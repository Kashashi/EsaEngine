#include "textManager.h"

namespace Kashashi{
textManager::textManager(std::shared_ptr<EsaLogger> logger): m_logger(logger){
	if (FT_Init_FreeType(&m_library)) {
        (*m_logger).writeLog("Could not init FreeType Library" ,[](){return "TextManager";});
    }

    if (FT_New_Face(m_library, "msjh.ttc", 0, &m_face)) {
        (*m_logger).writeLog("Failed to load font" ,[](){return "TextManager";});
    }

    FT_Set_Pixel_Sizes(m_face, 0, 48);
	(*m_logger).writeLog("Manager Load Complete", [](){return "TextManager";});
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

textManager::~textManager() = default;

std::vector<Character> textManager::getText(std::u16string text){
	std::vector<Character> targetString;
	for (char16_t ch : text){
		auto it = m_Characters.find(static_cast<unsigned int>(ch));
		if (it != m_Characters.end()) {
			targetString.push_back(it->second);
		}else if(loadGlyph(static_cast<unsigned int>(ch))){
			it = m_Characters.find(static_cast<unsigned int>(ch));
			if (it != m_Characters.end()){
				targetString.push_back(it->second);
			}
		}
		else{
			it = m_Characters.find(0x3f);
			if (it != m_Characters.end()){
				targetString.push_back(it->second);
			}
			(*m_logger).writeLog("找不到:", [ch]() -> std::string {std::string respond;
				respond += std::to_string(ch);
				respond += " 的字體";
				respond += ": 字體管理器";
				return respond;});
		}
	}
	return targetString;
}

bool textManager::loadGlyph(unsigned int characterCode){
	if(FT_Load_Char(m_face, characterCode, FT_LOAD_RENDER)){
		(*m_logger).writeLog("Failed to load Glyph" ,[](){return "TextManager";});
		return false;
	}
	GLuint texture;
	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RED,
		m_face->glyph->bitmap.width,
		m_face->glyph->bitmap.rows,
		0,
		GL_RED,
		GL_UNSIGNED_BYTE,
		m_face->glyph->bitmap.buffer
	);
	// 設置紋理環繞模式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	// 設置紋理過濾器
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	Character character = {
		texture,
		glm::ivec2(m_face->glyph->bitmap.width,m_face->glyph->bitmap.rows),
		glm::ivec2(m_face->glyph->bitmap_left,m_face->glyph->bitmap_top),
		static_cast<GLuint>(m_face->glyph->advance.x >> 6)
	};
	m_Characters.insert(std::pair<unsigned int, Character>(characterCode, character));
	return true;
}

void textManager::FT_Library_Deleter::operator()(FT_Library lib) const{
	FT_Done_FreeType(lib);
}

void textManager::FT_Face_Deleter::operator()(FT_Face face) const{
	FT_Done_Face(face);
}
}
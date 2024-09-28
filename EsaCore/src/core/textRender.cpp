#include "textRender.h"

namespace Kashashi{

textRender::textRender(std::shared_ptr<textManager> textManagerPTR,
						std::shared_ptr<EsaLogger> LoggerPTR): 
						TEXTManager(textManagerPTR), 
						m_Logger(LoggerPTR){
							shader = std::make_unique<著色器>("resource\\shaderFile\\textShader.vs","resource\\shaderFile\\textShader.fs",m_Logger);
							InitRenderData();
						}
textRender::~textRender(){}
void textRender::textDrow(std::u16string text,
						GLfloat x,
						GLfloat y,
						GLfloat scale,
						glm::vec3 color){
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	(*shader).使用();
	glUniform1i(glGetUniformLocation((*shader).程序唯一識別碼, "text"), 0);
	glUniform3f(glGetUniformLocation((*shader).程序唯一識別碼, "textColor"), color.x, color.y, color.z);
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(1920), 0.0f, static_cast<GLfloat>(1080));
	glUniformMatrix4fv(glGetUniformLocation((*shader).程序唯一識別碼, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	textData = (*TEXTManager).getText(text);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);
	for (auto c = textData.begin(); c != textData.end(); c++) {
		Character ch = *c;
		
		float xpos = x + ch.Bearing.x * scale;
		float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;

        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }
        };

        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        x += ch.Advance * scale;
		}
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		(*shader).解除使用();
}
void textRender::InitRenderData() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
}
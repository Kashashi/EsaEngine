#ifndef __TEXTMANAGER_H__
#define __TEXTMANAGER_H__

#include <string>
#include <map>
#include <memory>
#include "gladIncludeGuard.h"
// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H

#include "textStruct.h"
#include "EsaLogger.h"

namespace Kashashi{
class textManager{
public:
	textManager(std::shared_ptr<EsaLogger> logger);
	~textManager();
	std::vector<Character> getText(std::u16string text);
private:
	std::shared_ptr<EsaLogger> m_logger;
	bool loadGlyph(unsigned int characterCode);
	std::map<unsigned int, Character> m_Characters;
	FT_Library m_library;
	FT_Face m_face;
	struct FT_Library_Deleter {
	public:
		void operator()(FT_Library lib) const;
	};
	struct FT_Face_Deleter {
	public:
		void operator()(FT_Face face) const;
	};
	std::unique_ptr<std::remove_pointer_t<FT_Library>, FT_Library_Deleter> m_library_ptr{nullptr, FT_Library_Deleter()};
	std::unique_ptr<std::remove_pointer_t<FT_Face>, FT_Face_Deleter> m_face_ptr{nullptr, FT_Face_Deleter()};
};
}

#endif//__TEXTMANAGER_H__
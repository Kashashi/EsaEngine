#ifndef __TEXTRENDER_H_
#define __TEXTRENDER_H_

#include <iostream>
#include <map>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H
// GL includes
#include "shader.h"

namespace Kashashi{
	struct Character {
		GLuint TextureID;   // ID handle of the glyph texture
		glm::ivec2 Size;    // Size of glyph
		glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
		GLuint Advance;    // Horizontal offset to advance to next glyph
	};
	class textRender{
	public:
		textRender();
		~textRender();
		void textDrow(著色器 &shader,
			std::u16string text,
			GLfloat x,
			GLfloat y,
			GLfloat scale,
			glm::vec3 color);
	private:
		FT_Face face;
		std::map<char16_t, Character> Characters;
	};
	
}

#endif//__TEXTRENDER_H_
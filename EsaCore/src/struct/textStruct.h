#ifndef __TEXTSTRUCT_H__
#define __TEXTSTRUCT_H__

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
namespace Kashashi{
	struct Character{
		GLuint TextureID;   // 字型紋理的ID
		glm::ivec2 Size;    // 字型的大小
		glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
		GLuint Advance;    // Horizontal offset to advance to next glyph
	};
}

#endif//__TEXTSTRUCT_H__
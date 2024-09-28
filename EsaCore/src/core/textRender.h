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

// GL includes
#include "shader.h"
#include "EsaLogger.h"
#include "textStruct.h"
#include "textManager.h"

namespace Kashashi{
class textRender{
public:
	textRender(std::shared_ptr<textManager> textManagerPTR, std::shared_ptr<EsaLogger> LoggerPTR);
	~textRender();
	void textDrow(std::u16string text,
				GLfloat x,
				GLfloat y,
				GLfloat scale,
				glm::vec3 color);
private:
	std::shared_ptr<textManager> TEXTManager;
	std::shared_ptr<EsaLogger> m_Logger;
	std::unique_ptr<著色器> shader;
	std::vector<Character> textData;
	GLuint VAO;
	GLuint VBO;
	void InitRenderData();
};
}

#endif//__TEXTRENDER_H_
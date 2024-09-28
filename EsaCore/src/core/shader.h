#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

#include <glad/glad.h>

#include "EsaLogger.h"

namespace Kashashi{
class 著色器{
public:
    著色器(const GLchar* 頂點著色器路徑, const GLchar* 片段著色器路徑, std::shared_ptr<EsaLogger> loggerPtr);
    void 使用();
	void 解除使用();
	GLuint 程序唯一識別碼;
private:
	std::shared_ptr<EsaLogger> m_logger;
};
}


#endif
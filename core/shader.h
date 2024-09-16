#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

class 著色器
{
public:
    GLuint 程序唯一識別碼; //UUID
    著色器(const GLchar* 頂點著色器路徑, const GLchar* 片段著色器路徑);
    void 使用();
};

#endif
#include <shader.h>
著色器::著色器(const GLchar* 頂點著色器路徑, const GLchar* 片段著色器路徑){
    // 1. 從文件開啟頂點/片段著色器
    std::string 頂點著色器緩衝區;
    std::string 片段著色器緩衝區;
    std::ifstream 頂點著色器檔案;
    std::ifstream 片段著色器檔案;
    // 保證ifstream物件可以拋出異常：
    頂點著色器檔案.exceptions(std::ifstream::badbit);
    片段著色器檔案.exceptions(std::ifstream::badbit);
    try{
        // 打开文件
        頂點著色器檔案.open(頂點著色器路徑);
        片段著色器檔案.open(片段著色器路徑);
        std::stringstream 頂點著色器檔案流, 片段著色器檔案流;
        // 读取文件的缓冲内容到流中
        頂點著色器檔案流 << 頂點著色器檔案.rdbuf();
        片段著色器檔案流 << 片段著色器檔案.rdbuf();       
        // 关闭文件
        頂點著色器檔案.close();
        片段著色器檔案.close();
        // 转换流至GLchar数组
        頂點著色器緩衝區 = 頂點著色器檔案流.str();
        片段著色器緩衝區 = 片段著色器檔案流.str();     
    }
    catch(std::ifstream::failure e){
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const GLchar* 頂點著色器代碼 = 頂點著色器緩衝區.c_str();
    const GLchar* 片段著色器代碼 = 片段著色器緩衝區.c_str();
	// 2. 編譯著色器
	GLuint 頂點著色器, 片段著色器;
	GLint success;
	GLchar infoLog[512];

	// 頂點著色器
	頂點著色器 = glCreateShader(GL_VERTEX_SHADER );
	glShaderSource(頂點著色器, 1, &頂點著色器代碼, NULL);
	glCompileShader(頂點著色器);
	// 輸出錯誤（如果有的话）
	glGetShaderiv(頂點著色器, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(頂點著色器, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::頂點著色器::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	// 片段著色器
	片段著色器 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(片段著色器, 1, &片段著色器代碼, NULL);
	glCompileShader(片段著色器);
	// 輸出錯誤（如果有的话）
	glGetShaderiv(片段著色器, GL_COMPILE_STATUS, &success);
	glGetShaderiv(片段著色器, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(片段著色器, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::片段著色器::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

	// 著色器ID
	this->程序唯一識別碼 = glCreateProgram();
	glAttachShader(this->程序唯一識別碼, 頂點著色器);
	glAttachShader(this->程序唯一識別碼, 片段著色器);
	glLinkProgram(this->程序唯一識別碼);
	// 輸出錯誤（如果有的話）
	glGetProgramiv(this->程序唯一識別碼, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(this->程序唯一識別碼, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

// 連結完成，刪除著色器
glDeleteShader(頂點著色器);
glDeleteShader(片段著色器);
}
void 著色器::使用()
{
    glUseProgram(this->程序唯一識別碼);
}
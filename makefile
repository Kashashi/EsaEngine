

includePath = -I.\vender\glfw\include
includePath += -I.\vender\glad\include
includePath += -I.\vender\glm
includePath += -I.\vender\freetype\include
linkPath = -L.\vender\freetype\objs
linkPath += -L.\vender\glfw\lib-mingw-w64

all:
	g++ -o Esa $(includePath) $(linkPath) main.cpp vender/glad/src/glad.c core/EsaCore.cpp core/logger.cpp core/stringConverter.cpp core/windowManager.cpp -lglfw3 -limm32 -lgdi32 -l:freetype.a
# 包含路徑
DLL_INCLUDE_PATH = -IEsaCore/vender/glfw/include \
                   -IEsaCore/vender/glad/include \
                   -IEsaCore/vender/glm \
                   -IEsaCore/vender/freetype/include \
                   -IEsaCore/src

# 連結路徑
DLL_LINK_PATH = -LEsaCore/vender/freetype/objs \
                -LEsaCore/vender/glfw/lib-mingw-w64

# 原始碼
DLL_SRC_FILES = EsaCore/vender/glad/src/glad.c \
                EsaCore/src/core/Esacore.cpp \
                EsaCore/src/core/EsaLogger.cpp \
                EsaCore/src/core/EsaWindowManager.cpp \
                EsaCore/src/core/shader.cpp \
                EsaCore/src/core/textRender.cpp \
                EsaCore/src/core/textManager.cpp \
                EsaCore/src/core/stringConverter.cpp

# 連結庫
DLL_LINKING_LIB_PATH = -lglfw3 \
                       -limm32 \
			     	   -lgdi32 \
			    	   -l:freetype.a

Esa.dll:
	g++ -m64 -shared -o Esa.dll $(DLL_INCLUDE_PATH) $(DLL_LINK_PATH) $(DLL_SRC_FILES) $(DLL_LINKING_LIB_PATH)

EXE_INCLUDE_PATH = -IEsaCore/src \
                   -IEsaCore/src/core \
				   -IEsaCore/vender/glad/include \
				   -IEsaCore/vender/glfw/include \
				   -IEsaCore/vender/glm \
				   -IEsaCore/vender/freetype/include

EXE_SRC_FILES = Girigara/Girigara.cpp
Girigara.exe:
	g++ -mwindows -o Girigara $(EXE_INCLUDE_PATH) $(EXE_SRC_FILES) Esa.dll
	
Esapch.h.gch:
	g++ -o EsaCore/src/Esapch.h.gch EsaCore/src/Esapch.h
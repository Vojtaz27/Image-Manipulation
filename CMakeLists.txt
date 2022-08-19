cmake_minimum_required(VERSION 3.23)
project(Image_Manipulation)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_HEADERS
        Image.h
	stb_image.h
	stb_image_write.h
        )

set(PROJECT_SOURCES
        main.cpp
         Image.cpp )

add_executable(Image_Manipulation ${PROJECT_SOURCES} ${PROJECT_HEADERS})

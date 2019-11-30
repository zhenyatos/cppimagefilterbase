# CMakeList.txt: проект CMake для Lab1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 2.8)

project(student_toolkit)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (${PROJECT_NAME} "main.cpp"
"stb_image.h" "stb_image_write.h"
"png_toolkit.h" "png_toolkit.cpp"
"AbstractFilter.h" "AbstractFilter.cpp"
"PointFilter.h" "PointFilter.cpp"
"LocalityFilter.h" "LocalityFilter.cpp"
"TresholdFilter.h" "TresholdFilter.cpp"
"RedFilter.h" "RedFilter.cpp"
"BlWhFilter.h" "BlWhFilter.cpp"
"ConvFilter.h" "ConvFilter.cpp"
"BlurFilter.h" "BlurFilter.cpp"
"EdgeFilter.h" "EdgeFilter.cpp"
"myFilters.h"
"builder.h" "builder.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

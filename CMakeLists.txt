cmake_minimum_required(VERSION 3.10)

# Название вашего проекта (можете подставить своё)
project(MyProject)

# Опционально укажите C++ стандарт для всего проекта
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем подпапку с лабораторной
add_subdirectory(opencv_1)
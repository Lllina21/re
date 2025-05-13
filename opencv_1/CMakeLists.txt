cmake_minimum_required(VERSION 3.10)

# Название подпроекта (необязательно, но удобно для генерации IDE-проектов)
project(opencv_1)

# Найти OpenCV
find_package(OpenCV REQUIRED)

# Наш исходник
set(SOURCES lab1.cpp)

# Собираем исполняемый lab1
add_executable(lab1 ${SOURCES})

# Линкуем OpenCV
target_link_libraries(lab1 PRIVATE ${OpenCV_LIBS})

# (Необязательно) Установочные правила
install(TARGETS lab1
        RUNTIME DESTINATION bin)
cmake_minimum_required(VERSION 3.15)
project(verdad_o_reto CXX)

# exigir C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# para autocompletado de clangd en vscode
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# busca raylib
find_package(raylib REQUIRED)

include_directories(include)

# detecta todos los archivos .cpp en src
file(GLOB_RECURSE FUENTES "src/*.cpp")

# crea el ejecutable final
add_executable(${PROJECT_NAME} ${FUENTES}
    include/Pantalla.h
    src/Pantalla.cpp)

# enlaza la libreria de raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

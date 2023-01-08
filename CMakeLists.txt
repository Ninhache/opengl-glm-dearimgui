cmake_minimum_required(VERSION 3.23)
project(CppEngine)

set(CMAKE_CXX_STANDARD 20)

#add_subdirectory(find_package(LibXml2 REQUIRED))

add_subdirectory(lib)

add_executable(CppEngine
        # GLAD
        lib/glad/glad.c
        src/main.cpp
)

include_directories(lib/glm)

target_include_directories(CppEngine PRIVATE src lib)
target_link_libraries(CppEngine PRIVATE glfw ImGui)
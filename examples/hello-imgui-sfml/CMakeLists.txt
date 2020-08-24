cmake_minimum_required(VERSION 3.16)
project(hello-imgui-sfml)

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SRC_FILES src/*.cpp)

add_executable(hello-imgui-sfml
        ${SRC_FILES})

target_include_directories(hello-imgui-sfml PRIVATE src)
target_include_directories(hello-imgui-sfml PRIVATE ${CONAN_INCLUDE_DIRS})

target_link_libraries(hello-imgui-sfml ${CONAN_LIBS})

if(MSVC)
    target_compile_options(hello-imgui-sfml PRIVATE /W4 /WX $<$<CONFIG:RELEASE>:/O2 /MD>)
else()
    target_compile_options(hello-imgui-sfml PRIVATE -Wall -Wextra -Werror -pedantic $<$<CONFIG:RELEASE>:-O3>)
endif()
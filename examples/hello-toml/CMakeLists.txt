cmake_minimum_required(VERSION 3.16)
project(hello-toml)

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)
include_directories(${CONAN_INCLUDE_DIRS})

file(GLOB SRC_FILES src/*.cpp)
file(GLOB TOML_FILES src/*.toml)

add_executable(hello-toml
        ${SRC_FILES})

add_custom_command(TARGET hello-toml
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${TOML_FILES} ${CMAKE_BINARY_DIR}/bin
        )

conan_target_link_libraries(hello-toml)


if(MSVC)
    target_compile_options(hello-toml PRIVATE /W4 /WX $<$<CONFIG:RELEASE>:/O2>)
else()
    target_compile_options(hello-toml PRIVATE -Wall -Wextra -Werror -pedantic $<$<CONFIG:RELEASE>:-O3>)
endif()
cmake_minimum_required(VERSION 3.16)
project(hello-json)

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)
include_directories(${CONAN_INCLUDE_DIRS})

file(GLOB SRC_FILES src/*.cpp)
file(GLOB JSON_FILES src/*.json)

add_executable(hello-json
        ${SRC_FILES})

add_custom_command(TARGET hello-json
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${JSON_FILES} ${CMAKE_BINARY_DIR}/bin
        )

conan_target_link_libraries(hello-json)

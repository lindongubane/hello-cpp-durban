cmake_minimum_required(VERSION 3.16)
project(hello_json)

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)
include_directories(packages/include)

file(GLOB SRC_FILES src/*.cpp)
file(GLOB JSON_FILES src/*.json)

add_executable(hello_json
        ${SRC_FILES})

add_custom_command(TARGET hello_json
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${JSON_FILES} ${CMAKE_BINARY_DIR}/bin
        )

target_link_libraries(hello_json ${CONAN_LIBS})

cmake_minimum_required(VERSION 3.17)
project(hello-http-server)

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SRC_FILES src/*.cpp)

add_executable(hello-http-server
        ${SRC_FILES})

target_include_directories(hello-http-server PRIVATE src)
target_include_directories(hello-http-server PRIVATE ${CONAN_INCLUDE_DIRS})

conan_target_link_libraries(hello-http-server)

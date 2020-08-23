cmake_minimum_required(VERSION 3.16)
project(hello-wx-widgets)

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SRC_FILES src/*.cpp)

add_executable(hello-wx-widgets
        ${SRC_FILES})

target_include_directories(hello-wx-widgets PRIVATE src)
target_include_directories(hello-wx-widgets PRIVATE ${CONAN_INCLUDE_DIRS})

target_link_libraries(hello-wx-widgets ${CONAN_LIBS})

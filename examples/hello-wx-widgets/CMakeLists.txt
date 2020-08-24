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

conan_target_link_libraries(hello-wx-widgets)


if(MSVC)
    target_compile_options(hello-wx-widgets PRIVATE /WX $<$<CONFIG:RELEASE>:/O2>)
else()
    target_compile_options(hello-wx-widgets PRIVATE -Werror $<$<CONFIG:RELEASE>:-O3>)
endif()
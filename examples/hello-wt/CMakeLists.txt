cmake_minimum_required(VERSION 3.16)
project(hello-wt)

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SRC_FILES src/*.cpp)
file(GLOB CONFIG_FILES src/*.xml)

add_executable(hello-wt
        ${SRC_FILES})

add_custom_command(TARGET hello-wt
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CONFIG_FILES} ${CMAKE_BINARY_DIR}/bin
        )

add_custom_command(TARGET hello-wt
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/bin/resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Wt/resources ${CMAKE_BINARY_DIR}/bin/resources
        )

target_include_directories(hello-wt PRIVATE src)
target_include_directories(hello-wt PRIVATE ${CONAN_INCLUDE_DIRS})

target_link_libraries(hello-wt ${CONAN_LIBS})

if(MSVC)
    target_compile_options(hello-wt PRIVATE /WX $<$<CONFIG:RELEASE>:/O2>)
else()
    target_compile_options(hello-wt PRIVATE -Werror $<$<CONFIG:RELEASE>:-O3>)
endif()

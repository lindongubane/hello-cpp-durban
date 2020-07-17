# Hello JSON

This is an example for how to do some basic parsing with JSON in C++.

## Setup Instructions
The example requires the Conan package manager and CMake.

If you have Python installed on your system you can do something the effect of:

``pip install conan``

Once that is done, you can run the following command inside of the project directory.

``conan install .``

To run the project:

* The easy way:
    * Use CLion from JetBrains.
* Almost easy:
    * Use Visual Studio Code and its CMake extension to create a Visual Studio project in the build directory.
* Other ways:
    * TODO finish describing how to build the project using CMake.
    * Maybe NetBeans?

## Example Overview
The **conanfile.py** defines all of the dependencies and copies the source files to the _packages_ directory.

Because Nlohmann JSON is a header only library, there will just be some headers copied into the _packages/include_ directory.

The **CMakeLists.txt** is the CMake project file for the example. It defines the include directories and build steps for the project.

The _src/main.cpp_ is a program which will read _hello.json_ and output the contents of the file, in various ways, to the standard output stream, which should be your console/terminal.


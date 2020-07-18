# Hello JSON

This is an example for how to do some basic parsing with JSON in C++.

## Setup Instructions
The example requires the Conan package manager and CMake.

If you have Python installed on your system you can do something the effect of:

``pip install conan``

Once that is done, you can run the following command inside of the project directory.

``conan install .``

To run the project:

(Currently only tested on Windows, but should be similar on Linux)
* The easy way:
    * Use CLion from JetBrains.
        * Make sure that it detects Visual Studio or another supported compiler on your system.
    * Click the Run button to run the project.
* The command line way (on Windows with Visual Studio 2019 installed with all related C/C++ and CMake options)
    * Run the **Developer Command Prompt for VS 2019** (usually found in the Start Menu).
        * OR open a command prompt in your folder and run ``"%programfiles(x86)%\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"``
    * Then ``mkdir build``, which is our target directory for the VS solution and build outputs.
    * Then ``cmake . -B build`` which creates a Visual Studio solution by default.
    * Then ``msbuild build\hello_json.sln`` to compile the project.
        * OR just open build\hello_json.sln in Visual Studio.
    * Finally use ``build\bin\hello_json.exe`` to run the program.
        * You can use ``cat someone.json`` to see the example file it generated, besides the command line output.

## Example Overview
The **conanfile.py** defines all of the dependencies and copies the source files to the _packages_ directory.

Because Nlohmann JSON is a header only library, there will just be some headers copied into the _packages/include_ directory.

The **CMakeLists.txt** is the CMake project file for the example. It defines the include directories and build steps for the project.

The _src/main.cpp_ is a program which will read _hello.json_ and output the contents of the file, in various ways, to the standard output stream, which should be your console/terminal.


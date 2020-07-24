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
* The command line way:
    * ``conan build .``
    * Finally use ``build\bin\hello_json.exe`` to run the program.
        * You can use ``cat someone.json`` to see the example file it generated, besides the command line output.
    * If you are on Windows and have Visual Studio, it is best to run the **Developer Command Prompt for VS 2019** (usually found in the Start Menu).
        * There is also **vswhere** which can be installed via Choco. Then you can make a bat/ps1 file to open the VS command line: https://github.com/microsoft/vswhere/wiki/Start-Developer-Command-Prompt

## Example Overview
The **conanfile.py** defines all of the dependencies and copies the source files to the _packages_ directory.

Because Nlohmann JSON is a header only library, there will just be some headers copied into the _packages/include_ directory.

The **CMakeLists.txt** is the CMake project file for the example. It defines the include directories and build steps for the project.

The _src/main.cpp_ is a program which will read _hello.json_ and output the contents of the file, in various ways, to the standard output stream, which should be your console/terminal.


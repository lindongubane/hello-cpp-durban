# Hello imGUI + SFML

This is an example of a imGUI + SFML GUI application.

## Setup Instructions
The example requires the Conan package manager.

Python is required by Conan, and if it is installed on your system you can do something the effect of:

``pip install conan``

As a setup command, run ```conan install cmake/3.17.3@/ -g virtualenv```

Then run ```activate``` or ```./activate```

Once that is done, you can run the following command inside of the project directory.

``conan install .``

To build the project from the command line, use:

``conan build .``

Finally use ``build\bin\hello-imgui-sfml`` to run the program.

You can also use your favourite IDE, like Visual Studio or CLion, after doing the ``conan install .`` step.


## Example Overview
The **conanfile.py** defines all of the dependencies and copies the source files to the _packages_ directory.

The **CMakeLists.txt** is the CMake project file for the example. It defines the include directories and build steps for the project.

The _src/main.cpp_ is a program which has all of the code for the UI.


# Hello Wt

This is an example of a Wt web GUI application.

## Setup Instructions
The example requires the Conan package manager.

Python is required by Conan, and if it is installed on your system you can do something the effect of:

``pip install conan``

Once that is done, you can run the following command inside of the project directory.

```conan install .``` or ```conan install . --build=missing```

To build the project from the command line, use:

``conan build .``

Finally do ``cd build/bin`` then ``hello-wt --http-address=0.0.0.0 --http-port=8080 --deploy-path=/hello --docroot=. --config ./wt_config.xml`` to run the program.

You can also use your favourite IDE, like Visual Studio or CLion, after doing the ``conan install .`` step.


## Example Overview
The **conanfile.py** defines all of the dependencies and copies the source files to the _packages_ directory.

The **CMakeLists.txt** is the CMake project file for the example. It defines the include directories and build steps for the project.

The _src/main.cpp_ is a program which has all of the code for the UI.


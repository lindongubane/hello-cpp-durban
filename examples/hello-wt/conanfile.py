from conans import ConanFile, CMake, tools
import os.path


class HelloTomlConanFile(ConanFile):
    build_requires = "cmake/3.17.3"
    requires = "wt/4.4.0"
    settings = "arch", "build_type", "compiler"
    generators = "cmake"
    build_folder = "build"
        
    def build(self):
        self.build_folder = "build"
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("Wt/resources/*", src="@bindirs", dst="")
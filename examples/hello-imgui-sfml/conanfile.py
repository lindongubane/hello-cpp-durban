from conans import ConanFile, CMake, tools
import os.path


class HelloTomlConanFile(ConanFile):
    build_requires = "cmake/3.17.3"
    requires = "imgui-sfml/2.1@bincrafters/stable"
    generators = "cmake"
    build_folder = "build"
        
    def build(self):
        self.build_folder = "build"
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

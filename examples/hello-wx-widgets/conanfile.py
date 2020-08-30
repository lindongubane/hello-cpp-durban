from conans import ConanFile, CMake, tools


class HelloWxWidgetsConanFile(ConanFile):
    build_requires = "cmake/3.17.3"
    requires = "wxwidgets/3.1.3@bincrafters/stable"
    settings = "arch", "build_type", "compiler"
    generators = "cmake", "virtualenv"
    build_folder = "build"
        
    def build(self):
        self.build_folder = "build"
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


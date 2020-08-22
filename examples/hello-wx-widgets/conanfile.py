from conans import ConanFile, CMake, tools


class HelloTomlConanFile(ConanFile):
    build_requires = "cmake/3.17.3"
    requires = "wxwidgets/3.1.3@bincrafters/stable"
    generators = "cmake", "virtualenv"
    build_folder = "build"
        
    def build(self):
        self.build_folder = "build"
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


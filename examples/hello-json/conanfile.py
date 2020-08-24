from conans import ConanFile, CMake, tools


class HelloJsonConanFile(ConanFile):
    build_requires = "cmake/3.17.3"
    requires = "nlohmann_json/3.8.0"
    settings = "arch", "build_type", "compiler"
    generators = "cmake"
    build_folder = "build"
        
    def build(self):
        self.build_folder = "build"
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


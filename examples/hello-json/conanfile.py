from conans import ConanFile, CMake, tools


class HelloJsonConanFile(ConanFile):
    requires = "nlohmann_json/3.8.0"
    generators = "cmake"
    build_folder = "build"
        
    def build(self):
        self.build_folder = "build"
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


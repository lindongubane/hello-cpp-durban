from conans import ConanFile, tools


class HelloJsonConanFile(ConanFile):
    requires = "nlohmann_json/3.8.0"
    generators = "cmake"

    def imports(self):
        self.copy("*", src="@includedirs", dst="packages/include")
        self.copy("*", src="@libdirs", dst="packages/lib")
        self.copy("*", src="@bindirs", dst="packages/bin")
        self.copy("*", src="@resdirs", dst="packages/res")

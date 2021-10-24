from conans import ConanFile
from conans import tools

class LibftConan(ConanFile):
    name = "libft"
    version = "2.0"
    license = "MIT"
    author = "agagniere sid.xxdzs@gmail.com"
    url = "https://github.com/agagniere/Libft"
    description = "Standard datastructures"
    topics = ("libc")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    generators = "make"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def source(self):
        self.run("git clone " + self.url + " .")

    def build(self):
        self.run("make")

    def package(self):
        self.copy("*.h", dst="include", src="include")
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def test(self):
        self.run("make test")

    def package_info(self):
        self.cpp_info.libs = ["libft"]

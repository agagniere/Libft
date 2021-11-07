from conans import ConanFile
from conans import AutoToolsBuildEnvironment

class LibftConan(ConanFile):
    name = "libft"
    version = "2.0"
    license = "MIT"
    author = "agagniere sid.xxdzs@gmail.com"
    url = "https://github.com/agagniere/Libft"
    description = "Standard datastructures"
    topics = ()
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "optimisation": ['0', '1', '2', '3', 's', 'fast'],
        "debug": [True, False]}
    default_options = {
        "shared": True,
        "fPIC": False,
        "optimisation": '2',
        "debug": True}
    generators = "make"

    def source(self):
        self.run(f"git clone {self.url} .")

    def build(self):
        autotools = AutoToolsBuildEnvironment(self)
        autotools.flags = [f"-O{self.options.optimisation}"]
        if self.options.debug:
            autotools.flags += ["-g"]
        autotools.make(args=["shared" if self.options.shared else "static"])

    def package(self):
        self.copy("*.h", dst="include", src="include")
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["ft"]

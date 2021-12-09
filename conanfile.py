from conans import ConanFile
from conans import AutoToolsBuildEnvironment

class LibftConan(ConanFile):
    name = "libft"
    version = "2.2"
    license = "MIT"
    author = "agagniere sid.xxdzs@gmail.com"
    url = "https://github.com/agagniere/Libft"
    description = "Standard datastructures"
    topics = ("conan", "libc", "datastructures", "macros")
    settings = ("os", "compiler", "arch")
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "optimisation": ['0', '1', '2', '3', 's', 'fast'],
        "debug": [True, False]
    }
    default_options = {
        "shared": True,
        "fPIC": False,
        "optimisation": '2',
        "debug": True
    }
    generators = "make"
    build_policy = "missing"

    def source(self):
        self.run(f"git clone {self.url} .")

    def configure(self):
        del self.settings.compiler.libcxx
        del self.settings.compiler.cppstd

    def build(self):
        autotools = AutoToolsBuildEnvironment(self)
        autotools.flags = [f"-O{self.options.optimisation}"]
        if self.settings.compiler == 'gcc':
            autotools.flags += ['-nolibc']
        if self.options.debug:
            autotools.flags += ["-g"]
        autotools.make(args=["shared" if self.options.shared else "static", "-j"])

    def package(self):
        self.copy("*.h", dst="include", src="include")
        self.copy("libft.so", dst="lib")
        self.copy("libft.a", dst="lib")

    def package_info(self):
        self.cpp_info.libs = ["ft"]

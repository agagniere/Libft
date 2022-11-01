from conan import ConanFile
from conan.tools.gnu import Autotools, AutotoolsToolchain

class LibftConan(ConanFile):
    name = "libft"
    version = "2.6"
    license = "MIT"
    author = "agagniere sid.xxdzs@gmail.com"
    url = "https://github.com/agagniere/Libft"
    description = "Standard datastructures"
    topics = ("datastructures", "macros")
    settings = ("os", "compiler", "arch")
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "optimisation": ['0', '1', '2', '3', 's', 'fast'],
        "debug": [True, False]
    }
    default_options = {
        "shared": False,
        "fPIC": False,
        "optimisation": '2',
        "debug": True
    }
    exports_sources = "src*", "include*", 'LICENSE', 'Makefile', 'README.md'

    def configure(self):
        del self.settings.compiler.libcxx
        del self.settings.compiler.cppstd
        if self.options.shared:
            del self.options.shared

    def generate(self):
        toolchain = AutotoolsToolchain(self)
        toolchain.extra_cflags.append(f"-O{self.options.optimisation}")
        if self.settings.compiler == "gcc":
            toolchain.extra_cflags.append("-nolibc")
        if self.options.debug:
            toolchain.extra_cflags.append("-g")
        toolchain.generate()

    def build(self):
        autotools = Autotools(self)
        autotools.make("shared" if self.options.shared else "static")
        autotools.make("clean")

    def package(self):
        self.copy("*.h", dst="include", src="include")
        self.copy("libft.*", dst="lib")
        self.copy("LICENSE")
        self.copy("README.md", dst="doc")

    def package_info(self):
        self.cpp_info.libs = ["ft"]

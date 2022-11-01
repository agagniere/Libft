from conan import ConanFile
from conan.tools.gnu import Autotools, AutotoolsToolchain, AutotoolsDeps

class LibUnitConan(ConanFile):
    name = "libunit"
    version = "1.2"
    license = "MIT"
    author = "agagniere sid.xxdzs@gmail.com"
    url = "https://github.com/agagniere/Libft"
    description = "Simplistic unit testing framework"
    topics = ("testing", "unit-testing")
    settings = ("os", "compiler", "arch")
    options = {
        "fPIC" : [True, False],
        "optimisation": ['0', '1', '2', '3', 's', 'fast'],
        "debug": [True, False]
    }
    default_options = {
        "fPIC": False,
        "optimisation": '2',
        "debug": True
    }
    requires = ["libft/2.6"]
    exports_sources = '*.c', '*.h', 'Makefile'

    def configure(self):
        del self.settings.compiler.libcxx
        del self.settings.compiler.cppstd

    def generate(self):
        toolchain = AutotoolsToolchain(self)
        toolchain.extra_cflags.append(f"-O{self.options.optimisation}")
        if self.options.debug:
            toolchain.extra_cflags.append("-g")
        if self.settings.compiler == "gcc":
            toolchain.extra_cflags.append("-nolibc")
        toolchain.generate()
        AutotoolsDeps(self).generate()

    def build(self):
        autotools = Autotools(self)
        autotools.make()

    def package(self):
        self.copy("*.h", dst="include")
        self.copy("libunit.a", dst="lib")

    def package_info(self):
        self.cpp_info.libs = ["unit"]

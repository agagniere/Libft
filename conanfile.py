from os import path
from conan import ConanFile
from conan.tools.gnu import Autotools, AutotoolsToolchain
from conan.tools.files import copy

class LibftConan(ConanFile):
    name = "libft"
    version = "2.10"
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
        self.settings.rm_safe('compiler.libcxx')
        self.settings.rm_safe('compiler.cppstd')
        if self.options.shared:
            self.options.rm_safe("fPIC")

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
        copy(self, '*.h', path.join(self.source_folder, 'include'), path.join(self.package_folder, 'include'))
        copy(self, 'libft.*', self.build_folder, path.join(self.package_folder, 'lib'))
        copy(self, 'LICENSE|README.md', self.source_folder, self.package_folder)

    def package_info(self):
        self.cpp_info.libs = ["ft"]

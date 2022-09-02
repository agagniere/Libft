from conans import ConanFile
from conans import AutoToolsBuildEnvironment

class LibUnitConan(ConanFile):
    name = "libunit"
    version = "1.1"
    license = "MIT"
    author = "agagniere sid.xxdzs@gmail.com"
    url = "https://github.com/agagniere/Libft"
    description = "Simplistic unit testing framework"
    topics = ("conan", "testing", "unit-testing")
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
    generators = "make"
    requires = ["libft/2.5"]
    build_policy = "missing"

    def source(self):
        self.run(f"git clone {self.url} tmpdir")
        self.run("mv tmpdir/test/framework/* .")
        self.run("rm -rf tmpdir")

    def configure(self):
        del self.settings.compiler.libcxx
        del self.settings.compiler.cppstd

    def build(self):
        autotools = AutoToolsBuildEnvironment(self)
        autotools.flags = [f"-O{self.options.optimisation}"]
        if self.settings.compiler == "gcc":
            autotools.flags += ["-nolibc"]
        if self.options.debug:
            autotools.flags += ["-g"]
        autotools.make()

    def package(self):
        self.copy("*.h", dst="include")
        self.copy("libunit.a", dst="lib")

    def package_info(self):
        self.cpp_info.libs = ["unit"]

from conans import ConanFile
from conans import AutoToolsBuildEnvironment

class LibUnitConan(ConanFile):
    name = "libunit"
    version = "1.0"
    license = "MIT"
    author = "agagniere sid.xxdzs@gmail.com"
    url = "https://github.com/agagniere/Libft"
    description = "Simplistic unit testing framework"
    topics = ()
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "fPIC" : [True, False],
        "optimisation": ['0', '1', '2', '3', 's', 'fast'],
        "debug": [True, False]}
    default_options = {
        "fPIC": False,
        "optimisation": '2',
        "debug": True}
    generators = "make"
    requires = ["libft/2.0"]


    def source(self):
        self.run(f"git clone {self.url} tmpdir")
        self.run("mv tmpdir/test/framework/* .")
        self.run("rm -rf tmpdir")

    def build(self):
        autotools = AutoToolsBuildEnvironment(self)
        autotools.flags = [f"-O{self.options.optimisation}", "-nolibc"]
        if self.options.debug:
            autotools.flags += ["-g"]
        autotools.make()

    def package(self):
        self.copy("*.h", dst="include")
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["unit"]

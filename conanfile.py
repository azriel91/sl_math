from conans import *
import subprocess

class SlMathConan(ConanFile):
    name = 'sl_math'
    version = '0.1.0'
    settings = ['os', 'compiler', 'build_type']
    generators = ['cmake']
    exports = subprocess.check_output(['git', 'ls-files']).split()

    build_dir = 'build'

    def requirements(self):
        """ Declare here your project requirements or configure any of them """
        self.requires('CppMicroServices/3.0.0@azriel91/testing')
        self.requires('sl_cmake/0.1.0@azriel91/testing')
        self.requires('googlemock/1.7.0@azriel91/stable-2')

    def build(self):
        self.run("cmake . -B{build_dir}".format(build_dir=self.build_dir))
        self.run("cmake --build {build_dir}".format(build_dir=self.build_dir))

    def package(self):
        self.copy('*.h', dst='include', src='.')

        # Built artifacts
        lib_dir = "{build_dir}/lib".format(build_dir=self.build_dir)
        self.copy('*.so', dst='lib', src=lib_dir)
        self.copy('*.a', dst='lib', src=lib_dir)
        self.copy('*.lib', dst='lib', src=lib_dir)

    def package_info(self):
        self.cpp_info.libs = ['sl_math']

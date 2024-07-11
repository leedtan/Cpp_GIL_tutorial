import os
import shutil

from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext as build_ext_orig


class build_ext(build_ext_orig):
    def run(self):
        super().run()
        # Move the built extension to the src directory
        for ext in self.extensions:
            filename = self.get_ext_filename(ext.name)
            src = os.path.join(self.build_lib, filename)
            dst = os.path.join('src', filename)
            shutil.move(src, dst)

module = Extension("hello", sources=["src/hello.cpp"])

setup(
    name="hello",
    version="1.0",
    description="A Hello World package with C++",
    ext_modules=[module],
    cmdclass={'build_ext': build_ext},
)

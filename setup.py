from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        # Name of module
        'bezier_math',
        # Name of file
        ['bezier_module.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++'
    ),
]

setup(
    name='bezier_math',
    ext_modules=ext_modules,
)
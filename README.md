This is a bezier curve generator implemented in C++ and python. It takes in control points from python and uses De Casteljau's algorithm in C++ to output control points for a bezier curve.

Required python modules
- setuptools
- pybind11
- matplotlib
- numpy

To use this, run ```python setup.py build_ext --inplace``` to build the c++ code (This will generate a .so or .pyd file which is the compiled c++ code). Then, edit the points in app.py and run it to see the matplotlib visualizer.

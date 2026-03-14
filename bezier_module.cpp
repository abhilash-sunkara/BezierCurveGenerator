#include <vector>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

struct Pose{
    double x;
    double y;
};

inline std::ostream& operator<<(std::ostream& os, const Pose& p){
    os << p.x << ", " << p.y;
    return os;
}

std::vector<Pose> control_points;

Pose get_interpolation(Pose p1, Pose p2, double t){
    return Pose{p1.x * (1-t) + p2.x * (t), p1.y * (1-t) + p2.y * (t)};
}

Pose calculate_waypoint(double t){
    std::vector<Pose> interpolated_points = control_points;
        for(int i = interpolated_points.size()-1; i > 0; i--){
            for(int j = 0; j < i; j++){
                interpolated_points[j] = get_interpolation(interpolated_points[j], interpolated_points[j+1], t);
            }
        }
    return interpolated_points[0];
}

pybind11::array_t<double> get_bezier_curve(pybind11::array_t<double> input_array){
    auto points = input_array.unchecked<2>();

    pybind11::ssize_t num_points = points.shape(0);

    for(int i = 0; i < num_points; i++){
        Pose np = {points(i, 0), points(i, 1)};
        control_points.push_back(np);
    }

    int o_points = 100;

    pybind11::array_t<double> result({o_points+1, 2});

    auto r = result.mutable_unchecked<2>();

    for(int i = 0; i <= o_points; i++) {
        
        double o = i / static_cast<double>(o_points); 
        
        Pose wp = calculate_waypoint(o);
        
        
        r(i, 0) = wp.x; 
        r(i, 1) = wp.y; 
    }

    
    return result;
}

//Entry point for python import
//creates the functions that can be called in python
PYBIND11_MODULE(bezier_math, m) {
    m.def("get_bezier_curve", &get_bezier_curve, "Prints out bezier path");
}
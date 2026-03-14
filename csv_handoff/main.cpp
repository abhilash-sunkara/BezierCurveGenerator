#include <vector>
#include <iostream>
#include <fstream>
#include "bezier.cpp"

int main(){
    std::vector<Pose> points = {{0, 0}, {-6, 2}, {-6, 48}, {-24, 56}};

    BezierPath bp = BezierPath(points);

    std::ofstream data;
    data.open("data.csv");
    for(double o = 0.00; o <= 1; o += 0.01){
        data << bp.calculate_waypoint(o) << "\n";
    }

    data.close();
}
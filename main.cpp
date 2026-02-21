#include <vector>
#include <iostream>
#include <fstream>
#include "bezier.cpp"

int main(){
    std::vector<Pose> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}, {4, 4}};

    BezierPath bp = BezierPath(points);

    std::ofstream data;
    data.open("data.csv");
    for(double o = 0.00; o <= 1; o += 0.01){
        data << bp.calculate_waypoint(o) << "\n";
    }

    data.close();
}
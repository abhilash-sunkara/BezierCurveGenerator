#include <vector>
#include <iostream>

struct Pose{
    double x;
    double y;
};

inline std::ostream& operator<<(std::ostream& os, const Pose& p){
    os << p.x << ", " << p.y;
    return os;
}

class BezierPath{
    std::vector<Pose> control_points;

    Pose get_interpolation(Pose p1, Pose p2, double t){
        return Pose{p1.x * (1-t) + p2.x * (t), p1.y * (1-t) + p2.y * (t)};
    }

    public:
        BezierPath(std::vector<Pose> c_p): control_points{c_p} {};

        Pose calculate_waypoint(double t){
            std::vector<Pose> interpolated_points = control_points;
            for(int i = interpolated_points.size()-1; i > 0; i--){
                for(int j = 0; j < i; j++){
                    interpolated_points[j] = get_interpolation(interpolated_points[j], interpolated_points[j+1], t);
                }
            }
            return interpolated_points[0];
        }
};
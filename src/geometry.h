#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <regex>
#include <string>
#include <utility>

struct QuadraticPattern {
    std::regex pattern;
    std::string name;// is it linear, quadratic...etc
};
class Geometry {
public:
    Geometry();
    ~Geometry();
    std::pair<double, double> QuadraticRoots(const std::string& query);
    void VertexQuadraticForm();

private:
    double a{};
    double b{};
    double c{};
    double inner_surd{};
    double outer_surd{};
};
#endif //GEOMETRY_H

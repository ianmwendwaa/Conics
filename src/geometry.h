#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <algorithm>
#include <regex>
#include <string>
#include <utility>
#pragma once

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
    void CompareAndSolveEquation();

private:
    double a{};
    double b{};
    double c{};
    double inner_surd{};
    double outer_surd{};
    double a_v{}, b_v{};
};
#endif //GEOMETRY_H

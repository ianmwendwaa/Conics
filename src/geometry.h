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
    void QuadraticRoots(const std::string& query);
    void VertexQuadraticForm();
    void CompareAndSolveEquation();
    double FindSurdExpression(double& d);

private:
    double a{};
    double b{};
    double c{};
    double inner_surd{};
    double outer_surd{};
    double a_v{}, b_v{};// variables for the vertex form (x+a)2 + b
};
#endif //GEOMETRY_H

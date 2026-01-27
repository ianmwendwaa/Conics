#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <algorithm>
#include <regex>
#include <string>
#include <utility>

#include "../../core/core.h"
#include <src/engine/queryengine.h>
#pragma once

enum QuadraticType {
    STD_FORM, FACTORED_FORM, VERTEX_FORM
};
struct QuadraticVariadic {
    std::regex pattern;
    QuadraticType type;
};

namespace Geometry {
    struct Data {
        double a, b, c;
        double inner_surd, outer_surd;
        double a_v, b_v;
        std::string geoQuery;

        Data() = default;
        ~Data() = default;

        // Data(double a1 = 0, double b1 = 0, double c1 = 0, double inn1 = 0, double out2 = 0,
        //     double av1 = 0, double bv1 = 0, std::string gq1 = ""):
        // a(a1), b(b1), c(c1), inner_surd(inn1), outer_surd(out2), a_v(av1), b_v(bv1), geoQuery(gq1){}
    };
    void QuadraticRoots(const std::string& query);
    void StandardFormEvaluator(const std::string& query, const std::regex& pattern);
    void FactoredFormEvaluator(const std::string& query, const std::regex& pattern);
    void VertexFormEvaluator(const std::string& query, const std::regex& pattern);
    void ParseQuery(const std::string& query, const std::regex& pattern, EquationForm format);

    inline std::string geoQuery;

    void VertexQuadraticForm();
    void CompareAndSolveEquation();
    double FindSurdExpression(const double& d);
};
#endif //GEOMETRY_H

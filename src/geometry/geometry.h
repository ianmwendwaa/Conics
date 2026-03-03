#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <regex>
#include <string>

#include "../../core/core.h"
#include "types/types.h"

enum QuadraticType {
    STD_FORM, FACTORED_FORM, VERTEX_FORM
};
struct QuadraticVariadic {
    std::regex pattern;
    QuadraticType type;
};

class Geometry {
public:
    Geometry();
    void QuadraticRoots(const std::string& query);
    void StandardFormEvaluator(const std::string& query, const std::regex& pattern);
    void FactoredFormEvaluator(const std::string& query, const std::regex& pattern);
    void VertexFormEvaluator();
    static void ParseQuery(const std::string& query, const std::regex& pattern, EquationForm format);
    void VertexQuadraticForm();
    static void CompareAndSolveEquation();
    ~Geometry();
private:
    std::string geoQuery;
    double a{}, b{}, c{};
    double inner_surd{}, outer_surd{};
    double a_v{}, b_v{};
};
#endif //GEOMETRY_H

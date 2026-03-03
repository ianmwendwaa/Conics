//
// Created by Owner on 1/26/2026.
//

#ifndef TYPES_H
#define TYPES_H
#include <regex>

enum QueryType {
    CIRCLE_ENGINE, PARABOLA_ENGINE, HYPERBOLA_ENGINE, ELLIPSE_ENGINE, GEOMETRY_ENGINE, UNKNOWN_QUERY_TYPE
};
enum EquationForm {
    STANDARD, GENERAL, VERTEX, FACTORED, POLAR, PARAMETRIC, UNKNOWN_EQUATION_FORMAT
};
enum QueryIntent {
    FIND_RADIUS, FIND_EQUATION, FIND_CENTRE, FIND_STD_FORM, FIND_GEN_FORM, FIND_VTX_FORM
};
struct QueryInfo {
    std::regex queryRgx;
    QueryType type;
    EquationForm eqFmt;

    QueryInfo(std::regex r, QueryType t, EquationForm e): queryRgx(std::move(r)), type(t), eqFmt(e){}
};
#endif //TYPES_H

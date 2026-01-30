#ifndef QUERYENGINE_H
#define QUERYENGINE_H
#include <memory>
#include <regex>

#include "src/circle/circle.h"
#include "src/parabola/parabola.h"
#include "src/hyperbola/hyperbola.h"

#include <string>

#include "../geometry/geometry.h"

struct QueryInfo {
    std::regex queryRgx;
    QueryType type;
    EquationForm eqFmt;

    QueryInfo(std::regex r, QueryType t, EquationForm e): queryRgx(std::move(r)), type(t), eqFmt(e){}
};

namespace  QueryEngine
{
    void AscertainQueryType(const std::string& query);
    static std::vector<>
    static std::vector<QueryInfo> queryDecTree = {
        //1. Construct 1: For quadratics:
    {std::regex(R"(([+-]?\d*)x2([+-]\d*)x([+-]\d*)=0)"), GEOMETRY_ENGINE, STANDARD},
    // Factored Form: matches y=2(x-3)(x+4) or y=(x+1)(x+1)
    // Note: Use [+-]?\d* for the constant inside the parentheses too
    {std::regex(R"(y=([+-]?\d*)\(x([+-]\d+)\)\(x([+-]\d+)\))"), GEOMETRY_ENGINE, FACTORED},
    // Vertex Form: matches y=2(x-3)2+4 or y=(x+1)2-5
    {std::regex(R"(y=([+-]?\d*)\(x([+-]\d+)\)2([+-]\d+))"), GEOMETRY_ENGINE, VERTEX},

    //2. Construct 2: For circles:
    {std::regex(R"(([+-]?\d*)x2([+-]\d+)y2([+-]\d*)x([+-]\d*)y([+-]\d*)=0)"), CIRCLE_ENGINE, STANDARD},
    {std::regex(R"(([+-]\d*)x2([+-]\d*)y2([+-]\d*)x([+-]\d*)y([+-]\d*)=0)"), CIRCLE_ENGINE, GENERAL}

    // Construct 3: Parabola
};;

};
#endif // QUERYENGINE_H

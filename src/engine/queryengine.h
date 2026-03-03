#ifndef QUERYENGINE_H
#define QUERYENGINE_H
#include "core/core.h"
#include "types/types.h"
#include <string>
#include <regex>

#include "src/geometry/geometry.h"
class Geometry;
namespace Circle{ void ParseQuery(std::string& query, const std::regex& pattern, EquationForm format);}

namespace  QueryEngine{
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
    {std::regex(R"(([+-]?\d*)x2([+-]\d*)y2([+-]\d*)x([+-]\d*)y([+-]\d*)=0)"), CIRCLE_ENGINE, GENERAL}

    // Construct 3: Parabola
    };;

    inline void AscertainQueryType(const std::string& query) {
        std::string cleanQuery = Core::NormalizeQuery(query);
        QueryType queryType = QueryType::UNKNOWN_QUERY_TYPE;

        for (const auto& patternEntry: queryDecTree) {
            if (std::smatch matches; std::regex_match(cleanQuery, matches, patternEntry.queryRgx)) {
                queryType = patternEntry.type;
                switch (queryType) {
                case QueryType::GEOMETRY_ENGINE:
                        std::cout << "GEOMETRY_ENGINE" << std::endl;
                        Geometry::ParseQuery(cleanQuery, patternEntry.queryRgx, patternEntry.eqFmt);
                        break;
                case QueryType::CIRCLE_ENGINE:
                        std::cout << "CIRCLE_ENGINE" << std::endl;
                        Circle::ParseQuery(cleanQuery, patternEntry.queryRgx, patternEntry.eqFmt);
                        break;
                default:
                    std::cerr << "Could not process query syntax. Consider revising your input.";
                    break;
                }
            }
        }
    }

};
#endif // QUERYENGINE_H

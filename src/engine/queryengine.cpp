#include "queryengine.h"

#include <vector>

#include "src/geometry/geometry.h"
#include "core/core.h"
#include "types/types.h"

void QueryEngine::AscertainQueryType(const std::string &query) {
    const std::string cleanQuery = Core::NormalizeQuery(query);
    QueryType queryType = QueryType::UNKNOWN_QUERY_TYPE;

    for (const auto& patternEntry: queryDecTree) {
        if (std::smatch matches; std::regex_match(cleanQuery, matches, patternEntry.queryRgx)) {
            queryType = patternEntry.type;
            switch (queryType) {
                case QueryType::GEOMETRY_ENGINE:
                    Geometry::ParseQuery(cleanQuery, patternEntry.queryRgx, patternEntry.eqFmt);
                    break;
                case QueryType::CIRCLE_ENGINE:
                    Circle::ParseQuery(cleanQuery, patternEntry.queryRgx, patternEntry.eqFmt);
                    break;
                default:
                    std::cerr << "Could not process query syntax. Consider revising your input.";
                    break;
            }
        }
    }
}
#ifndef QUERYENGINE_H
#define QUERYENGINE_H
#include <memory>

#include "src/circle/circle.h"
#include "src/parabola/parabola.h"
#include "src/hyperbola/hyperbola.h"

#include <string>

class QueryEngine
{
    enum class QueryType {
        CIRCLE_ENGINE, PARABOLA_ENGINE, HYPERBOLA_ENGINE, ELLIPSE_ENGINE, UNKNOWN
    };
public:
    QueryEngine();
    ~QueryEngine();
    QueryType parseUserQuery(const std::string& query);
private:
    std::unique_ptr<Circle> circle;
    std::unique_ptr<Parabola> parabola;
    std::unique_ptr<Hyperbola> hyperbola;

    bool operationFound = false;
    static QueryType ascertainQueryType(const std::string& query);
};

#endif // QUERYENGINE_H

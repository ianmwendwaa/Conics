#ifndef QUERYENGINE_H
#define QUERYENGINE_H
#include "src/circle/circle.h"
#include "src/parabola/parabola.h"
#include "src/hyperbola/hyperbola.h"

#include <string>

class QueryEngine
{
public:
    QueryEngine();
    ~QueryEngine();
    bool parseUserQuery(const std::string& query);
private:
    Circle* circle;
    Parabola* parabola;
    Hyperbola* hyperbola;
    bool operationFound;
};

#endif // QUERYENGINE_H

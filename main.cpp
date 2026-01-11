#include <iostream>
#include "src/circle/circle.h"
#include "src/engine/queryengine.h"

int main() {
    QueryEngine queryEngine;
    std::string query;
    std::cin >> query;
    queryEngine.parseUserQuery(query);
}

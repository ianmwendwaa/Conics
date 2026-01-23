#include <iostream>
#include "src/circle/circle.h"
#include "src/engine/queryengine.h"
#include "src/geometry.h"

int main() {
    Geometry geo;
    std::string query;
    std::cout << "Enter equation: ";
    std::cin >> query;
    std::cout << query << "\n";
    geo.QuadraticRoots(query);
    return 0;
}

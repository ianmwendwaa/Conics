#include <iostream>
#include "src/engine/queryengine.h"

int main() {
    std::string query;
    std::cout << "Enter equation: ";
    std::cin >> query;
    QueryEngine::AscertainQueryType(query);
    return 0;
}

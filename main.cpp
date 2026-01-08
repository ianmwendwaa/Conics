#include <iostream>
#include "src/circle/circle.h"
int main() {
    Circle circle;
    std::string query;
    std::cout << "input equation: ";
    std::cin >> query;
    circle.parseUserQuery(query);
}

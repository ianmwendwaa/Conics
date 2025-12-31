#include "circle.h"

#include <iostream>
#include <sstream>
#include <regex>
Circle::Circle() {
    int a{},b{},r{};

    // (x-a)2 + (y-b)2 = r2

    // Expand:
    // x(x-3) - 3(x-3)
    // x*x - x*3 - 3*x + 3*3
    std::cout << "Paste question here (x-a)2 + (y-b)2 = r2: ";
    std::string spacelessStr;
    if (std::string input; std::getline(std::cin, input)) {
        std::string word;
        std::istringstream iss(input);
        while (iss >> word) {
            spacelessStr += word;
        }
        std::cout << spacelessStr;
        // (x-a)2+(y-b)2=r2
        const std::regex rgx(R"(\(x([+-]\d+)\)2\+\(y([+-]\d+)\)2=(\d+))");
        std::smatch matches;
        if (std::regex_match(spacelessStr, matches, rgx)) {
            std::cout << "Equation matches the format provided!";

            std::string strA = matches[1].str();
            std::string strB = matches[2].str();
            std::string strR = matches[3].str();

            a = std::stoi(strA);
            b = std::stoi(strB);
            r = std::stoi(strR);
        }else {
            std::cerr << "Unresolved circle equation syntax provided! Confirm the syntax follows the form:(x-a)2+(y-b)2=r2";
            exit(-1);
        }
    }
}

#include "circle.h"

#include <cmath>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <regex>
Circle::Circle() {
    int a{},b{},r{};

    // (x-a)2 + (y-b)2 = r2

    // Expand:
    // x(x-3) - 3(x-3)
    // x*x - x*3 - 3*x + 3*3
    std::cout << "Question: ";
    std::string spacelessStr;
    if (std::string input; std::getline(std::cin, input)) {
        std::string word;
        std::istringstream iss(input);
        while (iss >> word) {
            spacelessStr += word;
        }
        std::cout << spacelessStr;

        if (spacelessStr.empty()) {
            std::cerr << "Error (NULL) question. No question was provided!\n";
            exit(-1);
        }

        // List of all keywords, which may help tell the program what to do.
        std::vector<std::string> queryKeyWords = {"determine","compute","find",
            "equation","radius","centre"};

        // Find occurrence of the brackets and comma, to extract coordinates of the centre
        size_t endPointsCoordinatesPositionBracket1 = spacelessStr.find('(');
        size_t endPointsCoordinatesPositionBracket2 = spacelessStr.find(')');
        size_t commaSeparatorPosition = spacelessStr.find(',');

        if (endPointsCoordinatesPositionBracket1 == std::string::npos && endPointsCoordinatesPositionBracket2 == std::string::npos) {
            // No brackets found, so no endpoints provided. If so, look for another possible query by the user
        }

        std::string endPointsCoordinatesStr = spacelessStr.substr(endPointsCoordinatesPositionBracket1, endPointsCoordinatesPositionBracket2);
        std::string aStr = spacelessStr.substr(endPointsCoordinatesPositionBracket1+1, (commaSeparatorPosition-endPointsCoordinatesPositionBracket1)-1);
        std::string bStr = spacelessStr.substr(commaSeparatorPosition+1, (endPointsCoordinatesPositionBracket2 - commaSeparatorPosition)-1);

        double a = std::stod(aStr);
        double b = std::stod(bStr);
        double r = 0;

        // Print the simple equation in the form (x-a)2 + (y-b)2 = r2
        auto formatUnexpandedEquation = [](char variable, double value) {
            std::stringstream ss;
            if (value == 0) return std::string(1, variable) + "2";

            ss << "(" << std::string(1, variable) << (value > 0 ? "+":"-")<< std::abs(value) << ")2";
            return ss.str();
        };

        // Expanded equation resembles: x2 + y2 + Dx + Ey + F = 0, where, D=-2*a, E=-2*b and F=a2+b2-r2
        double D = -2 * a;
        double E = -2 * b;
        double F = (std::pow(a, 2)+std::pow(b, 2) - std::pow(r, 2));
        auto formatExpandedEquation = [&] {
            std::stringstream ss;
            ss << "x2+y2";
            if (D != 0) ss << (D > 0 ? "+": "-") << std::abs(D) << "x";
            if (E != 0) ss << (E > 0 ? "+": "-") << std::abs(E) << "y";
            if (F != 0) ss << (E > 0 ? "+": "-") << std::abs(F);
            ss << "= 0";
            return ss.str();
        };

        std::cout << "Unexpanded equation is: " << formatUnexpandedEquation('x', a) <<
            formatUnexpandedEquation('y', b) << "=" << std::pow(r, 2);

        std::cout << "Expanded equation is: " << formatExpandedEquation();
    }
}

std::string Circle::inputAndFormatQuery() {
    // Obtain the question from the user
    if (std::string input; std::getline(std::cin, input)) {
        std::string word;
        std::istringstream iss;
        while (iss >> word) {
            formattedQuery += word;
        }
    }
    // Convert query to lowercase
    std::transform(formattedQuery.begin(), formattedQuery.end(), formattedQuery.begin(),
        [](unsigned char c) {
            return std::tolower(c);
        });
    return formattedQuery;
}


#include "circle.h"

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

        int endPointsCoordinatesPositionBracket1 = spacelessStr.find('(');
        int endPointsCoordinatesPositionBracket2 = spacelessStr.find(')');

        if (endPointsCoordinatesPositionBracket1 == std::string::npos && endPointsCoordinatesPositionBracket2 == std::string::npos) {
            // No brackets found, so no endpoints provided. If so, look for another possible query by the user
        }

        std::string endPointsCoordinatesStr = spacelessStr.substr(endPointsCoordinatesPositionBracket1, endPointsCoordinatesPositionBracket2);

        std::cout << endPointsCoordinatesStr;
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

            //x(x-a) - a(x-a)->x2 - ax -ax + a2
            //x(x+a) + a(x+a)-> x2  + ax + ax + a2

            //y(y-b) - b(y-b)->y2 - by - by + b2
            if (a > 0 && b > 0) {
                std::cout <<
                    "The equation of the circle is: x2 - "<< a+a<<"x"+ a*a;
            }
        }else{
            std::cerr <<
                    "Unresolved circle equation syntax provided! Confirm the syntax follows the form:(x-a)2+(y-b)2=r2";
            exit(-1);
        }
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
    // Convert to lowercase
    std::transform(formattedQuery.begin(), formattedQuery.end(), formattedQuery.begin(),
        [](unsigned char c) {
            return std::tolower(c);
        });
    return formattedQuery;
}


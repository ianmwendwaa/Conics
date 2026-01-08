#include "circle.h"

#include <cmath>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <regex>
Circle::Circle() {
    // (x-a)2 + (y-b)2 = r2

    // Expand:
    // x(x-3) - 3(x-3)
    // x*x - x*3 - 3*x + 3*3
    // std::cout << "Question: ";
    // std::string spacelessStr;
    // if (std::string input; std::getline(std::cin, input)) {
    //     std::string word;
    //     std::istringstream iss(input);
    //     while (iss >> word) {
    //         spacelessStr += word;
    //     }
    //     std::cout << spacelessStr;

    //     if (spacelessStr.empty()) {
    //         std::cerr << "Error (NULL) question. No question was provided!\n";
    //         exit(-1);
    //     }

    //     // List of all keywords, which may help tell the program what to do.
    //     std::vector<std::string> queryKeyWords = {"determine","compute","find",
    //         "equation","radius","centre"};

    //     // Find occurrence of the brackets and comma, to extract coordinates of the centre
    //     size_t endPointsCoordinatesPositionBracket1 = spacelessStr.find('(');
    //     size_t endPointsCoordinatesPositionBracket2 = spacelessStr.find(')');
    //     size_t commaSeparatorPosition = spacelessStr.find(',');

    //     if (endPointsCoordinatesPositionBracket1 == std::string::npos && endPointsCoordinatesPositionBracket2 == std::string::npos) {
    //         // No brackets found, so no endpoints provided. If so, look for another possible query by the user
    //     }

    //     std::string endPointsCoordinatesStr = spacelessStr.substr(endPointsCoordinatesPositionBracket1, endPointsCoordinatesPositionBracket2);
    //     std::string aStr = spacelessStr.substr(endPointsCoordinatesPositionBracket1+1, (commaSeparatorPosition-endPointsCoordinatesPositionBracket1)-1);
    //     std::string bStr = spacelessStr.substr(commaSeparatorPosition+1, (endPointsCoordinatesPositionBracket2 - commaSeparatorPosition)-1);

    //     double a = std::stod(aStr);
    //     double b = std::stod(bStr);
    //     double r = 0;

    //     // Print the simple equation in the form (x-a)2 + (y-b)2 = r2
    //     auto formatUnexpandedEquation = [](char variable, double value) {
    //         std::stringstream ss;
    //         if (value == 0) return std::string(1, variable) + "2";

    //         ss << "(" << std::string(1, variable) << (value > 0 ? "+":"-")<< std::abs(value) << ")2";
    //         return ss.str();
    //     };

    //     // Expanded equation resembles: x2 + y2 + Dx + Ey + F = 0, where, D=-2*a, E=-2*b and F=a2+b2-r2
    //     double D = -2 * a;
    //     double E = -2 * b;
    //     double F = (std::pow(a, 2)+std::pow(b, 2) - std::pow(r, 2));
    //     auto formatExpandedEquation = [&] {
    //         std::stringstream ss;
    //         ss << "x2+y2";
    //         if (D != 0) ss << (D > 0 ? "+": "-") << std::abs(D) << "x";
    //         if (E != 0) ss << (E > 0 ? "+": "-") << std::abs(E) << "y";
    //         if (F != 0) ss << (F > 0 ? "+": "-") << std::abs(F);
    //         ss << "= 0";
    //         return ss.str();
    //     };

    //     std::cout << "Unexpanded equation is: " << formatUnexpandedEquation('x', a) <<
    //         formatUnexpandedEquation('y', b) << "=" << std::pow(r, 2);

    //     std::cout << "Expanded equation is: " << formatExpandedEquation();
    // }
}
bool Circle::parseUserQuery(const std::string& query) {
    // Normalize the query to remove whitespaces and convert to lowercase
    std::string cleanQuery = query;
    cleanQuery.erase(std::remove(cleanQuery.begin(), cleanQuery.end(), ' '), cleanQuery.end());
    std::transform(cleanQuery.begin(), cleanQuery.end(), cleanQuery.begin(), ::tolower);

    std::smatch matches;

    // Matches: (x-h)2+(y-k)2=r2
    const std::regex unexpandedRegex(R"(\(x([+-]\d+)\)2\+\(y([+-]\d+)\)2=(\d+))");

    if (std::regex_search(cleanQuery, matches, unexpandedRegex)) {
        // Regex group 1 is 'a' with flipped sign, group 2 is 'b' with flipped sign
        // We multiply by -1 because the formula is (x - a)
        this->a = std::stod(matches[1].str())* -1;
        this->b = std::stod(matches[2].str())* -1;
        this->r = std::sqrt(std::stod(matches[3].str())); // r^2 is provided
        return true;
    }

    // Algorithm to cover the expanded equation x2 + y2 + Dx + Ey + F = 0
    const std::regex expandedRegex(R"(x2\+y2([+-]\d+)x([+-]\d+)y([+-]\d+)=0)");

    if (std::regex_search(cleanQuery, matches, expandedRegex)) {
        const double D = std::stod(matches[1].str());
        const double E = std::stod(matches[2].str());
        const double F = std::stod(matches[3].str());

        // Center (a, b) = (-D/2, -E/2)
        this->a = -D / 2.0;
        this->b = -E / 2.0;
        // r = sqrt(a^2 + b^2 - F)
        this->r = std::sqrt((a * a) + (b * b) - F);
        return true;
    }

    // If radius and centre are provided, apply the following algorithm
    const std::regex coordRegex(R"(centre\(([+-]?\d+\.?\d*),([+-]?\d+\.?\d*)\))");
    const std::regex radiusRegex(R"(radius([+-]?\d+\.?\d*))");

    if (std::regex_search(cleanQuery, matches, coordRegex)) {
        this->a = std::stod(matches[1].str());
        this->b = std::stod(matches[2].str());

        if (std::regex_search(cleanQuery, matches, radiusRegex)) {
            this->r = std::stod(matches[1].str());
            return true;
        }
    }
    return false; // No valid circle data found
}
Circle::QueryType Circle::findUserIntent(const std::string& query) {
    bool hasEquation = query.find("equation") != std::string::npos;
    bool hasRadius = query.find("radius") != std::string::npos;
    bool hasCentre = (query.find("center") && query.find("at")) != std::string::npos;

    bool userIntent = query.find("determine");

    if (query.find("area") != std::string::npos || query.find("circumference"))
        return QueryType::FIND_AREA_CIRCUMFERENCE;
    if (query.find("equation") != std::string::npos)
        return QueryType::FIND_EQUATION;
    if (query.find("congruent") != std::string::npos)
        return QueryType::FIND_CONGRUENCE_RATIO;

    return QueryType::UNKNOWN;
}

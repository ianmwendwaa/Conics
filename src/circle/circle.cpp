#include "circle.h"

#include <cmath>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <regex>
#include <algorithm>
Circle::Circle() {

}
bool Circle::parseUserQuery(const std::string& query) {
    // Normalize the query to remove whitespaces and convert to lowercase
    std::string cleanQuery = query;
    cleanQuery.erase(std::ranges::remove(cleanQuery, ' ').begin(), cleanQuery.end());
    std::ranges::transform(cleanQuery, cleanQuery.begin(), ::tolower);

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

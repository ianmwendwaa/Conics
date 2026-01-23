#include "geometry.h"

#include <algorithm>
#include <regex>
#include <cmath>
#include <iostream>

Geometry::Geometry() = default;

std::pair<double, double> Geometry::QuadraticRoots(const std::string& query) {
    std::string cleanQuery = query;
    cleanQuery.erase(std::ranges::remove(cleanQuery, ' ').begin(), cleanQuery.end());
    std::ranges::transform(cleanQuery, cleanQuery.begin(), ::tolower);

    // Contort different regex patterns to extract values from the equations
    const std::vector<std::regex> quadraticPgxPatterns = {
        std::regex(R"(([+-]\d+)x2([+-]\d+)x([+-]\d+)=0)"),
        std::regex(R"((\d+)x2([+-]\d+)x([+-]\d+)=0)")
        };
    std::smatch match;

    for (const auto& pattern: quadraticPgxPatterns) {
        if (std::regex_match(cleanQuery, match, pattern)) {

        }
    }
    const std::regex quadraticRgx(R"(([+-]?\d+)x2([+-]\d+)x([+-]\d+)=0)");

    auto parseCoefficients = [&](const std::string& s) {
      if (s.empty() || s == "-x") return -1.0;
        if (s == "+x" || s == "x") return 1.0;
        return std::stod(s);
    };

    if (std::regex_match(query, match, quadraticRgx)) {
        this->a = std::stod(match[1].str());
        this->b = std::stod(match[2].str());
        this->c = std::stod(match[3].str());
    }
    std::cout << this->a << "\n";
    std::cout << this->b << "\n";
    std::cout << this->c << "\n";
    // Find the roots applying the formula: (-b+-(b2 - 4ac).sqrt)/2a

    // Check if the square root of discriminant is positive, negative or equal to zero
    double discriminantSqrt = std::sqrt(std::pow(this->b, 2) - (4 * this->a * this->c));
    double x1 = (-this->b + std::sqrt(std::pow(this->b, 2) - (4 * this->a * this->c)))/(2 * this->a);
    double x2 = (-this->b - std::sqrt(std::pow(this->b, 2) - (4 * this->a * this->c)))/(2 * this->a);

    std::cout << "x1: " << x1 << " x2: " << x2 << std::endl;
    return std::make_pair(x1, x2);
}

Geometry::~Geometry() = default;


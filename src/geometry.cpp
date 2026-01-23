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
    const double discriminant = std::pow(this->b, 2) - (4 * this->a * this->c);

    const double two_a = 2 * this->a;

    // If it is positive, and greater than 0, it has two real and distinct roots
    if (discriminant > 0) {
        const double discriminantSqrt = std::sqrt(discriminant);
        const double x1 = (-this->b + discriminantSqrt)/two_a;
        const double x2 = (-this->b - discriminantSqrt)/two_a;
        std::cout << "x1: " << x1 << " x2: " << x2 << std::endl;
        // Expressing in surd form gives:
        auto findSimplestSurd = [&](const double& d) {
            // First check if the number is a prime number. If so, leave it untouched
            bool is_prime{};
            double result = 0;

            for (size_t i = 2; i <= std::sqrt(d); i++) {
                if (std::fmod(d, i) != 0) {
                    is_prime = true;
                    break;
                }
            }
            if (is_prime) return d;

        };
        std::cout << "Expressed in surd form: " <<
            (std::fmod(this->b, two_a) == 0.0 ? -this->b/two_a : -this->b) << "+- _/"<< discriminant <<"\n";
    }

    // If it is negative, it has no real roots, or two complex roots
    if (discriminant < 0) {
        // Express the result in its simplest form, should b be a multiple of 2a
        if (std::fmod(this->b, two_a) == 0.0) {
            std::cout << "x1: "<< -this->b / two_a << " + sqrt("<<discriminant<< ")" <<
                " or x1: " << -this->b / two_a <<(discriminant > 0.0 ? "+":"-") << std::abs(discriminant) <<"i\n";
            std::cout << "x2: "<< -this->b / two_a << " + sqrt("<<discriminant<< ")" <<
                " or x2: " << -this->b / two_a <<(discriminant > 0.0 ? "+":"-") << std::abs(discriminant) <<"i\n";
        }else {
            std::cout << "x1: " <<-this->b << "+ √"<<discriminant << ")/" << two_a<<"\n";
            std::cout << "x2: " <<-this->b << "- √"<<discriminant << ")/" << two_a<<"\n";
        }
    }
    VertexQuadraticForm();

    return std::make_pair(1.0, 1.0);
}

void Geometry::VertexQuadraticForm() {
    /* This is expressed in the form (x+a)2+b. It is achieved by completing the square. First, find
     * the value of a, which is b/2. Add it to ax2+bx and subtract it from c.
     */
    const double a = this->b / 2.0;
    const double b = -std::pow(a,2) + this->c;

    std::cout << "(" << this->a << "x + " << std::abs(a) << ")2" << (b > 0.0 ? " + ":" - ") << std::abs(b);
}


Geometry::~Geometry() = default;


#include "geometry.h"

#include <algorithm>
#include <regex>
#include <cmath>
#include <iostream>

Geometry::Geometry() = default;

inline auto findSimplestSurd = [](const int& d) {
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

    // To find the surd, find the greatest perfect square. It should be less than the provided number
    double gps = 0;// greatest perfect square

    // Vector to store the values found
    std::vector<int> surdValues;
    for (size_t i = d; i > 0; i--) {
        if (std::sqrt(i) == d) {
            surdValues.emplace_back(i);
        }
    }
};
inline bool isPerfectSquare(long long d) {
    if (d <= 0) return false;// Cannot find square root of 0 or negative numbers

    if (std::sqrt(d) != d) return false;// Square root is not equal to provided number

    return true;// If both are false, d is a perfect square

}
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

        std::cout << "Expressed in surd form: " <<
            (std::fmod(this->b, two_a) == 0.0 ? -this->b/two_a : -this->b) << "+- _/"<< discriminant <<"\n";
    }

    // If it is negative, it has no real roots, or two complex roots
    if (discriminant < 0) {
        // Express the result in its simplest form, should b be a multiple of 2a
        if (std::fmod(this->b, two_a) == 0.0) {
            // Express it as: a ± bi
            std::cout << "x1: " << -this->b / two_a <<(discriminant > 0.0 ? "+":"-") << std::abs(discriminant) <<"i\n";
            // If discriminant is negative, make it positive since -1*-1 = 1
            std::cout << "x2: " << -this->b / two_a <<(discriminant < 0.0 ? "+":"-") << std::abs(discriminant) <<"i\n";
        }else {
            std::cout << "x1: " <<-this->b << "+ √"<<discriminant << ")/" << two_a<<"\n";
            std::cout << "x2: " <<-this->b << "- √"<<discriminant << ")/" << two_a<<"\n";
        }
    }
    VertexQuadraticForm();
    CompareAndSolveEquation();

    return std::make_pair(1.0, 1.0);
}

void Geometry::VertexQuadraticForm() {
    /* This is expressed in the form (x+a)2+b. It is achieved by completing the square. First, find
     * the value of a, which is b/2. Add it to ax2+bx and subtract it from c.
     */
    this->a_v = this->b / 2.0;
    this->b_v = -std::pow(a_v,2) + this->c;

    std::cout << "Expressed in the form (x+a)2 + b: " <<
        "(" << this->a << "x" << (this->a_v > 0 ? "+":"-")<< std::abs(this->a_v) << ")2"
    << (this->b_v > 0 ? " + ":" - ") << std::abs(this->b_v) <<"\n";
    // Ascertain whether f(x) is positive for all values of x
    if (b_v > 0) {
        std::cout << "f(x) > 0 for all values of x\n";
    }
}

void Geometry::CompareAndSolveEquation(){
    /* Here, compare f(x) to the vertex form of the equation. Normally, f(x) = 0. Therefore, simulate
     * taking b to the other side of the equation. If it is negative, it becomes positive and vice versa.
     */
    if (this->b_v < 0)
        this->b_v = std::abs(this->b_v);// make it positive
    else
        this->b_v = -(this->b_v);// negate it
    /* Next, find its square root. If it is negative, display it as an imaginary number. If it is a perfect square, find
     * the square root. If not a perfect square, display it as the simplest surd
     */
    if (!isPerfectSquare(this->b_v)) {
        std::cout << this->b_v << " is not a perfect square. Invoking surd func...\n";
    }else {
        std::cout << this->b_v << " is a perfect square";
    }
}


Geometry::~Geometry() = default;


#include "geometry.h"
#include "core.h"

#include <algorithm>
#include <regex>
#include <cmath>
#include <iostream>

Geometry::Geometry() {
    core = std::make_unique<Core>();
};

inline bool isPerfectSquare(double d) {
    if (d <= 0) return false;// Cannot find square root of 0 or negative numbers
    const double sqr = std::sqrt(d);
    return (sqr * sqr == d);
}

inline bool isPrime(double d) {
    double result = 0;
    int div_counter = 0;

    for (int i = 2; i <= std::sqrt(d); i++) {
        if (std::fmod(d, i) == 0) {
            div_counter++;
        }
    }
    if (div_counter > 0) return false;// Meaning more than one divisor has been found

    return true;
}

void Geometry::QuadraticRoots(const std::string& query) {
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
    core->WriteDataResults("geometry.txt",
        "a: ",this->a,
        "b: ",this->b,
        "c: ",this->c,
        "a_v: ",this->a_v,
        "b_v: ",this->b_v);
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
     * the square root. If not a perfect square, express it as its simplest surd
     */
    if (!isPerfectSquare(this->b_v)) {
        std::cout << this->b_v << " is not a perfect square. Invoking surd func...\n";
        std::cout << FindSurdExpression(this->b_v);
    }else
        std::cout << this->b_v << " is a perfect square";

    // Contort results-> x = ±a ± surd. Simulate conversion of a_v's sign
    if (this->a_v < 0) {
        this->a_v = std::abs(this->a_v);
    }else {
        this->a_v = -(this->a_v);
    }

    FindSurdExpression(this->b_v);


}
double Geometry::FindSurdExpression(double& d) {
    // First check if the number is positive
    if (d < 0) return d;
    // if (d == 0) return 0;

    // Then, check if the number is a prime number. If so, leave it untouched
    if (isPrime(d)) return d;

    // If the number is a perfect square, no need to find its surd. So return its square root
    if (isPerfectSquare(d))
        return sqrt(d);

    double result = 0;

    std::vector<double> multiples;

    // All tests failed, so d must not be a prime number and is a perfect square. So, obtain the greatest square
    for (int i = 0; i < d; i++) {
        for (int j = 2; j < d; j++) {
            if (isPrime(j) && isPerfectSquare(i)) {
                result = i * j;
                if (result == d) {
                    multiples.emplace_back(i);
                    multiples.emplace_back(j);
                }
            };
        }
    }

    double squareOSrd = 0;// stores the raw squared outer surd

    for (const auto& it: multiples) {
        if (isPerfectSquare(it)) {
            squareOSrd = it;
        }
    }

    this->outer_surd = std::sqrt(squareOSrd);

    std::cout << "Values of x in surd form, given that f(x) = 0: "<< this->outer_surd << "± sqrt(" << multiples.at(1) <<")\n";

    return 0.0;
}

Geometry::~Geometry() = default;


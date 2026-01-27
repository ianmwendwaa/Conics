#include "src/geometry/geometry.h"

#include <cmath>

void Geometry::ParseQuery(const std::string &query, const std::regex& pattern, const EquationForm format) {
    Geometry::geoQuery = query;
    EquationForm form = format;
    switch (form) {
        case EquationForm::STANDARD:
            Geometry::StandardFormEvaluator(query, pattern);
            break;
        case EquationForm::FACTORED:
            Geometry::FactoredFormEvaluator(query, pattern);
            break;
        case EquationForm::VERTEX:
            Geometry::VertexFormEvaluator(query, pattern);
            break;
        default:
            std::cerr << "Could not establish the Geometric equation's format\n";
            break;
    }
}

void Geometry::StandardFormEvaluator(const std::string &query, const std::regex& pattern) {
    const auto d = new Geometry::Data;
    if (std::smatch match; std::regex_match(query, match, pattern)) {
        d->a = std::stod(match[1].str());
        d->b = std::stod(match[2].str());
        d->c = std::stod(match[3].str());
    }
    std::cout << d->a << "\n";
    std::cout << d->b << "\n";
    std::cout << d->c << "\n";

    auto parseCoefficients = [&](const std::string& s) {};
        // //       if (s.empty() || s == "-x") return -1.0;
        // //         if (s == "+x" || s == "x") return 1.0;
        // //         return std::stod(s);
        // //     };

    const double discriminant = std::pow(d->b, 2) - (4 * d->a * d->c);

    const double two_a = 2 * d->a;

    // If it is positive, and greater than 0, it has two real and distinct roots
    if (discriminant > 0) {
        const double discriminantSqrt = std::sqrt(discriminant);
        const double x1 = (-d->b + discriminantSqrt)/two_a;
        const double x2 = (-d->b - discriminantSqrt)/two_a;
        std::cout << "x1: " << x1 << " x2: " << x2 << std::endl;
        // Expressing in surd form gives:

        std::cout << "Expressed in surd form: " <<
            (std::fmod(d->b, two_a) == 0 ? -d->b/two_a : -d->b) << "+- _/"<< discriminant <<"\n";
    }

    // If it is negative, it has no real roots, or two complex roots
    if (discriminant < 0) {
        // Express the result in its simplest form, should b be a multiple of 2a
        if (std::fmod(d->b, two_a) == 0) {
            // Express it as: a ± bi
            std::cout << "x1: " << -d->b / two_a <<(discriminant > 0 ? "+":"-") << std::abs(discriminant) <<"i\n";
            // If discriminant is negative, make it positive since -1*-1 = 1
            std::cout << "x2: " << -d->b / two_a <<(discriminant < 0 ? "+":"-") << std::abs(discriminant) <<"i\n";
        }else {
                std::cout << "x1: " <<-d->b << "+ √"<<discriminant << ")/" << two_a<<"\n";
                std::cout << "x2: " <<-d->b << "- √"<<discriminant << ")/" << two_a<<"\n";
        }
    }

    delete d;
}

void Geometry::FactoredFormEvaluator(const std::string &query,const std::regex& pattern) {

}

void Geometry::VertexFormEvaluator(const std::string &query,const std::regex& pattern) {

}
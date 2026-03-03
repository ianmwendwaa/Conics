#include "src/geometry/geometry.h"

#include <cmath>
#include "lib/math.h"
Geometry::Geometry() = default;

void Geometry::ParseQuery(const std::string &query, const std::regex& pattern, const EquationForm format) {
    try{
        EquationForm form = format;
        Geometry geometry;
        switch (form) {
        case EquationForm::STANDARD:
            geometry.StandardFormEvaluator(query, pattern);
            break;
        case EquationForm::FACTORED:
            geometry.FactoredFormEvaluator(query, pattern);
            break;
        case EquationForm::VERTEX:
            geometry.VertexFormEvaluator();
            break;
        default:
            std::cerr << "Could not establish the Geometric equation's format\n";
            break;
        }
    }catch (std::exception& e){
        std::cerr << "Exception: " << e.what();
    }
}

void Geometry::StandardFormEvaluator(const std::string &query, const std::regex& pattern) {
    /* Consider an equation x2+6x+10=0. The standard equation is given in the form ax2+bx+c=0.
     * In this case, a would be 1, b would be 6 and c would be 10. If any were negative, the
     * negative should be included in the result. Some instances have equations implicitly mapping
     * the value of x2 to 1. Therefore, the program should clear the air, should any of the values fail to
     * be explicitly defined. Map them to 1. The helper function below aids in this.
     */
    this->geo_query = query;
    auto parse_coefficients = [&](const std::string& s){
        // ToDo: This is just glue code that seems to work at the moment. Shall revisit...
        if (s.empty()) return 1.0;
        const double s_val = std::stod(s);
        return s == "x"? 1 : s_val;
    };
    if (std::smatch match; std::regex_match(query, match, pattern)) {
        this->a = parse_coefficients(match[1].str());
        this->b = parse_coefficients(match[2].str());
        this->c = parse_coefficients(match[3].str());
    }
    std::cout << this->a << "\n";
    std::cout << this->b << "\n";
    std::cout << this->c << "\n";
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
            (std::fmod(this->b, two_a) == 0 ? -this->b/two_a : -this->b) << "+- _/"<< discriminant <<"\n";
        std::cout << "Expressed in simplest surd form: \n" << CMath::find_surd_expression(discriminant);
    }

    // If it is negative, it has no real roots, or two complex roots
    if (discriminant < 0)
    {
        // Express the result in its simplest form, should b be a multiple of 2a
        if (std::fmod(this->b, two_a) == 0) {
            // Express it as: a ± bi
            std::cout << "x1: " << -this->b / two_a <<(discriminant > 0 ? "+":"-") << std::abs(discriminant) <<"i\n";
            // If discriminant is negative, make it positive since -1*-1 = 1
            std::cout << "x2: " << -this->b / two_a <<(discriminant < 0 ? "+":"-") << std::abs(discriminant) <<"i\n";
        }else {
            std::cout << "x1: " <<-this->b << "+ √"<<discriminant << ")/" << two_a<<"\n";
            std::cout << "x2: " <<-this->b << "- √"<<discriminant << ")/" << two_a<<"\n";
        }
    }
    // Finding quadratic roots using the provided equation
    /* Consider an equation as used before: x2+6x+10=0. To get the quadratic roots, we have to find two numbers
     * which when added give us +6 and when multiplied,give us +10...bummer. Or should I just stick to the quadratic
     * formula? Well, for the purpose of testing my sanity's limits, I guess it's worth chasing
     */

    // variables to store these two numbers
    double num1{}, num2 = 1;
    bool ints_found = false;
    // Infinitely search for these two numbers and break when a match is found
    // while (ints_found){
    //     if (num1*num2 == this->c && num1+num2 == this->b){
    //         std::cout << "Roots of the equation" << query << "is: " << num1 << " and " << num2;
    //         ints_found = true;
    //     }
    //     num1++;
    //     num2++;
    // }
}

void Geometry::FactoredFormEvaluator(const std::string &query,const std::regex& pattern) {

}

void Geometry::VertexFormEvaluator() {
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

void Geometry::QuadraticRoots(){

}

Geometry::~Geometry() = default;

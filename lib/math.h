//
// Created by Owner on 2/28/2026.
//

#ifndef MATH_H
#define MATH_H
#include <cmath>
#include <iostream>
#include <vector>
namespace CMath {
    inline bool is_prime(const double &d) {
        if (d <= 0) return false;// Cannot find square root of 0 or negative numbers
        const double sqr = std::sqrt(d);
        return (sqr * sqr == d);
    }
    inline bool is_perfect_square(const double &d) {
        int div_counter = 0;

        for (int i = 2; i <= std::sqrt(d); i++) {
            if (std::fmod(d, i) == 0) {
                div_counter++;
            }
        }
        if (div_counter > 0) return false;// Meaning more than one divisor has been found

        return true;
    }
    inline double find_surd_expression(const double& d, double& outerSurd) {
        // First check if the number is positive
        if (d < 0) return d;
        // if (d == 0) return 0;

        // Then, check if the number is a prime number. If so, leave it untouched
        if (is_prime(d)) return d;

        // If the number is a perfect square, no need to find its surd. So return its square root
        if (is_perfect_square(d))
            return sqrt(d);
        double result = 0;
        std::vector<double> multiples;
        // All tests failed, so d must not be a prime number and is a perfect square. So, obtain the greatest square
        for (int i = 0; i < d; i++) {
            for (int j = 2; j < d; j++) {
                if (is_prime(j) && is_perfect_square(i)) {
                    result = i * j;
                    if (result == d) {
                        multiples.emplace_back(i);
                        multiples.emplace_back(j);
                    }
                }
            }
        }
        double squareOSrd = 0;// stores the raw squared outer surd
        for (const auto& it: multiples) {
            if (is_perfect_square(it)) {
                squareOSrd = it;
            }
        }
        outerSurd = std::sqrt(squareOSrd);
        std::cout << "Values of x in surd form, given that f(x) = 0: "<< outerSurd << "± sqrt(" << multiples.at(1) <<")\n";
        return std::nan("");
    }

}
#endif //MATH_H

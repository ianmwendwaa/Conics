//
// Created by Owner on 1/25/2026.
//

#include "core.h"

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

namespace Core {
    std::string NormalizeQuery(const std::string &query) {
        // This function takes in the query, converts it to lowercase and removes whitespaces to increase predictability
        std::string cleanQuery = query;
        std::ranges::transform(cleanQuery, cleanQuery.begin(), ::tolower);
        auto [ret, back] = std::ranges::remove(cleanQuery, ' ');
        cleanQuery.erase(ret, back);
        return cleanQuery;
    }

    bool isPerfectSquare(const double &d) {
        int div_counter = 0;

        for (int i = 2; i <= std::sqrt(d); i++) {
            if (std::fmod(d, i) == 0) {
                div_counter++;
            }
        }
        if (div_counter > 0) return false;// Meaning more than one divisor has been found

        return true;
    }

    bool isPrime(const double &d) {
        if (d <= 0) return false;// Cannot find square root of 0 or negative numbers
        const double sqr = std::sqrt(d);
        return (sqr * sqr == d);
    }

    /* ToDo:// This function is faulty; some logic has been lost during translation to multipurpose functionality.
     *  Revisit this as soon as you can.
     */
    double FindSurdExpression(const double& d, double& outerSurd) {
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

        outerSurd = std::sqrt(squareOSrd);

        std::cout << "Values of x in surd form, given that f(x) = 0: "<< outerSurd << "± sqrt(" << multiples.at(1) <<")\n";

        return std::nan("");
    }
}


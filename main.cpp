// #include <tester.h>

#include <any>
#include <iostream>
#include <regex>
#include <string>
#include <sstream>

int main(){
    std::cout << "Question: ";
    std::string spacelessStr;
    if (std::string input; std::getline(std::cin, input)) {
        std::string word;
        std::istringstream iss(input);
        while (iss >> word) {
            spacelessStr += word;
        }
        // std::cout << spacelessStr;

        if (spacelessStr.empty()) {
            std::cerr << "Error (NULL) question. No question was provided!\n";
            exit(-1);
        }

        // Convert input to lower string
        std::transform(spacelessStr.begin(), spacelessStr.end(),spacelessStr.begin(),
            [](unsigned char c) {
                return std::tolower(c);
            });

        // List of all keywords, which may help tell the program what to do.
        std::vector<std::string> queryKeyWords = {"find",
            "equation","radius","r","centre"};

        for (const auto& keyWord : queryKeyWords) {

        }


        const size_t endPointsCoordinatesPositionBracket1 = spacelessStr.find('(');
        const size_t endPointsCoordinatesPositionBracket2 = spacelessStr.find(')');

        // Obtain the value of the radius (if provided)
        size_t radiusPosition= spacelessStr.find('r');

        // Obtain the coordinates in the format (h,k)
        std::string endPointsCoordinatesStr = spacelessStr.substr(endPointsCoordinatesPositionBracket1, (endPointsCoordinatesPositionBracket2-endPointsCoordinatesPositionBracket1)+1);

        // Find the comma separator, to separate the values of h and k
        size_t commaSeparatorPosition = spacelessStr.find(',');

        if (endPointsCoordinatesPositionBracket1 == std::string::npos ||
            endPointsCoordinatesPositionBracket2 == std::string::npos ||
            radiusPosition == std::string::npos ||
            commaSeparatorPosition == std::string::npos) {
            // No brackets found, so no endpoints provided. If so, look for another possible query by the user
            std::cerr << "Error parsing query! Missing information from the user.";
            throw std::exception();
        }

        const bool keyTermFound = std::any_of(queryKeyWords.begin(), queryKeyWords.end(),
            [&](const std::string& keyWord) {
            return spacelessStr.find(keyWord) != std::string::npos;
        });

        if (keyTermFound) {
            std::cout << "Query keyword found!";
        }

        std::string aStr = spacelessStr.substr(endPointsCoordinatesPositionBracket1+1, (commaSeparatorPosition - endPointsCoordinatesPositionBracket1)-1);

        std::string bStr = spacelessStr.substr(commaSeparatorPosition+1, endPointsCoordinatesPositionBracket2 - commaSeparatorPosition-1);

        std::cout << "value of a: "<<aStr << "and b: "<<bStr;

        // Apply the values to the general form of the equation
        double a = std::stoi(aStr);
        double b = std::stoi(bStr);

        // Represent in the form (x-a)2 + (y-b)2
        auto formatBracket = [](char variable, double value) {
            std::stringstream ss;
            if (value == 0) return std::string(1, variable);

            return "(" + std::string(1, variable) + (value < 0 ? "+": "-" ) + std::to_string(std::abs(variable)) + ")2";
        };

        std::cout << "Equation would be represented by: "<< formatBracket('x', a) << "+" << formatBracket('y', b) << "= r2";
    }

    // // y = a(x-h)2 + k
    // std::cout << "Enter equation: ";
    // std::string spacelessStr;
    // if (std::string input; std::getline(std::cin, input)) {
    //     std::string word;
    //     std::istringstream iss(input);
    //     while (iss >> word) {
    //         spacelessStr += word;
    //     }
    // }
    //
    // // x/y = 4p(x-h)2+k
    // std::regex vertexRgx(R"(y=([+-]?\d*)\(x([+-]\d+)\)2([+-]\d+)| x=([+-]?\d*)\(y([+-]\d+)\)2([+-]\d+))");
    //
    // // regex for advanced geometry: (x-h)2 = 4p(y-k)/(y-k)2 = 4p(x-h)
    // std::regex conicRgx(R"(\(x([+-]\d+)\)2=([+-]?\d+)\(y([+-]\d+)\)|\(y([+-]\d+)\)2=([+-]?\d+)\(x([+-]\d+)\))");
    //
    // std::smatch matches;
    // if (std::regex_match(spacelessStr, matches, conicRgx)) {
    //     // if matches the vertical parabola
    //     // if (!matches[1].matched && !matches[4].matched) {
    //     //     // if both don't match, try the normal one
    //     //     if (std::regex_match(spacelessStr, matches, vertexRgx)) {
    //     //         if (matches[1].matched) {
    //     //             const int p4 = std::stoi();
    //     //         }
    //     //     }
    //     // }
    //     if (matches[1].matched) {
    //         const int h = std::stoi(matches[1].str());
    //         const int p4 = std::stoi(matches[2].str());
    //         const int k = std::stoi(matches[3].str());
    //         std::cout << "Coordinates for the vertical parabola: h = "<< h << ". 4p = " << p4 << ", k = "<< k << "\n";
    //     }else if (matches[4].matched) {
    //         const int h = std::stoi(matches[1].str());
    //         const int p4 = std::stoi(matches[2].str());
    //         const int k = std::stoi(matches[3].str());
    //         std::cout << "Coordinates for the horizontal parabola: h = " << h <<" , 4p = " << p4 << ", k = " << k << "\n";
    //     }else {
    //         std::cerr << "Something's wrong with the provided equation!";
    //     }
    // }
    // // Tester tester;
    // // tester.startEngine();
    return 0;
}

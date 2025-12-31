#include <tester.h>

#include <iostream>
#include <regex>
#include <string>
#include <sstream>

int main(){
    // y = a(x-h)2 + k
    std::cout << "Enter equation: ";
    std::string spacelessStr;
    if (std::string input; std::getline(std::cin, input)) {
        std::string word;
        std::istringstream iss(input);
        while (iss >> word) {
            spacelessStr += word;
        }
    }

    // x/y = 4p(x-h)2+k
    std::regex vertexRgx(R"(y=([+-]?\d*)\(x([+-]\d+)\)2([+-]\d+)| x=([+-]?\d*)\(y([+-]\d+)\)2([+-]\d+))");

    // regex for advanced geometry: (x-h)2 = 4p(y-k)/(y-k)2 = 4p(x-h)
    std::regex conicRgx(R"(\(x([+-]\d+)\)2=([+-]?\d+)\(y([+-]\d+)\)|\(y([+-]\d+)\)2=([+-]?\d+)\(x([+-]\d+)\))");

    std::smatch matches;
    if (std::regex_match(spacelessStr, matches, conicRgx)) {
        // if matches the vertical parabola
        if (!matches[1].matched && !matches[4].matched) {
            // if both don't match, try the normal one
            if (std::regex_match(spacelessStr, matches, vertexRgx)) {

            }
        }
        if (matches[1].matched) {
            const int h = std::stoi(matches[1].str());
            const int p4 = std::stoi(matches[2].str());
            const int k = std::stoi(matches[3].str());
            std::cout << "Coordinates for the vertical parabola: h = "<< h << ". 4p = " << p4 << ", k = "<< k << "\n";
        }else if (matches[4].matched) {
            const int h = std::stoi(matches[1].str());
            const int p4 = std::stoi(matches[2].str());
            const int k = std::stoi(matches[3].str());
            std::cout << "Coordinates for the horizontal parabola: h = " << h <<" , 4p = " << p4 << ", k = " << k << "\n";
        }else {
            std::cerr << "Something's wrong with the provided equation!";
        }
    }
    // Tester tester;
    // tester.startEngine();
    return 0;
}

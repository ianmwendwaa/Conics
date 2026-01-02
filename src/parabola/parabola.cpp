#include "parabola.h"

#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <stack>

Parabola::Parabola() {
    formattedStr = inputAndFormatEquation();// f

    if(formattedStr.empty()){
        std::cerr << "ERROR: No equation was input!\n";
        exit(-1);
    }

    //find an instance of '=' to split the equation into left and right sides
    eqPos = formattedStr.find('=');
    if(eqPos == std::string::npos){
        std::cerr << "ERROR: No '=' found.\n";
    }

    const std::regex vertexRgx(R"(y=([+-]?\d*)\(x([+-]\d+)\)2([+-]\d+)| x=([+-]?\d*)\(y([+-]\d+)\)2([+-]\d+))");

    // regex for advanced geometry: (x-h)2 = 4p(y-k)/(y-k)2 = 4p(x-h)
    const std::regex conicRgx(R"(\(x([+-]\d+)\)2=([+-]?\d+)\(y([+-]\d+)\)|\(y([+-]\d+)\)2=([+-]?\d+)\(x([+-]\d+)\))");

    std::smatch matches;
    if (std::regex_match(formattedStr, matches, conicRgx)) {
        // if matches the vertical parabola
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
        if (!matches[1].matched && !matches[4].matched) {
            // if both don't match, try the normal one
            if (std::regex_match(formattedStr, matches, vertexRgx)) {

            }
        }
    }
}

std::string Parabola::inputAndFormatEquation(){
    std::string spacelessStr;

    std::cout << "Input equation of the parabola: ";
    if(std::string input; std::getline(std::cin, input)){
        std::string word;
        std::istringstream stream(input);
        while(stream >> word){
            spacelessStr += word;
        }
    }
    return spacelessStr;
}

int main() {
    std::map<char, std::string> binaryMap;
    binaryMap['A'] = "";
    if (constexpr char input = 'A'; binaryMap.count(input)) {
        std::cout << "Key found!";
    }else {
        std::cerr << "Element not found!";
    }
}



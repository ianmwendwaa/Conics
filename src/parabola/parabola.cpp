#include "parabola.h"

#include <iostream>
#include <string>
#include <sstream>

Parabola::Parabola() {}

std::string Parabola::fmtEquation(){
    std::string input;//stores value of input
    std::string word;
    std::string spacelessStr;

    std::cout << "Input equation of the parabola: ";
    if(std::getline(std::cin, input)){
        std::istringstream stream(input);
        while(stream >> word){
            spacelessStr += word;
        }
    }
    return spacelessStr;
}

bool Parabola::isXPos(const char* rightSide)
{
    if(*rightSide != '-'){
        isUpward = true;
    }else
        isUpward = false;

    return isUpward;
}

bool Parabola::isYPos(const char* rightSide)
{
    if(*rightSide != '-'){
        isRightward = true;
    }else
        isRightward = false;

    return isRightward;
}

int Parabola::p()
{
    if(m_rightSide.at(0) != '-'){
        m_p = std::atoi(&m_rightSide.at(0));
    }else{
        m_p = std::atoi(&m_rightSide.at(1));
    }
    return m_p/4;
}

std::pair<int, int> Parabola::foci(const int& f1, const int& f2)
{
    return std::make_pair(f1, f2);
}

void Parabola::parabolaOrientation(){
    formattedStr = fmtEquation();

    int eqPos = formattedStr.find("=");

    m_leftSide = formattedStr.substr(0, eqPos);
    m_rightSide = formattedStr.substr(eqPos + 1);

    // if equation begins with x and has a positive -> upwards else down
    // if it begins with y and has a positive -> right else left

    char firstChar = m_leftSide.at(0);// store the beginning of the left side

    if(firstChar == 'x'){
        if(isXPos(&m_rightSide.at(0))){
            std::cout << "Parabola is oriented upwards\n";

            // Focus will be equal to F(0,±p)
            f = foci(0, p());
            std::cout << "Focus: ("<< f.first<<"," << f.second << ")\n";
        }else{
            std::cout << "Parabola is oriented downwards\n";
            f = foci(0, -p());
            std::cout << "Focus: ("<< f.first<<"," << f.second << ")\n";
        }
    }

    if(firstChar == 'y'){
        if(isYPos(&m_rightSide.at(0))){
            std::cout << "Parabola is oriented rightwards\n";

            // Focus will now be equal to F(±p, 0)
            f = foci(p(), 0);
            std::cout << "Focus: ("<< f.first<<"," << f.second << ")\n";
        }else{
            std::cout << "Parabola is oriented leftwards\n";
            f = foci(-p(), 0);
            std::cout << "Focus: ("<< f.first<<"," << f.second << ")\n";
        }
    }
}

int Parabola::startEngine(){
    parabolaOrientation();
    return 0;
}


#include "tester.h"
#include <iostream>
#include <utility>
#include <sstream>
#include <string>

struct VertexProp{
    double a, h, k;
};

Tester::Tester() {
    formattedEquation = inputAndFormatEquation();

    //this should symbolize something like y=a(x+h)2+k / x=a(y-k)2+h..if not V is at 0,0;

    if(formattedEquation.empty()){
        std::cerr << "Error processing equation. Reason? No equation was provided!"<<std::endl;
        exit(-1);
    }

    //find the occurrence of the "=" sign
    eqPos = formattedEquation.find('=');
    if(eqPos == std::string::npos){//if no equals sign is found, throw an error
        std::cerr << "Error. Reason? No equals sign found. Double check your equation input!\n";
        exit(-1);
    }

    m_leftSide = formattedEquation.substr(0, eqPos);
    m_rightSide = formattedEquation.substr(eqPos+1);
}

std::string Tester::inputAndFormatEquation()
{
    std::string inputString;
    std::string spacelessString;
    std::string word;//temporary value to hold the spaceless string
    std::cout << "Enter equation of the parabola: ";
    if(std::getline(std::cin, inputString)){
        std::istringstream oss(inputString);
        while(oss >> word){
            spacelessString += word;
        }
    }
    return spacelessString;
}

void Tester::analysis()
{
    if(m_leftSide.at(0) == 'x'){
        calculationforXParabola();
    }
    if(m_leftSide.at(0) == 'y' || m_leftSide.at(0) == 'f'){
        calculationforYParabola();
    }
    if(m_leftSide.at(0) != 'x' && m_leftSide.at(0) != 'y' && m_leftSide.at(0) != 'f'){
        std::cerr << "Error! Unknown equation provided.\n"
                     " Please make sure your equation follows the format y=a(x+h)2+k or x = a(y-k)2+h";
        exit(-1);
    }

}

void Tester::calculationforXParabola()
{
    // obtain the value of a from the equation. Ordinarily, it's the first integer. But not in the case
    // of negative

    // to be more robust, I am thinking get the opening bracket's pos, and the equals position, and get that value
    int openingBrackets = m_rightSide.find('(');
    std::string pString = formattedEquation.substr(eqPos, openingBrackets);
    a = std::atoi(pString.c_str());

    //1. Calculating the focus
    // obtain the values of h and k first from the equation
    int closingBracket = m_rightSide.find(')');
    if(closingBracket == std::string::npos){
        std::cerr << "Error! Closing bracket not found. Please double check your equation.\n";
        exit(-1);
    }

    // determine whether k is positive or negative
    int yPos = m_rightSide.find('y');
    if(yPos == std::string::npos || closingBracket == std::string::npos){
        std::cerr << "Error! Missing variable in equation. Probably x or y\n";
        exit(-1);
    }
    char innerFuncOperator = m_rightSide.at(yPos + 1);
    if(innerFuncOperator == '-'){
        k = -k;
    }
    if(innerFuncOperator != '-' && innerFuncOperator != '+'){
        std::cerr << "Error! Missing variable in equation. Probably + or - in the inner function\n";
        exit(-1);
    }

    std::string kString = m_rightSide.substr(yPos + 2);
    k = std::atoi(kString.c_str());

    // finding h
    // x = a(y-k)2 + h
    int hPos = closingBracket+2;
    if(hPos < m_rightSide.length()){
        std::string hString = m_rightSide.substr(hPos);
        h = std::atoi(hString.c_str());
    }else{
        h = 0;
    }

    // determine whether h is positive or negative
    if(m_rightSide.substr(closingBracket + 1) == "-"){
        h = -h;
    }

    //vertex
    std::pair<int, int> vertex = std::make_pair(h,k);
    std::pair<double, double> focus = std::make_pair(h + (0.25*a), k);
    std::cout << "Focus: ("<<(focus.first) <<","<< (focus.second)<<")\n";

    // latus rectum - (-a, 0), length = 4a
    double latusRectumLength = 4*a;
    std::cout << "Length of latus rectum: "<<latusRectumLength;

}

void Tester::calculationforYParabola()
{

}

void Tester::startEngine()
{
    if(!formattedEquation.empty()){
        analysis();
    }
}


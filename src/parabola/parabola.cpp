#include "parabola.h"

#include <iostream>
#include <string>
#include <sstream>

Parabola::Parabola() {
    formattedStr = fmtEquation();// formatted equation to be used in all functions for arithmetics

    //find an instance of '=' to split the equation into left and right sides
    eqPos = formattedStr.find("=");

    // from the fmtEquation, assign the left and right sides for individual analysis and operations
    m_leftSide = formattedStr.substr(0, eqPos);
    m_rightSide = formattedStr.substr(eqPos + 1);

    // get the first character on the left side; determines the orientation horizontally or vertically
    firstChar = m_leftSide.at(0);
}

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

bool Parabola::isVertexAtO()
{

    return vertexIsAtO;
}

bool Parabola::isXPositive(const char *rightSide)
{
    if(*rightSide != '-'){
        isUpward = true;
    }else
        isUpward = false;

    return isUpward;
}

bool Parabola::isYPositive(const char *rightSide)
{
    if(*rightSide != '-'){
        isRightward = true;
    }else
        isRightward = false;

    return isRightward;
}

void Parabola::analyseParabola()
{
    //1. Ascertain the type of parabola and then apply the respective function
    if(firstChar == 'x'){
        xParabola();
    }

    if(firstChar == 'y'){
        yParabola();
    }

    if(firstChar == '('){
        firstChar = m_leftSide.at(1);
        // check if it is x or y
        if(firstChar == 'x'){
            xParabola();
        }

        if(firstChar == 'y'){
            yParabola();
        }
    }

    //2. Determine whether the vertex is at V(0,0) or V(h,k)
    //find the occurence of v to obtain the coordinates of the vertex
    int vPos = formattedStr.find("v");

    std::string vStr = formattedStr.substr(vPos + 1);// to move right from 'v' i.e: '(h,k)'

    // parse further to obtain first and second values from the coordinates v(h,k)
    int bPos = vStr.find("(");// occurrence of the first bracket
    int cPos = vStr.find(",");// occurrence of the comma separator

    std::string rawCoordinates = vStr.substr(bPos + 1);// 'h, k)'

    xV = std::atoi(&rawCoordinates.at(0));

    std::string kStr =vStr.substr(cPos + 1);// i.e: 'k)'
    yV = std::atoi(&kStr.at(0));

    auto vCoordinates = std::make_pair(xV, yV);// pair them up to make the vertex coordinates

    if(vCoordinates.first == 0 && vCoordinates.second == 0){
        vertexIsAtO = true;//if V(0,0), it's at the origin
    }else{
        vertexIsAtO = false;//if V ≠ (0,0), it's somewhere else on the Cartesian plane
    }
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

int Parabola::directrix()
{
    return 0;
}

int Parabola::latusRectumLen()
{
    return 4 * p();
}

std::pair<int, int> Parabola::foci(const int& f1, const int& f2)
{
    return std::make_pair(f1, f2);
}

void Parabola::xParabola(){
    // checking if the first occurrence of char is not '-'
    if(isXPositive(&m_rightSide.at(0))){
        //if so, parabola is oriented upwards applying
        std::cout << "Parabola is oriented upwards\n";

        // check position of the vertex to ascertain what foci formula to apply
        if(!vertexIsAtO){
            // equation will be given by: (x-h)² = 4p(y-k)
            // focus will then be V(h, k+p)

            //so first, obtain the values of h and k:
            // 1. h - it will always be at the 3rd index, but first, check if its predecessor is - or +
            char hStr = m_leftSide.at(3);
            h = std::atoi(&hStr);
            if(m_leftSide.at(2) != '-'){
                h = -h;// apply a negative to it since it would make the symbol on the equation positive
                // eg. (x+2)² would make h = -2, comparing it to the formula.
            }
            // for the right side, getting k will be a little different since 4p could be negative
            // 1. check if 4p is negative
            if(m_rightSide.at(0) == '-'){
                char fP = m_rightSide.at(1);//get the string int next to it
                //since it is negative, apply a negative sign to it
                m_p = -(std::atoi(&fP));

                //obtain the value of k from the string
                char kStr = m_rightSide.at(5);
                k = std::atoi(&kStr);
                //check if its predecessor is + or -
                if(m_rightSide.at(4) != '-'){
                    k = -k;
                }
            }
            std::cout << "Vertex will be at: ("<<h <<"," <<k<<"\n";

        }else if(vertexIsAtO){
            //if it is at the origin,
            f = foci(0, p());
            std::cout << "Focus: ("<< f.first<<"," << f.second << ")\n";
        }
        else{
            std::cerr << "Calculation failed.";
        }



        // Focus will be equal to F(0,±p)

    }else{
        std::cout << "Parabola is oriented downwards\n";
        f = foci(0, -p());
        std::cout << "Focus: ("<< f.first<<"," << f.second << ")\n";
    }
}

void Parabola::yParabola(){
    if(isYPositive(&m_rightSide.at(0))){
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

void Parabola::drawParabola()
{
    // y and x represent the corresponding axes
    std::cout << "^" << std::endl;
    for(int y = 0; y < 8; y++){
        std::cout << "|"<< std::endl;
        if(y == 6){
            for(int x = 0; x < 21; x++){
                std::cout << "-";
                if(x == 20){
                    std::cout << ">";
                }
            }
        }
    }
}

int Parabola::startEngine(){
    fmtEquation();
    return 0;
}


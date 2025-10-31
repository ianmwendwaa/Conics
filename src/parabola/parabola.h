#ifndef PARABOLA_H
#define PARABOLA_H

#include <utility>
#include <string>

// A parabola can either curve to the left or right, or up or down  depending on the equation.
class Parabola
{
public:
    Parabola();
    std::string fmtEquation();// formats the equation
    bool isVertexAtO();// assesses position of vertex and applies respective methods
    bool isXPos(const char* rightSide);
    bool isYPos(const char* rightSide);

    void xParabola();
    void yParabola();
    int p();// returns the value of p
    std::pair<int, int> foci(const int& f1, const int& f2);
    void parabolaOrientation();// ascertains orientation

    int startEngine();// commences parabola operations

private:
    std::string formattedStr;// stores the fmtd eqtn string
    std::string m_leftSide;// stores values on the left side
    std::string m_rightSide;// stores values on the right side
    char firstChar;// stores value of the first character in either side

    int eqPos = 0;

    //Booleans to ascertain orientation of the parabola
    bool isUpward;
    bool isRightward;

    bool vertexIsAtO;

    int h,k;

    std::pair<int, int> f; // stores coordinates of the focus

    int m_p;// obtains the value 4p


};

#endif // PARABOLA_H

#ifndef PARABOLA_H
#define PARABOLA_H

#include <utility>
#include <string>

// A parabola can either curve to the left or right, or up or down  depending on the equation.
class Parabola
{
public:
    Parabola();
    std::string inputAndFormatEqtn();// formats the equation
    bool isVertexAtOrigin();// assesses position of vertex and applies respective methods
    bool isParabolaPositive(const std::string& rightSide);// checks if the parabola is positive

    void analyseParabola();

    void xParabola();
    void yParabola();
    int calculateP();// returns the value of p
    int directrix();// returns the c value of directrix
    int latusRectumLen();// returns the length of latus rectum
    std::pair<int, int> foci(const int& f1, const int& f2);
    void drawParabola();// draws a simple parabola on the terminal

    int startEngine();// commences parabola operations

private:
    std::string formattedStr;// stores the fmtd eqtn string
    std::string m_leftSide;// stores values on the left side
    std::string m_rightSide;// stores values on the right side
    char firstChar;// stores value of the first character in either side

    int eqPos = 0;

    // ascertaining orientation of the parabola
    bool isUpward;
    bool isRightward;

    bool vertexIsAtO;

    int xV,yV;
    int h, k;

    std::pair<int, int> f; // stores coordinates of the focus

    int m_p;// obtains the value 4p


};

#endif // PARABOLA_H

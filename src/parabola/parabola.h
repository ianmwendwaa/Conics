#ifndef PARABOLA_H
#define PARABOLA_H

#include <utility>
#include <string>

// A parabola can either curve to the left or right, or up or down  depending on the equation.
class Parabola
{
public:
    Parabola();
    static std::string inputAndFormatEquation();// formats the equation


private:
    std::string formattedStr;// stores the fmtd eqtn string
    std::string m_leftSide;// stores values on the left side
    std::string m_rightSide;// stores values on the right side

    int eqPos = 0;

};

#endif // PARABOLA_H

#ifndef TESTER_H
#define TESTER_H

#include <string>

class Tester
{
public:
    Tester();

    static std::string inputAndFormatEquation();
    void analysis();
    void calculationforXParabola();
    void calculationforYParabola();
    void startEngine();
private:
    std::string formattedEquation;
    std::string m_leftSide;
    std::string m_rightSide;
    int eqPos;
    double a{}, h{}, k{};
    bool isPositive{};
};

#endif // TESTER_H

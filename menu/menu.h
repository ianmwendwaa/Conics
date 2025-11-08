#ifndef MENU_H
#define MENU_H

#include <src/parabola/parabola.h>
#include <src/hyperbola/hyperbola.h>
#include <iostream>
#include <string>

class Menu{
private:
    Parabola parabola;
    Hyperbola hyperbola;
    void conics();
    void linearAlgebra();
    void calculus();
    void chemistry();
    bool isRunning;

public:
    Menu();
    void print(const std::string& message){
        std::cout << message << "\n";
    }
    void showMenu();
};

#endif // MENU_H

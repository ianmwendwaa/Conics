#ifndef MENU_H
#define MENU_H

#include <src/parabola/parabola.h>
#include <iostream>
#include <string>

class Menu{
public:
    Menu(){}
    void print(const std::string& message){
        std::cout << message << "\n";
    }
    void showMenu(){
        Parabola parabola;

        bool isRunning = true;

        while(isRunning){
            std::cout << "Welcome to Chelate Math Tutor!"<<std::endl;
            print("1. Conics (parabola, hyperbola, ellipses)");
            print("2. Linear algebra (Gauss Seidel, Eigen vectors)");
            print("3. Calculus");
            print("4. Chemistry?");
            print("5. Exit");
            std::cout << "Enter what topic you want me to solve: ";
            std::string choice;
            std::cin >> choice;

            int input = std::stoi(choice);

            switch(input){
            case 1:
                parabola.fmtEquation();
                break;
            case 2:
                print("Coming soon!");
                break;
            case 3:
                print("Coming soon!");
                break;
            case 4:
                print("Coming soon!");
                break;
            case 5:
                isRunning = false;
                print("See you soon!");
                break;
        }

        }
    }

};

#endif // MENU_H


// Menu::Menu(){
//     isRunning = true;
// }

// void Menu::conics(){

//     print("Select topic under conics:");
//     print("1. Parabola");
//     print("2. Hyperbola");
//     print("3. Ellipses");
//     print("4. Go back");
//     print("I choose: ");

//     std::string conics_choice;
//     std::cin >> conics_choice;

//     switch(std::stoi(conics_choice)){
//     case 1:
//         parabola.startEngine();
//         isRunning = false;
//         break;
//     case 2:
//         print("**Coming soon**");
//         isRunning = false;
//         break;
//     case 3:
//         print("**Coming soon**");
//         isRunning = false;
//         break;
//     case 4:
//         showMenu();
//         isRunning = false;
//         break;
//     }


//     parabola.startEngine();
// }

// void Menu::showMenu(){
//     while(isRunning){
//         std::cout << "Welcome to Chelate Math Tutor!"<<std::endl;
//         print("1. Conics (parabola, hyperbola, ellipses)");
//         print("2. Linear algebra (Gauss Seidel, Eigen vectors)");
//         print("3. Calculus");
//         print("4. Chemistry?");
//         print("5. Exit");
//         std::cout << "Enter what topic you want me to solve: ";
//         std::string choice;
//         std::cin >> choice;

//         int input = std::stoi(choice);

//         switch(input){
//         case 1:
//             conics();
//             isRunning = false;
//             break;
//         case 2:
//             print("**Coming soon!**");
//             break;
//         case 3:
//             print("**Coming soon!**");
//             break;
//         case 4:
//             print("**Coming soon!**");
//             break;
//         case 5:
//             isRunning = false;
//             print("See you soon!");
//             break;
//         }
//     }
// }


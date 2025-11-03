#include <src/parabola/parabola.h>
#include <menu/menu.h>

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Parabola p;
    Menu menu;
    menu.showMenu();
    // p.drawParabola();
    return a.exec();
}

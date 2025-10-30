#include <src/parabola/parabola.h>

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parabola p;
    p.startEngine();
    return a.exec();
}

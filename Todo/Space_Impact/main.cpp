#include "mainwindow.h"
#include "inicio.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();

    Inicio i;
    i.show();
    return a.exec();
}

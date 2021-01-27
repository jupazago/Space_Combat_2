#include "mainwindow.h"
#include "inicio.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    Inicio i;
    i.show();
    //w.show();
    return a.exec();
}

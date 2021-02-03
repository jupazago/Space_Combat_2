#ifndef INICIO_JUEGO_MENU_H
#define INICIO_JUEGO_MENU_H

#include <QWidget>
#include <mainwindow.h>
#include <inicio.h>

namespace Ui {
class Inicio_juego_menu;
}

class Inicio_juego_menu : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio_juego_menu(QWidget *parent = nullptr);
    ~Inicio_juego_menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Inicio_juego_menu *ui;
    Inicio *principal;
    MainWindow *juego;
};

#endif // INICIO_JUEGO_MENU_H

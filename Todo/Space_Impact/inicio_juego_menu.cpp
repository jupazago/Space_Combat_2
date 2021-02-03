#include "inicio_juego_menu.h"
#include "ui_inicio_juego_menu.h"

Inicio_juego_menu::Inicio_juego_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio_juego_menu)
{
    ui->setupUi(this);
}

Inicio_juego_menu::~Inicio_juego_menu()
{
    delete ui;
}

void Inicio_juego_menu::on_pushButton_clicked()
{
    principal = new Inicio();
    juego = new MainWindow();

    principal->show();
    juego->close();
    this->close();
}

#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/recursos/fondo_inicio.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    formulario_inicio = new Inicio_juego_nuevo();
    formulario_cargar = new inicio_juego_cargar();
    formulario_eliminar = new Inicio_juego_eliminar();
    formulario_reiniciar = new Inicio_juego_reiniciar();
}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_btn_nuevo_clicked()
{
    formulario_inicio->show();
    //this->hide();
}

void Inicio::on_btn_cargar_clicked()
{
    formulario_cargar->show();
    //this->hide();
}

void Inicio::on_btn_eliminar_clicked()
{
    formulario_eliminar->show();
    //this->hide();
}

void Inicio::on_btn_reiniciar_clicked()
{
    formulario_reiniciar->show();
    //this->hide();
}

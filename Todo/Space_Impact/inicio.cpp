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

}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_btn_nuevo_clicked()
{
    this->hide();
    formulario_inicio.show();
}

void Inicio::on_btn_cargar_clicked()
{
    this->hide();
}

void Inicio::on_btn_eliminar_clicked()
{
    this->hide();
}

void Inicio::on_pushButton_4_clicked()
{
    this->hide();
}

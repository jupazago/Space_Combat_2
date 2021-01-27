#include "inicio_juego_nuevo.h"
#include "ui_inicio_juego_nuevo.h"

Inicio_juego_nuevo::Inicio_juego_nuevo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio_juego_nuevo)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/recursos/fondo_inicio.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Inicio_juego_nuevo::~Inicio_juego_nuevo()
{
    delete ui;
}


void Inicio_juego_nuevo::on_btn_crear_clicked()
{
    string usuario = ui->le_usuario->text().toStdString();
    string clave   = ui->le_usuario->text().toStdString();

    jugador = new Jugador(usuario, clave);
    jugador->crear_nuevo();

    this->close();
}

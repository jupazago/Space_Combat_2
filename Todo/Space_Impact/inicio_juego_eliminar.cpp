#include "inicio_juego_eliminar.h"
#include "ui_inicio_juego_eliminar.h"

Inicio_juego_eliminar::Inicio_juego_eliminar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio_juego_eliminar)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/recursos/fondo_pregunta.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Inicio_juego_eliminar::~Inicio_juego_eliminar()
{
    delete ui;
}

void Inicio_juego_eliminar::on_btn_eliminar_clicked()
{
    string usuario = ui->le_usuario->text().toStdString();
    string clave   = ui->le_clave->text().toStdString();

    jugador = new Jugador(usuario, clave);

    if(jugador->eliminar() == true){
        QMessageBox::information(this, "Informacion", "Registro eliminado");

        this->close();
    }else{
        QMessageBox::information(this, "Informacion", "Usuario no disponible");
    }
}

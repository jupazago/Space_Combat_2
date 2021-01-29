#include "inicio_juego_reiniciar.h"
#include "ui_inicio_juego_reiniciar.h"

Inicio_juego_reiniciar::Inicio_juego_reiniciar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio_juego_reiniciar)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/recursos/fondo_pregunta.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Inicio_juego_reiniciar::~Inicio_juego_reiniciar()
{
    delete ui;
}

void Inicio_juego_reiniciar::on_btn_crear_clicked()
{
    string usuario = ui->le_usuario->text().toStdString();
    string clave   = ui->le_clave->text().toStdString();

    jugador = new Jugador(usuario, clave);

    if(jugador->reiniciar() == true){
        QMessageBox::information(this, "Informacion", "Registro Restaurado");
        //this->close();
    }else{
        QMessageBox::information(this, "Informacion", "Usuario no disponible");
    }
}

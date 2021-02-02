#include "inicio_juego_nuevo.h"
#include "ui_inicio_juego_nuevo.h"

Inicio_juego_nuevo::Inicio_juego_nuevo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio_juego_nuevo)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/recursos/fondo_pregunta.jpg");
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
    string clave   = ui->le_clave->text().toStdString();

    jugador = new Jugador(usuario, clave);

    if(jugador->crear_nuevo() == true){

        this->hide();

        juego = new MainWindow();
        juego->show();
        juego->iniciar(usuario, clave);
    }else{
        QMessageBox::information(this, "Informacion", "Usuario no disponible");
    }


}

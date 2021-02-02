#include "inicio_juego_cargar.h"
#include "ui_inicio_juego_cargar.h"

inicio_juego_cargar::inicio_juego_cargar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inicio_juego_cargar)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/recursos/fondo_pregunta.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

inicio_juego_cargar::~inicio_juego_cargar()
{
    delete ui;
}

void inicio_juego_cargar::on_btn_cargar_clicked()
{
    string usuario = ui->le_usuario->text().toStdString();
    string clave   = ui->le_clave->text().toStdString();

    jugador = new Jugador(usuario, clave);

    if(jugador->cargar() == true){

        this->hide();

        juego = new MainWindow();
        juego->show();
        juego->iniciar(usuario, clave);

    }else{
        QMessageBox::information(this, "Informacion", "Resgistro incorrecto o no existe");
    }
}

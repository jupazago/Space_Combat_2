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

    timer_instructivo = new QTimer();
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

        connect(timer_instructivo, SIGNAL(timeout()), this, SLOT(empezar()));
        timer_instructivo->start(10000);

        QPixmap bkgndd(":/recursos/instructivo.jpg");
        bkgndd = bkgndd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palettee;
        palettee.setBrush(QPalette::Background, bkgndd);
        this->setPalette(palettee);


        ui->btn_crear->hide();
        ui->le_clave->hide();
        ui->le_usuario->hide();
    }else{
        QMessageBox::information(this, "Informacion", "Usuario no disponible");
    }


}

void Inicio_juego_nuevo::empezar()
{
    //ejecutar juego

    string usuario = ui->le_usuario->text().toStdString();
    string clave   = ui->le_clave->text().toStdString();

    timer_instructivo->stop();
    this->close();
    juego = new MainWindow();
    juego->show();
    juego->iniciar(usuario, clave);
}

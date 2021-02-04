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

    timer_instructivo = new QTimer();
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

        connect(timer_instructivo, SIGNAL(timeout()), this, SLOT(empezar()));
        timer_instructivo->start(10000);

        QPixmap bkgndd(":/recursos/instructivo.jpg");
        bkgndd = bkgndd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palettee;
        palettee.setBrush(QPalette::Background, bkgndd);
        this->setPalette(palettee);


        ui->btn_cargar->hide();
        ui->le_clave->hide();
        ui->le_usuario->hide();

    }else{
        QMessageBox::information(this, "Informacion", "Resgistro incorrecto o no existe");
    }
}

void inicio_juego_cargar::empezar()
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

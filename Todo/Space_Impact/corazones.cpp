#include "corazones.h"

int Corazones::getPosx() const
{
    return posx;
}

void Corazones::setPosx(int value)
{
    posx = value;
}

int Corazones::getPosy() const
{
    return posy;
}

void Corazones::setPosy(int value)
{
    posy = value;
}

Corazones::Corazones(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    posx = 170;
    posy = 50;

    setPos(posx, posy);


    pixmap = new QPixmap(":/recursos/vidas.png");

    //dimensiones de cada imagen
    ancho = 358;
    alto = 81;

    Actualizacion(3);
    /*
    timer->start(50);
    connect(timer, &QTimer::timeout, this, &Corazones::Actualizacion);
    */
}

void Corazones::Actualizacion(int n)
{
    switch(n)
    {
        case 1: columnas = 0;
        break;

        case 2: columnas = 358;
        break;

        case 3: columnas = 358*2;
        break;

        default: pixmap = new QPixmap(":/recursos/amongus2.png");
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Corazones::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Corazones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

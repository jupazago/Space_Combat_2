#include "enemigo.h"

int Enemigo::getPosx() const
{
    return posx;
}

void Enemigo::setPosx(int value)
{
    posx = value;
}

int Enemigo::getPosy() const
{
    return posy;
}

void Enemigo::setPosy(int value)
{
    posy = value;
}

int Enemigo::getVel() const
{
    return vel;
}

void Enemigo::setVel(int value)
{
    vel = value;
}

Enemigo::Enemigo(int posx_, int posy_, int nivel, QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    posx = posx_;
    posy = posy_;
    vel = 3;
    setPos(posx, posy);

    switch(nivel)
    {
        case 1: pixmap = new QPixmap(":/recursos/enemigo1.png");
        break;

        case 2: pixmap = new QPixmap(":/recursos/amongus2.png");
        break;

        case 3: pixmap = new QPixmap(":/recursos/amongus2.png");
        break;

        default: pixmap = new QPixmap(":/recursos/amongus2.png");
    }



    //dimensiones de cada imagen
    ancho = 160;
    alto = 100;

    timer->start(50);
    connect(timer, &QTimer::timeout, this, &Enemigo::Actualizacion);
}

void Enemigo::Actualizacion()
{
    columnas += 160;
    if(columnas >= 960){
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Enemigo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void Enemigo::Move()
{
    posx-=2*vel;
    setPos(posx,posy);

}



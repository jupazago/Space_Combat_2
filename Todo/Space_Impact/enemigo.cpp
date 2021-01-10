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

int Enemigo::getSalud() const
{
    return salud;
}

void Enemigo::setSalud(int value)
{
    salud = value;
}

Enemigo::Enemigo(int posx_, int posy_, int nivel, QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    posx = posx_;
    posy = posy_;
    vel = 3;
    salud = nivel;
    setPos(posx, posy);

    pixmap = new QPixmap(":/recursos/enemigo1.png");

    switch(nivel)
    {
        case 1: filas=0;
        break;

        case 2: filas=100;
        break;

        case 3: filas=200;
        break;

        case 4: filas=300;
        break;

        case 5: filas=400;
        break;

        default: filas=100;
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
        columnas = 0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Enemigo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void Enemigo::Move()
{
    posx-=2*vel;
    setPos(posx,posy);

}



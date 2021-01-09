#include "jefe.h"

int Jefe::getPosx() const
{
    return posx;
}

void Jefe::setPosx(int value)
{
    posx = value;
}

int Jefe::getPosy() const
{
    return posy;
}

void Jefe::setPosy(int value)
{
    posy = value;
}

int Jefe::getVel() const
{
    return vel;
}

void Jefe::setVel(int value)
{
    vel = value;
}

int Jefe::getSalud() const
{
    return salud;
}

void Jefe::setSalud(int value)
{
    salud = value;
}

Jefe::Jefe(int posx_, int posy_, int nivel, QObject *parent) : QObject(parent)
{
    
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    posx = posx_;
    posy = posy_;
    vel = 2;
    salud = 100*nivel;
    setPos(posx, posy);

    switch(nivel)
    {
        case 1: pixmap = new QPixmap(":/recursos/jefe1.png");
        break;

        case 2: pixmap = new QPixmap(":/recursos/jefe1.png");
        break;

        case 3: pixmap = new QPixmap(":/recursos/jefe1.png");
        break;

        default: pixmap = new QPixmap(":/recursos/jefe1.png");
    }



    //dimensiones de cada imagen
    ancho = 240;
    alto = 300;

    timer->start(50);
    connect(timer, &QTimer::timeout, this, &Jefe::Actualizacion);
}

void Jefe::Actualizacion()
{
    columnas += 240;
    if(columnas >= 2880){
        columnas = 0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Jefe::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Jefe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void Jefe::MoveUp()
{
    posy-=2*vel;
    setPos(posx,posy);

}

void Jefe::MoveDown()
{
    posy+=2*vel;
    setPos(posx,posy);
}

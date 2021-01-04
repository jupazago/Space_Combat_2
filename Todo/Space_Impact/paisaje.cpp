#include "paisaje.h"

Paisaje::Paisaje(int posx_, int posy_, int figura, QObject *parent) : QObject(parent)
{

    posx = posx_;
    posy = posy_;
    vel = 2;
    setPos(posx, posy);

    //dimensiones de cada imagen
    ancho = 1000;
    alto = 300;

    filas = 0;
    columnas = 0;


    switch(figura)
    {
        case 1: pixmap = new QPixmap(":/recursos/paisaje1.png");
        break;

        case 2: pixmap = new QPixmap(":/recursos/paisaje2.png");
        break;

        case 3: pixmap = new QPixmap(":/recursos/paisaje3.png");
        break;

        case 4: pixmap = new QPixmap(":/recursos/paisaje4.png");
        break;

        case 5: pixmap = new QPixmap(":/recursos/paisaje5.png");
        break;

        case 6: pixmap = new QPixmap(":/recursos/fondo_lvl1.png");
        break;


        default: pixmap = new QPixmap(":/recursos/paisaje1.png");
    }
}


QRectF Paisaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Paisaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void Paisaje::Move()
{
    posx-=2*vel;
    setPos(posx,posy);

}

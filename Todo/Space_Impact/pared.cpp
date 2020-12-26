#include "pared.h"

int Pared::getPosx() const
{
    return posx;
}

void Pared::setPosx(int value)
{
    posx = value;
}

int Pared::getPosy() const
{
    return posy;
}

void Pared::setPosy(int value)
{
    posy = value;
}

int Pared::getW() const
{
    return w;
}

void Pared::setW(int value)
{
    w = value;
}

int Pared::getH() const
{
    return h;
}

void Pared::setH(int value)
{
    h = value;
}

QRectF Pared::boundingRect() const
{
    return QRect(posx,posy,w,h);
}

void Pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
    //proceso para que las paredes sean graficables en la escena
}

Pared::Pared()
{

}

Pared::Pared(int x, int y, int w_, int h_)
{
    posx =x;
    posy =y;
    w=w_;
    h=h_;
}

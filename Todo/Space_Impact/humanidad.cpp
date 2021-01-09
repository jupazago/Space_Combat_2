#include "humanidad.h"

int Humanidad::getPosx() const
{
    return posx;
}

void Humanidad::setPosx(int value)
{
    posx = value;
}

int Humanidad::getPosy() const
{
    return posy;
}

void Humanidad::setPosy(int value)
{
    posy = value;
}

int Humanidad::getVel() const
{
    return vel;
}

void Humanidad::setVel(int value)
{
    vel = value;
}

bool Humanidad::getExiste() const
{
    return existe;
}

void Humanidad::setExiste(bool value)
{
    existe = value;
}

Humanidad::Humanidad(QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    posx = 40;
    posy = 300;
    vel = 5;
    existe = true;
    setPos(posx, posy);

    pixmap = new QPixmap(":/recursos/amongus.png");

    //dimensiones de cada imagen
    ancho = 80;
    alto = 100;

    timer->start(50);
    connect(timer, &QTimer::timeout, this, &Humanidad::Actualizacion);


}

void Humanidad::Actualizacion()
{
    columnas += 80;
    if(columnas >= 960){
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Humanidad::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Humanidad::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void Humanidad::MoveUp()
{
    posy-=2*vel;
    setPos(posx,posy);

}

void Humanidad::MoveDown()
{
    posy+=2*vel;
    setPos(posx,posy);
}

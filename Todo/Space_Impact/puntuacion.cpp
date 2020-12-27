#include "puntuacion.h"
#include <QFont>

int Puntuacion::getPuntos() const
{
    return puntos;
}

Puntuacion::Puntuacion(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    puntos = 0;
    setPlainText(QString::number(puntos));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",50));
    setPos(800,0);
}

void Puntuacion::incrementar(int puntos_)
{
    puntos = puntos_;
    setPlainText(QString::number(puntos));
}

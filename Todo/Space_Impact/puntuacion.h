#ifndef PUNTUACION_H
#define PUNTUACION_H


#include <QGraphicsTextItem>

class Puntuacion: public QGraphicsTextItem
{
    int puntos;
public:
    Puntuacion(QGraphicsItem * parent = 0);
    void incrementar(int puntos_);

    int getPuntos() const;
};

#endif // PUNTUACION_H

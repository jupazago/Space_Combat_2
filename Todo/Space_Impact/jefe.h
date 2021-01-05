#ifndef JEFE_H
#define JEFE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Jefe : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int posx;
    int posy;
    int vel;

public:
    explicit Jefe(int posx_, int posy_n, int nivel, QObject *parent = nullptr);

    QTimer * timer;
    QPixmap *pixmap;

    float filas, columnas;
    float ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosx() const;
    void setPosx(int value);

    int getPosy() const;
    void setPosy(int value);

    int getVel() const;
    void setVel(int value);

signals:

public slots:
    void Actualizacion();
};

#endif // JEFE_H
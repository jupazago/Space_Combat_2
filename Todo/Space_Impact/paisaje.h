#ifndef PAISAJE_H
#define PAISAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Paisaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int posx;
    int posy;
    int vel;
public:
    explicit Paisaje(int posx_, int posy_n, int figura, QObject *parent = nullptr);

    void Move();
    QPixmap *pixmap;

    float filas, columnas;
    float ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PAISAJE_H

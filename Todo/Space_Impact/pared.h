#ifndef PARED_H
#define PARED_H
#include <QGraphicsItem> //para que sea un elemento graficable
#include <QPainter>


class Pared:public QGraphicsItem //para que sea grafico
{
    int posx;
    int posy;
    int w;
    int h;
public:
    Pared();
    Pared(int x, int y, int w_, int h_);
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
    int getW() const;
    void setW(int value);
    int getH() const;
    void setH(int value);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PARED_H

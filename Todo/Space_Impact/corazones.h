#ifndef CORAZONES_H
#define CORAZONES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Corazones : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int posx;
    int posy;
public:
    explicit Corazones(QObject *parent = nullptr);

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

signals:

public slots:
    void Actualizacion(int n);

};

#endif // CORAZONES_H

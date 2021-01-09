#ifndef HUMANIDAD_H
#define HUMANIDAD_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Humanidad : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int posx;
    int posy;
    int vel;
    bool existe;
public:
    explicit Humanidad(QObject *parent = nullptr);

    void MoveUp();
    void MoveDown();

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

    bool getExiste() const;
    void setExiste(bool value);

signals:

public slots:
    void Actualizacion();

};

#endif // HUMANIDAD_H

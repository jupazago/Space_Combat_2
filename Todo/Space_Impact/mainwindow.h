#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <string>
#include <humanidad.h>
#include <jugador.h>
#include <misil.h>
#include <QList>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Mover();

private:
    Ui::MainWindow *ui;

    //Escena
    QGraphicsScene *scene;
    float x,y,ancho,alto;

    //Nave
    Humanidad *humanos;

    //Misiles
    QTimer *timer_misiles;
    Misil *cuerpo;
    QList<Misil*> misiles;

    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H

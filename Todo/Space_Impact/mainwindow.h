#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <string>
#include <humanidad.h>
#include <jugador.h>
#include <misil.h>
#include <enemigo.h>
#include <pared.h>
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
    void MoverEnemigo();

private:
    Ui::MainWindow *ui;

    //Escena
    QGraphicsScene *scene;
    float x,y,ancho,alto;

    //Nave
    Humanidad *humanos;

    //jugador
    Jugador *jugador;

    //Misiles
    QTimer *timer_misiles;
    QList<Misil*> misiles;

    //Enemigo
    QTimer *timer_enemigo;
    QList<Enemigo*> enemigos;

    //pared
    QList<Pared *> paredes;
    Pared *eliminacion_humana;
    Pared *eliminacion_enemiga;

    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H

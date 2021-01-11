#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <humanidad.h>
#include <jugador.h>
#include <misil.h>
#include <enemigo.h>
#include <pared.h>
#include <paisaje.h>
#include <jefe.h>

#include <math.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <string>
#include <QList>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <windows.h>
#include <QDesktopWidget>
#include <stdlib.h>     /* srand, rand */


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
    void nivel();

    void Limpiar_y_Detener();

    void invocarJefe();
    void verificarChoques();
    void verificarChoquesVsJefe();
    void DisparoJefe();

    void Mover();
    void Mover2();

    void MoverEnemigo();
    void MoverPaisaje();

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

    QTimer *timer_proyectiles;
    QList<Misil*> proyectiles;


    //choques
    QTimer *timer_choques;

    //Enemigo
    QTimer *timer_enemigo;
    QList<Enemigo*> enemigos;

    //jefe
    QTimer *timer_jefe;
    QTimer *timer_jefeVsMisiles;
    QTimer *timer_jefeDisparo;
    Jefe *jefe;
    int coord = 50;

    //pared
    QList<Pared *> paredes;
    Pared *eliminacion_humana;
    Pared *eliminacion_enemiga;

    //Paisajes - Nubes
    QList<Paisaje *> nubes;

    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H

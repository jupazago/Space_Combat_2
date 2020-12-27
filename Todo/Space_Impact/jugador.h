#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <QFile>        //Lectura y escritura de archivo
#include <QMessageBox>  //Mensaje
#include <vector>
#include <corazones.h>
#include <puntuacion.h>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

using namespace std;


class Jugador
{
    string usuario;
    int clave;
    int nivel;
    int vidas;
    Corazones *corazones;
    Puntuacion *puntuacion;
    int puntos;

public:
    //Constructores
    Jugador();
    Jugador(string usuario_, int clave_);
    Jugador(string usuario_, int clave_,int vidas_, int nivel_, int puntos_);

    //Set y get
    string getUsuario() const;
    void setUsuario(const string &value);
    int getClave() const;
    void setClave(int value);
    int getNivel() const;
    void setNivel(int value);
    int getVidas() const;
    void setVidas(int value);
    int getPuntos() const;
    void setPuntos(int value);

    //Metodos
    void crear_nuevo();
    void cargar(string usuario_, int clave_);
    void guardar();
    void reiniciar();
    void eliminar();

    Corazones *graficar_vida();
    void eliminar_Corazon();

    Puntuacion *crear_puntos();
    void incrementar_puntos(int valor);
};

#endif // JUGADOR_H

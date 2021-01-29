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
    string clave;
    int nivel;
    int vidas;
    Corazones *corazones;
    Puntuacion *puntuacion;
    int puntos;

public:
    //Constructores
    Jugador();
    Jugador(string usuario_, string clave_);
    Jugador(string usuario_, string clave_,int vidas_, int nivel_, int puntos_);

    //Set y get
    string getUsuario() const;
    void setUsuario(const string &value);
    string getClave() const;
    void setClave(const string &value);
    int getNivel() const;
    void setNivel(int value);
    int getVidas() const;
    void setVidas(int value);
    int getPuntos() const;
    void setPuntos(int value);

    //Metodos
    bool crear_nuevo();
    bool cargar();
    bool guardar();
    bool reiniciar();
    bool eliminar();
    bool existe_registro();

    Corazones *graficar_vida();
    void eliminar_Corazon();

    Puntuacion *crear_puntos();
    void incrementar_puntos(int valor);

    void subir_nivel();

};

#endif // JUGADOR_H

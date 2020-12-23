#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <QFile>        //Lectura y escritura de archivo
#include <QMessageBox>  //Mensaje
#include <vector>
using namespace std;


class Jugador
{
    string usuario;
    int clave;
    int nivel;

public:
    //Constructores
    Jugador();
    Jugador(string usuario_, int clave_, int nivel_);

    //Set y get
    string getUsuario() const;
    void setUsuario(const string &value);
    int getClave() const;
    void setClave(int value);
    int getNivel() const;
    void setNivel(int value);

    //Metodos
    void crear_nuevo();
    void cargar(string usuario_, int clave_);
    void guardar();
    void reiniciar();
    void eliminar();
};

#endif // JUGADOR_H

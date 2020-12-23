#include "jugador.h"
#include <QString>
#include <QMessageBox>  //Mensaje
#include <QTextStream>

int Jugador::getClave() const
{
    return clave;
}

void Jugador::setClave(int value)
{
    clave = value;
}

Jugador::Jugador()
{
    usuario = "user";
    clave = 1;
    nivel = 0;
}

Jugador::Jugador(string usuario_, int clave_, int nivel_)
{
    usuario = usuario_;
    clave = clave_;
    nivel = nivel_;
}

string Jugador::getUsuario() const
{
    return usuario;
}

void Jugador::setUsuario(const string &value)
{
    usuario = value;
}

int Jugador::getNivel() const
{
    return nivel;
}

void Jugador::setNivel(int value)
{
    nivel = value;
}

void Jugador::crear_nuevo()
{
    //Crear el flujo escritura desde un archivo
    QFile archivo("/recursos/data_base.txt");
    if(!archivo.open(QIODevice::WriteOnly | QIODevice::Append)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
    }

    //Guardamos el nuevo usuario
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Append)){
        QTextStream out(&archivo);
        QString texto = "\n" + QString::fromStdString(usuario) + " " + QString::number(clave) + " " + QString::number(nivel);
        out << texto;
        archivo.close();
    }



}

void Jugador::cargar(string usuario_, int clave_)
{
    //Crear el flujo lectura desde un archivo
    QFile archivo("/recursos/data_base.txt");
    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
    }
    QTextStream in(&archivo);
    QString valor;

    while(!in.atEnd()){ //mientras no sea el final del archivo
        valor = in.readLine();

        if(valor.toStdString() == usuario_){
            QString valor2 = valor;
            valor = in.readLine();
            QString valor3 = valor;

            if(valor.toInt() == clave_){
                valor = in.readLine();

                if(valor > 0){
                    //actulizar
                    setUsuario(valor2.toStdString());
                    setClave(valor3.toInt());
                    setNivel(valor.toInt());
                    break;
                }
            }
        }
    }
    archivo.close();
}

void Jugador::guardar()
{
    struct Cuentas{
        string user;
        int pass;
        int level;
    };

    vector<Cuentas> contenedor;


    //Crear el flujo lectura desde un archivo
    QFile archivo("/recursos/data_base.txt");
    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
    }
    QTextStream in(&archivo);
    QString valor;

    while(!in.atEnd()){ //mientras no sea el final del archivo
        Cuentas cuenta;

        //Obtenemos los valores
        valor = in.readLine();
        cuenta.user = valor.toStdString();
        valor = in.readLine();
        cuenta.pass = valor.toInt();
        valor = in.readLine();
        cuenta.level = valor.toInt();

        //Lo agregamos al vector de cuentas
        contenedor.push_back(cuenta);
    }
    archivo.close();

    //recorremos el vector para actualizarlo
    for(auto p=begin(contenedor); p != end(contenedor); p++){
        if(p->user == getUsuario()){
            p->level = getNivel();
        }
    }

    //Guardamos el nuevo usuario

    QFile archivo2("/recursos/data_base.txt");
    if(!archivo2.open(QIODevice::WriteOnly | QIODevice::Text)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
    }

    if(archivo2.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&archivo2);

        //recorremos el vector para actualizar la base de datos
        for(auto p=begin(contenedor); p != end(contenedor); p++){
            QString texto = QString::fromStdString(p->user) + " " + QString::number(p->pass) + " " + QString::number(p->level) + "\n";
            out << texto;
        }
    }
    archivo2.close();
}

void Jugador::reiniciar()
{
    nivel=1;
    setNivel(1);
}

void Jugador::eliminar()
{
    nivel=0;
    setNivel(0);

    struct Cuentas{
        string user;
        int pass;
        int level;
    };

    vector<Cuentas> contenedor;


    //Crear el flujo lectura desde un archivo
    QFile archivo("/recursos/data_base.txt");
    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
    }
    QTextStream in(&archivo);
    QString valor;

    while(!in.atEnd()){ //mientras no sea el final del archivo
        Cuentas cuenta;

        //Obtenemos los valores
        valor = in.readLine();
        cuenta.user = valor.toStdString();
        valor = in.readLine();
        cuenta.pass = valor.toInt();
        valor = in.readLine();
        cuenta.level = valor.toInt();

        //Lo agregamos al vector de cuentas
        contenedor.push_back(cuenta);
    }
    archivo.close();

    //recorremos el vector para actualizarlo
    for(auto p=begin(contenedor); p != end(contenedor); p++){
        if(p->user == getUsuario()){
            p->level = getNivel();
        }
    }

    //Guardamos el nuevo usuario

    QFile archivo2("/recursos/data_base.txt");
    if(!archivo2.open(QIODevice::WriteOnly | QIODevice::Text)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
    }

    if(archivo2.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&archivo2);

        //recorremos el vector para actualizar la base de datos
        for(auto p=begin(contenedor); p != end(contenedor); p++){
            QString texto = QString::fromStdString(p->user) + " " + QString::number(p->pass) + " " + QString::number(p->level) + "\n";
            out << texto;
        }
    }
    archivo2.close();

}


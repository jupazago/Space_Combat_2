#include "jugador.h"
#include <QFont>
#include <QtGui>

int Jugador::getVidas() const
{
    return vidas;
}

void Jugador::setVidas(int value)
{
    vidas = value;
}

int Jugador::getPuntos() const
{
    return puntos;
}

void Jugador::setPuntos(int value)
{
    puntos = value;
}

string Jugador::getClave() const
{
    return clave;
}

void Jugador::setClave(const string &value)
{
    clave = value;
}

Jugador::Jugador()
{
    usuario = "user";
    clave = "1111";
    nivel = 0;
    vidas = 3;
    puntos= 0;
}

Jugador::Jugador(string usuario_, string clave_)
{
    usuario = usuario_;
    clave = clave_;
    nivel = 1;
    vidas = 3;
    puntos = 0;
}

Jugador::Jugador(string usuario_, string clave_, int vidas_, int nivel_, int puntos_)
{
    usuario = usuario_;
    clave = clave_;
    nivel = nivel_;
    vidas = vidas_;
    puntos = puntos_;
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

bool Jugador::crear_nuevo()
{


    //Guardamos el nuevo usuario
    //si no existe ese usuario, guardamos
    if(existe_registro() == false){
        //qDebug() <<"Como no se encontro, vamos a crearlo";

        //Crear el flujo escritura desde un archivo
        QFile archivo("../Space_Impact/recursos/data_base.txt");
        if(!archivo.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
            //QMessageBox::information(this, "Informacion", "No se puede leer el archivo data_base.txt");
            qDebug() << "No lectura: Crear Nuevo";
        }else{
            QTextStream out(&archivo);
            QString texto = "\n" + QString::fromStdString(usuario) + "\n" + QString::fromStdString(clave) + "\n" + QString::number(nivel) + "\n" + QString::number(vidas)+ "\n" + QString::number(puntos);

            out << texto;
            archivo.close();
            qDebug() <<"Nueva cuenta Creada";
            return true;
        }

        archivo.close();
    }
    qDebug() <<"NO Creado";

    return false;

}

bool Jugador::cargar()
{
    //Crear el flujo lectura desde un archivo
    QFile archivo("../Space_Impact/recursos/data_base.txt");
    if(!archivo.open(QIODevice::ReadOnly)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
        qDebug() << "No lectura: Cargar";
    }
    QTextStream in(&archivo);
    QString valor;

    while(!in.atEnd()){ //mientras no sea el final del archivo
        valor = in.readLine();

        //si el usuario existe
        if(valor.toStdString() == usuario){
            QString valor2 = valor; //valor 2 es el usuario
            valor = in.readLine();
            QString valor3 = valor; //valor 3 es la clave

            //si su contrasenia coincide
            if(valor3.toStdString() == clave){
                valor = in.readLine(); //obtenemos el nivel

                //si nivel es correcto
                if(valor > 0){
                    //actulizar
                    usuario = valor2.toStdString();

                    clave = valor3.toStdString();

                    nivel = valor.toInt();

                    valor = in.readLine();
                    vidas = valor.toInt();

                    valor = in.readLine();
                    puntos = valor.toInt();
                    archivo.close();
                    return true;
                }
            }else{
                archivo.close();
                return false;
            }
        }
    }
    archivo.close();
    return  false;
}

bool Jugador::guardar()
{
    struct Cuentas{
        string user;
        string pass;
        int level;
        int vidas;
        int puntos;
    };

    vector<Cuentas> contenedor;


    //Crear el flujo lectura desde un archivo
    QFile archivo("../Space_Impact/recursos/data_base.txt");
    if(!archivo.open(QIODevice::ReadOnly)){
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
        cuenta.pass = valor.toStdString();

        valor = in.readLine();
        cuenta.level = valor.toInt();

        valor = in.readLine();
        cuenta.vidas = valor.toInt();

        valor = in.readLine();
        cuenta.puntos = valor.toInt();

        //Lo agregamos al vector de cuentas
        contenedor.push_back(cuenta);
    }
    archivo.close();

    //recorremos el vector para actualizarlo
    for(auto p=begin(contenedor); p != end(contenedor); p++){
        if(p->user == usuario && p->pass == clave){
            p->level = nivel;
            p->vidas = vidas;
            p->puntos = puntos;

            qDebug() << QString::fromStdString(p->user);
            qDebug() << QString::fromStdString(p->pass);
            qDebug() << QString::number(p->level);
            qDebug() << QString::number(p->vidas);
            qDebug() << QString::number(p->puntos);
        }
    }

    //Guardamos el nuevo usuario

    if(!archivo.open(QIODevice::WriteOnly| QIODevice::Text)){
        //QMessageBox::Critical(this, "¡Informacion!", "No se puede leer el archivo data_base.txt");
    }else{
        QTextStream out(&archivo);
        int iterador = 0;
        //recorremos el vector para actualizar la base de datos
        for(auto p=begin(contenedor); p != end(contenedor); p++){
            if(iterador == 0){
                QString texto = QString::fromStdString(p->user) + "\n" + QString::fromStdString(p->pass) + "\n" + QString::number(p->level) + "\n" + QString::number(p->vidas) + "\n" + QString::number(p->puntos);
                out << texto;
            }else{
                QString texto = "\n" + QString::fromStdString(p->user) + "\n" + QString::fromStdString(p->pass) + "\n" + QString::number(p->level) + "\n" + QString::number(p->vidas) + "\n" + QString::number(p->puntos);
                out << texto;
            }
            iterador++;
        }
    }
    archivo.close();
    return true;
}

bool Jugador::reiniciar()
{
    nivel=1;
    vidas = 3;
    puntos = 0;
    return guardar();
}

bool Jugador::eliminar()
{
    nivel=0;

    struct Cuentas{
        string user;
        string pass;
        int level;
        int vidas;
        int puntos;
    };

    vector<Cuentas> contenedor;


    //Crear el flujo lectura desde un archivo
    QFile archivo("../Space_Impact/recursos/data_base.txt");
    if(!archivo.open(QIODevice::ReadOnly)){
        qDebug() << "No lectura: Eliminar 1";
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
        cuenta.pass = valor.toStdString();
        valor = in.readLine();
        cuenta.level = valor.toInt();
        valor = in.readLine();
        cuenta.vidas = valor.toInt();
        valor = in.readLine();
        cuenta.puntos = valor.toInt();

        //Lo agregamos al vector de cuentas
        contenedor.push_back(cuenta);
    }
    archivo.close();

    bool encontrado = false;

    //recorremos el vector para actualizarlo
    for(auto p=begin(contenedor); p != end(contenedor); p++){
        if(p->user == usuario && p->pass == clave){
            p->level = nivel;
            encontrado = true;
            break;
        }
    }
    if(encontrado == false) return false;

    //Guardamos el nuevo usuario



    if(!archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "No lectura: Eliminar 2";
    }

    if(archivo.isOpen()){
        qDebug() << "Actualizaremos el nivel";
        QTextStream out(&archivo);

        //recorremos el vector para actualizar la base de datos
        for(auto p=begin(contenedor); p != end(contenedor); p++){
            QString texto = QString::fromStdString(p->user) + "\n" + QString::fromStdString(p->pass) + "\n" + QString::number(p->level) + "\n" + QString::number(p->vidas) + "\n" + QString::number(p->puntos) + "\n";
            out << texto;
        }
    }else{
        qDebug() << "No lectura: Eliminar 2";
    }


    archivo.close();
    return true;

}

bool Jugador::existe_registro()
{
    struct Cuentas{
        string user;
        string pass;
        int level;
        int vidas;
        int puntos;
    };

    vector<Cuentas> contenedor;

    //Crear el flujo escritura desde un archivo
    QFile archivo("../Space_Impact/recursos/data_base.txt");
    if(!archivo.open(QIODevice::ReadOnly)){
        //QMessageBox::information(this, "Informacion", "No se puede leer el archivo data_base.txt");
        qDebug() << "No lectura: Existe Registro";
    }

    QTextStream in(&archivo);
    QString valor;

    while(!in.atEnd()){ //mientras no sea el final del archivo
        Cuentas cuenta;

        //Obtenemos los valores
        valor = in.readLine();
        cuenta.user = valor.toStdString();
        //qDebug() << QString::fromStdString(cuenta.user);
        valor = in.readLine();
        cuenta.pass = valor.toStdString();
        valor = in.readLine();
        cuenta.level = valor.toInt();
        valor = in.readLine();
        cuenta.vidas = valor.toInt();
        valor = in.readLine();
        cuenta.puntos = valor.toInt();

        //Lo agregamos al vector de cuentas
        contenedor.push_back(cuenta);
    }
    archivo.close();


    //recorremos el vector para actualizarlo
    for(auto p=begin(contenedor); p != end(contenedor); p++){
        if(p->user == usuario){
            //qDebug() << QString::fromStdString(p->user);
            //qDebug() << QString::fromStdString(usuario);
            return true;
        }
    }
    return false;

}

Corazones *Jugador::graficar_vida()
{
    corazones = new Corazones();
    return corazones;
}

void Jugador::eliminar_Corazon()
{
    corazones->Actualizacion(vidas);
}

Puntuacion *Jugador::crear_puntos()
{
    puntuacion = new Puntuacion();
    return puntuacion;
}

void Jugador::incrementar_puntos(int valor)
{
    puntos += valor;
    puntuacion->incrementar(puntos);
}

void Jugador::subir_nivel()
{
    nivel++;
    guardar();
}




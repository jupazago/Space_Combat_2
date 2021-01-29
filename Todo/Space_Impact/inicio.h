#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include <inicio_juego_nuevo.h>
#include <inicio_juego_cargar.h>
#include <inicio_juego_eliminar.h>
#include <inicio_juego_reiniciar.h>

namespace Ui {
class Inicio;
}

class Inicio : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();

private slots:
    void on_btn_nuevo_clicked();

    void on_btn_cargar_clicked();

    void on_btn_eliminar_clicked();

    void on_btn_reiniciar_clicked();

private:
    Ui::Inicio *ui;

    Inicio_juego_nuevo *formulario_inicio;
    inicio_juego_cargar *formulario_cargar;
    Inicio_juego_eliminar *formulario_eliminar;
    Inicio_juego_reiniciar *formulario_reiniciar;
};

#endif // INICIO_H

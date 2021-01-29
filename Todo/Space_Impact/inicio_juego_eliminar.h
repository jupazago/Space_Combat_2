#ifndef INICIO_JUEGO_ELIMINAR_H
#define INICIO_JUEGO_ELIMINAR_H

#include <QWidget>
#include <string>
#include <jugador.h>

namespace Ui {
class Inicio_juego_eliminar;
}

class Inicio_juego_eliminar : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio_juego_eliminar(QWidget *parent = nullptr);
    ~Inicio_juego_eliminar();

private slots:
    void on_btn_eliminar_clicked();

private:
    Ui::Inicio_juego_eliminar *ui;

    Jugador *jugador;
};

#endif // INICIO_JUEGO_ELIMINAR_H

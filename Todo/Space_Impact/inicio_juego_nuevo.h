#ifndef INICIO_JUEGO_NUEVO_H
#define INICIO_JUEGO_NUEVO_H

#include <QWidget>
#include <string>
#include <jugador.h>

namespace Ui {
class Inicio_juego_nuevo;
}

class Inicio_juego_nuevo : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio_juego_nuevo(QWidget *parent = nullptr);
    ~Inicio_juego_nuevo();

private slots:
    void on_btn_crear_clicked();

private:
    Ui::Inicio_juego_nuevo *ui;

    Jugador *jugador;
};

#endif // INICIO_JUEGO_NUEVO_H

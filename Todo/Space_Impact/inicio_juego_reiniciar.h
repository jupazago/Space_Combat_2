#ifndef INICIO_JUEGO_REINICIAR_H
#define INICIO_JUEGO_REINICIAR_H

#include <QWidget>
#include <string>
#include <jugador.h>

namespace Ui {
class Inicio_juego_reiniciar;
}

class Inicio_juego_reiniciar : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio_juego_reiniciar(QWidget *parent = nullptr);
    ~Inicio_juego_reiniciar();

private slots:
    void on_btn_crear_clicked();

private:
    Ui::Inicio_juego_reiniciar *ui;

    Jugador *jugador;
};

#endif // INICIO_JUEGO_REINICIAR_H

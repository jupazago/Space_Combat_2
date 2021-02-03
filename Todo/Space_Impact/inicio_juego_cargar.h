#ifndef INICIO_JUEGO_CARGAR_H
#define INICIO_JUEGO_CARGAR_H

#include <QWidget>
#include <string>
#include <jugador.h>
#include <mainwindow.h>
#include <QTimer>

namespace Ui {
class inicio_juego_cargar;
}

class inicio_juego_cargar : public QWidget
{
    Q_OBJECT

public:
    explicit inicio_juego_cargar(QWidget *parent = nullptr);
    ~inicio_juego_cargar();

private slots:
    void on_btn_cargar_clicked();
    void empezar();

private:
    Ui::inicio_juego_cargar *ui;

    MainWindow *juego;
    Jugador *jugador;

    QTimer *timer_instructivo;
};

#endif // INICIO_JUEGO_CARGAR_H

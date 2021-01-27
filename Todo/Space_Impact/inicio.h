#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include <inicio_juego_nuevo.h>

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

    void on_pushButton_4_clicked();

private:
    Ui::Inicio *ui;

    Inicio_juego_nuevo formulario_inicio;
};

#endif // INICIO_H

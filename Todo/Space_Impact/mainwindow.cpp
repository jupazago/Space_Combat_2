#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Creación de escena y fondo de pantalla
    scena = new QGraphicsScene;
    ui->graphicsView->setScene(scena);
    scena->setSceneRect(0,0,1000,600);
    scena->backgroundBrush();
    ui->graphicsView->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));


}

MainWindow::~MainWindow()
{
    delete ui;
}


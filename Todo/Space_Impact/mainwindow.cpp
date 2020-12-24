#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Creación de escena y fondo de pantalla
    /*
    scena = new QGraphicsScene;
    ui->graphicsView->setScene(scena);
    scena->setSceneRect(0,0,1000,600);
    scena->backgroundBrush();
    ui->graphicsView->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));
    */
    QRect Desktop = QApplication::desktop()->screenGeometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = 995;
    alto = 590;

    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));
    ui->graphicsView->setScene(scene);

    personaje = new Humanidad();

    scene->addItem(personaje);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        personaje->MoveUp();
        /*
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(objCuerpo->collidesWithItem(*p)){
                objCuerpo->MoveDown();
            }
        }
        */
    }else if(evento->key()==Qt::Key_S){
        personaje->MoveDown();
        /*
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(personaje->collidesWithItem(*p)){
                personaje->MoveUp();
            }
        }
        */
    }

}


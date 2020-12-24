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

    humanos = new Humanidad();
    scene->addItem(humanos);

    timer_misiles= new QTimer();
    connect(timer_misiles, SIGNAL(timeout()), this, SLOT(Mover()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        humanos->MoveUp();
    }else if(evento->key()==Qt::Key_S){
        humanos->MoveDown();
    }

    if(evento->key()==Qt::Key_Space){
        double x= humanos->getPosx()+30;
        double y= humanos->getPosy()+30;
        double v= 100;
        double a= -45;


        a = (a*3.14159)/180;
        //cuerpo = new Misil(x,y,v,a);
        misiles.push_back(new Misil(x,y,v,a));
        scene->addItem(misiles.back());
        timer_misiles->start(5);
    }

}
//Mover misiles
void MainWindow::Mover()
{
    QList<Misil*>::iterator it;
    for(it = misiles.begin();it != misiles.end(); it++)
       (*it)->ActualizarPosicion();
}

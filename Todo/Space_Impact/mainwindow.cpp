#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Add escena
    QRect Desktop = QApplication::desktop()->screenGeometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = 995;
    alto = 590;

    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));
    ui->graphicsView->setScene(scene);


    //Add humanidad
    humanos = new Humanidad();
    scene->addItem(humanos);


    //add enemigos lvl 1
    enemigos.push_back(new Enemigo(x,y,1));
    scene->addItem(enemigos.back());

    timer_enemigo = new QTimer();
    connect(timer_enemigo, SIGNAL(timeout()), this, SLOT(MoverEnemigo()));
    timer_enemigo->start(20);


    //add misiles humanidad
    timer_misiles = new QTimer();
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

//Mover Enemigo
void MainWindow::MoverEnemigo()
{

    for(auto it = enemigos.begin(); it != enemigos.end(); it++){
        (*it)->Move();
    }

}








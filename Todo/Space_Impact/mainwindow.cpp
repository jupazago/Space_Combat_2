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

    //add jugador
    jugador = new Jugador("jupazago", 1998);
    scene->addItem(jugador->graficar_vida());   //corazones
    scene->addItem(jugador->crear_puntos());    //puntuacion

    //Pared
    //                   x-y-ancho-alto
    paredes.push_back(new Pared(-1,100,1000,10));
    scene->addItem(paredes.back());
    paredes.push_back(new Pared(-1,600,1000,10));
    scene->addItem(paredes.back());

    //Pared de eliminacion
    eliminacion_humana = new Pared(1000,-1000,1,2600);
    eliminacion_enemiga = new Pared(-200,-1000,1,2600);
    scene->addItem(eliminacion_humana);
    scene->addItem(eliminacion_enemiga);



    nivel1();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        humanos->MoveUp();

        //choque con paredes
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(humanos->collidesWithItem(*p)){
                humanos->MoveDown();
            }
        }

    }else if(evento->key()==Qt::Key_S){
        humanos->MoveDown();

        //choque con paredes
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(humanos->collidesWithItem(*p)){
                humanos->MoveUp();
            }
        }


    }

    if(evento->key()==Qt::Key_1){
        double x= humanos->getPosx()+30;
        double y= humanos->getPosy()+30;
        double v= 100;
        double a= -45;
        a = (a*3.14159)/180; //angulo en radianes

        misiles.push_back(new Misil(x,y,v,a));
        scene->addItem(misiles.back());
        timer_misiles->start(5);
    }

    if(evento->key()==Qt::Key_2){
        double x= humanos->getPosx()+30;
        double y= humanos->getPosy()+30;
        double v= 35;
        double a= 45;
        a = (a*3.14159)/180; //angulo en radianes

        misiles.push_back(new Misil(x,y,v,a));
        scene->addItem(misiles.back());
        timer_misiles->start(5);
    }

}

//Mover misiles
void MainWindow::Mover()
{
    int contador1 = 0;
    QList<Misil*>::iterator it;
    for(it = misiles.begin();it != misiles.end(); it++){
       (*it)->ActualizarPosicion();

        if((*it)->collidesWithItem(eliminacion_humana)){
            scene->removeItem(misiles.at(contador1));
            misiles.removeAt(contador1);
            break;
        }
    contador1++;
    }
}

//Mover Enemigo
void MainWindow::MoverEnemigo()
{
    int contador = 0;
    for(auto it = enemigos.begin(); it != enemigos.end(); it++){
        (*it)->Move();
        if((*it)->collidesWithItem(eliminacion_enemiga)){
            scene->removeItem(*it);
            enemigos.erase(it);
            jugador->setVidas(jugador->getVidas()-1);
            jugador->eliminar_Corazon();
            break;
        }
        contador++;
    }
    MoverPaisaje();
}

//Mover Paisaje
void MainWindow::MoverPaisaje()
{
    for(auto it = nubes.begin(); it != nubes.end(); it++){
        (*it)->Move();
    }
}

//verificar Choques
void MainWindow::verificarChoques()
{
    int contador1 = 0;
    int contador2 = 0;
    for(auto it = enemigos.begin(); it != enemigos.end(); it++){
        for(auto itt = misiles.begin(); itt != misiles.end(); itt++){
            if(sqrt(pow((*it)->getPosx()-(*itt)->getPosx(),2)   + pow((*it)->getPosy()-(*itt)->getPosy(),2)) < 50){
                scene->removeItem(*it);
                enemigos.erase(it);

                scene->removeItem(*itt);
                misiles.erase(itt);

                jugador->incrementar_puntos(10);

                break;
            }
            contador2++;
        }
        contador1++;
    }
}




void MainWindow::nivel1()
{

    //add enemigos lvl 1
    int ejey;
    for (int i=500; i<10000; i+=500) {
        ejey = rand() %400 + 100;
        enemigos.push_back(new Enemigo(i, ejey, 1));
        scene->addItem(enemigos.back());
    }

    //add nubes
    int ejex, nube=1;
    ejey=0;
    for (int i=0; i<100; i++) {
        ejex = rand() %10000 + 1;
        ejey = rand() %600 + 1;
        nubes.push_back(new Paisaje(ejex, ejey, nube));
        scene->addItem(nubes.back());
        nube++;
        if(nube>5) nube = 1;
    }
    //montania
    scene->addItem(new Paisaje(500,585,6));



    //timer enemigo
    timer_enemigo = new QTimer();
    connect(timer_enemigo, SIGNAL(timeout()), this, SLOT(MoverEnemigo()));
    timer_enemigo->start(20);


    //add misiles humanidad
    timer_misiles = new QTimer();
    connect(timer_misiles, SIGNAL(timeout()), this, SLOT(Mover()));

    //Add humanidad
    humanos = new Humanidad();
    scene->addItem(humanos);


    //add verificar choques
    timer_choques = new QTimer();
    connect(timer_choques, SIGNAL(timeout()), this, SLOT(verificarChoques()));
    timer_choques->start(100);

    jefe1 = new Jefe(800, 200, 1);
    scene->addItem(jefe1);

}

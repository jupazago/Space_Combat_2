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

    //add jugador
    jugador = new Jugador("jupazago", 1998);
    scene->addItem(jugador->graficar_vida());   //corazones
    scene->addItem(jugador->crear_puntos());    //puntuacion
    jugador->subir_nivel();
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

    if(evento->key()==Qt::Key_1 && humanos->getExiste() == true){
        double x= humanos->getPosx()+30;
        double y= humanos->getPosy()+30;
        double v= 100;
        double a= -45;
        a = (a*3.14159)/180; //angulo en radianes

        misiles.push_back(new Misil(x,y,v,a));
        scene->addItem(misiles.back());
        timer_misiles->start(5);
    }

    if(evento->key()==Qt::Key_2 && humanos->getExiste() == true){
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
    if(misiles.size() > 0){
        QList<Misil*>::iterator it;
        for(it = misiles.begin();it != misiles.end(); it++){
           (*it)->ActualizarPosicion();
            if((*it)->collidesWithItem(eliminacion_humana)){
                scene->removeItem(*it);
                misiles.erase(it);
                break;
            }
        }
    }
}

//Mover proyectiles
void MainWindow::Mover2()
{
    if(proyectiles.size() > 0){
        QList<Misil*>::iterator itt;
        for(itt = proyectiles.begin();itt != proyectiles.end(); itt++){
           (*itt)->ActualizarPosicion();
        }
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

    //Misiles vs enemigos
    int contador1 = 0;
    int contador2 = 0;
    for(auto it = enemigos.begin(); it != enemigos.end(); it++){
        for(auto itt = misiles.begin(); itt != misiles.end(); itt++){
            if(sqrt(pow((*it)->getPosx()-(*itt)->getPosx(),2)   + pow((*it)->getPosy()-(*itt)->getPosy(),2)) < 50){


                (*it)->setSalud((*it)->getSalud() -1);

                if((*it)->getSalud() <=0){
                    scene->removeItem(*it);
                    enemigos.erase(it);
                }
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

    scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));
    ui->graphicsView->setScene(scene);

    //add enemigos por lvl
    int ejey;
    for (int i=1000; i<10000; i+=500) {
        ejey = rand() %400 + 100;
        enemigos.push_back(new Enemigo(i, ejey, jugador->getNivel()));
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

    //Add Jefe
    timer_jefe1 = new QTimer();
    connect(timer_jefe1, SIGNAL(timeout()), this, SLOT(invocarJefe1()));
    timer_jefe1->start(6000);
    //add disparos del jefe

    timer_jefeDisparo = new QTimer();
    connect(timer_jefeDisparo, SIGNAL(timeout()), this, SLOT(DisparoJefe()));
    timer_jefeDisparo->start(4000);
}

//Jefe 1
void MainWindow::invocarJefe1()
{



    jefe1 = new Jefe(800, 300, jugador->getNivel());
    scene->addItem(jefe1);
    timer_jefe1->stop();

    timer_jefeVsMisiles = new QTimer();
    connect(timer_jefeVsMisiles, SIGNAL(timeout()), this, SLOT(verificarChoquesVsJefe()));
    timer_jefeVsMisiles->start(50);

    //add proyectiles al jefe
    timer_proyectiles = new QTimer();
    connect(timer_proyectiles, SIGNAL(timeout()), this, SLOT(Mover2()));


}

void MainWindow::verificarChoquesVsJefe()
{
    //Misiles vs Jefe
    if(misiles.size() > 0){
        for(auto itt = misiles.begin(); itt != misiles.end(); itt++){
            if(jefe1->collidesWithItem(*itt)){
                scene->removeItem(*itt);
                misiles.erase(itt);

                jefe1->setSalud( jefe1->getSalud() - 5);
                jugador->incrementar_puntos(5);

                //Si muere el jefe
                if(jefe1->getSalud() <= 0){
                    Limpiar_y_Detener();
                }
                break;
            }
        }
    }

    if(proyectiles.size() > 0){
        for(auto it = proyectiles.begin(); it != proyectiles.end(); it++){
            if(humanos->collidesWithItem(*it)){
                scene->removeItem(*it);
                proyectiles.erase(it);

                jugador->setVidas(jugador->getVidas()-1);
                jugador->eliminar_Corazon();
                break;
            }
        }
    }

    if(coord >= 80) coord = -80;
    if(coord > 0) jefe1->MoveUp();
    if(coord < 0) jefe1->MoveDown();

    coord++;
}

void MainWindow::DisparoJefe()
{
    //Generar proyectiles
    double x= jefe1->getPosx()-30;
    double y= jefe1->getPosy()-30;
    double v= rand() %100 + 80;
    double a= rand() %180 + 120;
    a = (a*3.14159)/180; //angulo en radianes

    proyectiles.push_back(new Misil(x,y,v,a));
    scene->addItem(proyectiles.back());
    timer_proyectiles->start(10);

    //Generar proyectiles
    x= jefe1->getPosx()-30;
    y= jefe1->getPosy()-30;
    v= rand() %100 + 80;
    a= rand() %180 + 120;
    a = (a*3.14159)/180; //angulo en radianes

    proyectiles.push_back(new Misil(x,y,v,a));
    scene->addItem(proyectiles.back());
    timer_proyectiles->start(10);
}

void MainWindow::Limpiar_y_Detener(){

    //detener Timers
    timer_misiles->stop();
    timer_proyectiles->stop();
    timer_choques->stop();
    timer_enemigo->stop();
    timer_jefe1->stop();
    timer_jefeVsMisiles->stop();
    timer_jefeDisparo->stop();

    //remover objetos de listas
    if(misiles.size() > 0){
        for (auto i=misiles.begin(); i<misiles.end(); i++) {
            scene->removeItem(*i);
            misiles.erase(i);
        }
    }
    misiles.clear();

    if(proyectiles.size() > 0){
        for (auto i=proyectiles.begin(); i<proyectiles.end(); i++) {
            scene->removeItem(*i);
            proyectiles.erase(i);
        }
    }
    proyectiles.clear();

    if(enemigos.size() > 0){
        for (auto i=enemigos.begin(); i<enemigos.end(); i++) {
            scene->removeItem(*i);
            enemigos.erase(i);
        }
    }
    enemigos.clear();

    if(nubes.size() > 0){
        for (auto i=nubes.begin(); i<nubes.end(); i++) {
            scene->removeItem(*i);
            nubes.erase(i);
        }
    }
    nubes.clear();

    //limpiar
    scene->removeItem(humanos);
    humanos->setExiste(false);
    scene->removeItem(jefe1);

    //subo nivel
    jugador->subir_nivel();
    scene->clear();

    if(jugador->getNivel() <= 5){
        MainWindow w;
    }

}

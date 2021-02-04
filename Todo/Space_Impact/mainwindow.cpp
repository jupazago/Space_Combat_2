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

    //iniciar("jupazago", "1998");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciar(string u, string c){

    timer_enemigo       = new QTimer();
    timer_misiles       = new QTimer();
    timer_choques       = new QTimer();
    timer_jefe          = new QTimer();
    timer_jefeDisparo   = new QTimer();

    //add jugador

    jugador = new Jugador(u, c);
    jugador->cargar(); //obetenemos sus atributos restantes (puntos, vidas, nivel)
    scene->addItem(jugador->graficar_vida());   //corazones
    jugador->eliminar_Corazon();
    scene->addItem(jugador->crear_puntos());    //puntuacion
    jugador->incrementar_puntos(0);




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


    //Add humanidad
    humanos = new Humanidad();

    //timer enemigo
    connect(timer_enemigo, SIGNAL(timeout()), this, SLOT(MoverEnemigo()));

    //add misiles humanidad
    connect(timer_misiles, SIGNAL(timeout()), this, SLOT(Mover()));

    //add verificar choques
    connect(timer_choques, SIGNAL(timeout()), this, SLOT(verificarChoques()));

    //Add Jefe
    connect(timer_jefe, SIGNAL(timeout()), this, SLOT(invocarJefe()));

    //add disparos del jefe
    connect(timer_jefeDisparo, SIGNAL(timeout()), this, SLOT(DisparoJefe()));

    nivel();
}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    //Si presiono la tecla W
    if(evento->key()==Qt::Key_W){
        //Muevo mi humano
        humanos->MoveUp();

        //choque con paredes
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(humanos->collidesWithItem(*p)){
                humanos->MoveDown();
            }
        }

        //Si presiono la tecla S
    }else if(evento->key()==Qt::Key_S){
        //Muevo mi humano
        humanos->MoveDown();

        //choque con paredes
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(humanos->collidesWithItem(*p)){
                humanos->MoveUp();
            }
        }
    }

    //Si me encuentro habilitado para disparar
    //Disparo con 1 y 2


    if(evento->key()==Qt::Key_1 && humanos->getExiste() == true){
        double x= humanos->getPosx()+30;
        double y= humanos->getPosy();
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


    //Tecla de M de menu
    if(evento->key()==Qt::Key_M){
        timer_enemigo->stop();
        this->close();

    }

    //Tecla de P de pausar
    if(evento->key()==Qt::Key_P){

    }

}

//Mover misiles
void MainWindow::Mover()
{
    if(misiles.size() > 0){
        //si misiles es >0, los recorro y los muevo
        QList<Misil*>::iterator it;
        for(it = misiles.begin();it != misiles.end(); it++){
           (*it)->ActualizarPosicion();

            //existe un limite a la derecha que elimina los misiles humanos
            //cuando ya no se ven y libera espacio
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
        //si proyectiles es > 0, los recorro y los muevo
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
    if(enemigos.size() > 0){
        for(auto it = enemigos.begin(); it != enemigos.end(); it++){
            //muevo enemigo
            (*it)->Move();

            //si coliciona con la pared invisible a la izquierda
            //desapaece de la escena, limpia de la lista
            // y eliminamos una vida de nuestro humano

            if((*it)->collidesWithItem(eliminacion_enemiga)){
                scene->removeItem(*it);
                enemigos.erase(it);
                jugador->setVidas(jugador->getVidas()-1);
                jugador->eliminar_Corazon();
                if(jugador->getVidas() == 0){
                    QMessageBox::critical(this, "Informacion", "Perdiste");
                    this->close();
                }
                break;
            }

            contador++;
        }
    }
    //tambien movemos el paisaje, las nubes
    MoverPaisaje();
}

//Mover Paisaje
void MainWindow::MoverPaisaje()
{
    //movemos todas nuestras nubes
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

    if(misiles.size() > 0 && (enemigos.size() > 0)){
        for(auto it = enemigos.begin(); it != enemigos.end(); it++){
            for(auto itt = misiles.begin(); itt != misiles.end(); itt++){
                //si el radio de choque esta dentro del rango
                //distancia entre dos puntos
                if(sqrt(pow((*it)->getPosx()-(*itt)->getPosx(),2)   + pow((*it)->getPosy()-(*itt)->getPosy(),2)) < 50){

                    //quitamos una vida a cada enemigo
                    (*it)->setSalud((*it)->getSalud() -1);

                    //si sus vidas es < 0, los eliminamos
                    if((*it)->getSalud() <=0){
                        scene->removeItem(*it);
                        enemigos.erase(it);
                    }
                    scene->removeItem(*itt);
                    misiles.erase(itt);

                    //aumentamos el puntaje
                    jugador->incrementar_puntos(10);

                    break;
                }
                contador2++;
            }
            contador1++;
        }
    }

}

//Jefe 1
void MainWindow::invocarJefe()
{
    //invocamos al jefe
    jefe = new Jefe(800, 300, jugador->getNivel());
    scene->addItem(jefe);
    timer_jefe->stop();

    //verificamos los choques de los misiles vs nuestro jefe
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
        //si misiles son mas o igual de 1
        for(auto itt = misiles.begin(); itt != misiles.end(); itt++){
            //si jefe colisiona con los misiles humanos
            if(jefe->collidesWithItem(*itt)){
                //eliminamos el misil
                scene->removeItem(*itt);
                misiles.erase(itt);
                //reducimos su vida
                jefe->setSalud( jefe->getSalud() - 5);
                jugador->incrementar_puntos(5);

                //Si muere el jefe
                if(jefe->getSalud() <= 0){
                    Limpiar_y_Detener();
                }
                break;
            }
        }
    }

    //si los proyectiles enemigos tocan a nuestro humano
    //reducimos nuestra vida
    if(proyectiles.size() > 0){
        for(auto it = proyectiles.begin(); it != proyectiles.end(); it++){
            if(humanos->collidesWithItem(*it)){
                //eliminamos el proyectil
                scene->removeItem(*it);
                proyectiles.erase(it);

                jugador->setVidas(jugador->getVidas()-1);
                jugador->eliminar_Corazon();
                break;
            }
        }
    }

    //los movimientos del jefe para que vaya de arriba a abajo
    // constantemente

    if(coord >= 80) coord = -80;
    if(coord > 0) jefe->MoveUp();
    if(coord < 0) jefe->MoveDown();

    coord++;
}

void MainWindow::DisparoJefe()
{

    //generamos un disparo

    for (int i=0; i<(jugador->getNivel()-1); i++) {
        //Generar proyectiles
        double x= jefe->getPosx()-30;
        double y= jefe->getPosy()-30;
        double v= rand() %100 + 80;
        double a= rand() %180 + 120;
        a = (a*3.14159)/180; //angulo en radianes

        proyectiles.push_back(new Misil(x,y,v,a));
        scene->addItem(proyectiles.back());

        //le damos movimiento
        timer_proyectiles->start(10);
    }
}

void MainWindow::Limpiar_y_Detener(){

    //detener Timers
    timer_misiles->stop();
    timer_proyectiles->stop();
    timer_choques->stop();
    timer_enemigo->stop();
    timer_jefe->stop();
    timer_jefeVsMisiles->stop();
    timer_jefeDisparo->stop();

    //remover objetos de listas para dejar todo en limpio
    //tambien limpiamos toda la escena


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
    scene->removeItem(jefe);



    //subo nivel y guardo partida
    jugador->subir_nivel();

    if(jugador->getNivel() <= 5){
        nivel();
    }

}

void MainWindow::nivel()
{
    humanos->setExiste(true);


    if(jugador->getNivel() == 1){
        scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));
        ui->graphicsView->setScene(scene);

    }else if(jugador->getNivel() == 2){
        scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba2.jpg"));
        ui->graphicsView->setScene(scene);

    }else if(jugador->getNivel() == 3){
        scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba3.jpg"));
        ui->graphicsView->setScene(scene);

    }else if(jugador->getNivel() == 4){
        scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));
        ui->graphicsView->setScene(scene);

    }else if(jugador->getNivel() == 5){
        scene->setBackgroundBrush(QPixmap(":/recursos/fondo_prueba.jpg"));
        ui->graphicsView->setScene(scene);
    }


    //add enemigos por lvl
    int ejey;
    for (int i=1000; i<10000; i+=500) {
        ejey = rand() %400 + 100;
        enemigos.push_back(new Enemigo(i, ejey, jugador->getNivel()));
        scene->addItem(enemigos.back());
    }

    if(jugador->getNivel() != 2){
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
    }

    //montania
    scene->addItem(new Paisaje(500,585,6));

    //timer enemigo
    timer_enemigo->start(20);

    //humanos en escena
    scene->addItem(humanos);

    //add verificar choques
    timer_choques->start(100);

    //Add Jefe
    timer_jefe->start(40000);

    //add disparos del jefe
    //timer_jefeDisparo->start(6000);
}

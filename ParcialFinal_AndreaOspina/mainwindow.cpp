#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,582,390);
    ui->graphicsView->setScene(escena);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    srand(unsigned(time(nullptr)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NuevoObstaculo()
{
    Obstaculos.push_back(new Obstaculo(rand()%(581),rand()%(391),20+rand()%(51)));
    escena->addItem(Obstaculos.back());
}

void MainWindow::NuevoParabolico()
{
   Parabolicos.push_back(new Parabolico(rand()%(581),0,(5+rand()%(20))-10,(-1)*(5+rand()%(20))));
   escena->addItem(Parabolicos.back());
}

void MainWindow::NuevoEspecial()
{
    Especiales.push_back(new CaidaLibre(rand()%(581),rand()%(101)));
    escena->addItem(Especiales.back());
}

void MainWindow::Actualizar()
{
   contTime++;
   if(contTime%20==0){
       NuevoObstaculo();
       NuevoParabolico();
       for(int i=0; i<Obstaculos.size();i++){
           Obstaculos.at(i)->setTiempoVida(Obstaculos.at(i)->getTiempoVida()-1);
           if(Obstaculos.at(i)->getTiempoVida()==0){
               escena->removeItem(Obstaculos.at(i));
               Obstaculo *obstaculo=Obstaculos.at(i);
               Obstaculos.removeAt(i);
               delete obstaculo;
           }
       }
   }
   for(int i=0; i<Parabolicos.size();i++){
       if(Parabolicos.at(i)->y()<390){
        Parabolicos.at(i)->ActualizarPosicion();
       }
       else{
           Parabolicos.at(i)->Desaparecer();
           Parabolico *para=Parabolicos.at(i);
           Parabolicos.removeAt(i);
           delete para;
       }
   }

   for(int i=0; i<Especiales.size();i++){
       if(Especiales.at(i)->y()<390){
        Especiales.at(i)->ActualizarPosicion();
       }
       else{
           Especiales.at(i)->Desaparecer();
           CaidaLibre *esp=Especiales.at(i);
           Especiales.removeAt(i);
           delete esp;
       }
   }


}

void MainWindow::on_pushButton_clicked()
{
        timer=new QTimer;
        connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
        timer->start(50);
}

void MainWindow::on_pushButton_2_clicked()
{
    NuevoEspecial();
}

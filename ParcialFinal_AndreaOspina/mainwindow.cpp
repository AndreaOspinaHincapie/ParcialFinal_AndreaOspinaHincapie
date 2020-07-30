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
    parabolico=new Parabolico(0,0,10,-10);
    escena->addItem(parabolico);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Actualizar()
{
    parabolico->ActualizarPosicion();

}

void MainWindow::on_pushButton_clicked()
{
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer->start(50);
}

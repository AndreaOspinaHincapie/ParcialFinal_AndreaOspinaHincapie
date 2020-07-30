#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QTimer>
#include"parabolico.h"
#include"caidalibre.h"
#include"obstaculo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void NuevoObstaculo();
    void NuevoParabolico();
    void NuevoEspecial();
private slots:
    void Actualizar();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QList<Obstaculo*>Obstaculos;
    QList<CaidaLibre*>Especiales;
    QList<Parabolico*>Parabolicos;

    QGraphicsScene *escena;
    Parabolico *parabolico;
    CaidaLibre *especial;
    Obstaculo *obs;

    int contTime=0;
};

#endif // MAINWINDOW_H

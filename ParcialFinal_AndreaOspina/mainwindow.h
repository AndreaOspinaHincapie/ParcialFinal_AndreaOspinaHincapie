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
private slots:
    void Actualizar();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *escena;
    Parabolico *parabolico;
    CaidaLibre *especial;
    Obstaculo *obs;
};

#endif // MAINWINDOW_H

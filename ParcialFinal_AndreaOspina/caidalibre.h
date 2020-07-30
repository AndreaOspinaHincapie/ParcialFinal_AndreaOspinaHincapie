#ifndef CAIDALIBRE_H
#define CAIDALIBRE_H

#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsScene>
#include<math.h>
#include"obstaculo.h"

class CaidaLibre: public QGraphicsItem
{
    //Sin velocidad en X.
private:
    double posX=0, posY=0, V0=0, Vy=0;
    double radio=20;//constante
    double a=9.8,delta=1;
public:
    CaidaLibre(double _posX, double _posY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void rebotar();
    void ActualizarPosicion();
    void ActualizarVelocidad();
    void Desaparecer();
};

#endif // CAIDALIBRE_H

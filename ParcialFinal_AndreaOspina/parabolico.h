#ifndef PARABOLICO_H
#define PARABOLICO_H

#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsScene>
#include<math.h>
#include"obstaculo.h"
class Parabolico: public QGraphicsItem
{
private:
    double posX=0, posY=0, Vx=0,Vy=0, V0y=0;
    double radio=20;//constante
    double a=9.8,delta=1; //delta: cambio en el tiempo (variar segun timer para mayor o
                            //menor velocidad de la animacion)
public:
    Parabolico(double _posX, double _posY, double VelX, double VelY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void rebotar();
    void ActualizarPosicion();
    void ActualizarVelocidad();
    void Desaparecer();
};

#endif // PARABOLICO_H

#include "parabolico.h"

Parabolico::Parabolico(double _posX, double _posY, double VelX, double VelY)
{
    posX=_posX;
    posY=_posY;
    Vx=VelX;
    Vy=VelY;
    V0y=VelY;
    setPos(posX,posY);

}

QRectF Parabolico::boundingRect() const
{
   return QRectF(-radio,-radio,2*radio,2*radio);
}

void Parabolico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

void Parabolico::rebotar()
{
    QList<QGraphicsItem*> colliding=collidingItems();
    for(int i=0;i<colliding.size();i++){
        if(typeid(colliding.at(i))==typeid (Obstaculo)){
            Vy=-Vy;
            qDebug()<<"Colision con obstaculo";
        }
    }
    if(posX<1 || posX>580){
        Vx=-Vx;
    }

}

void Parabolico::ActualizarPosicion()
{
    //Segun ecuaciones de MRUA
        ActualizarVelocidad();
        rebotar();
        posX+=Vx*delta;
        posY-=Vy*delta-0.5*a*delta*delta; //Resta por sistema de coordenadas de la escena
        setPos(posX,posY);
}

void Parabolico::ActualizarVelocidad()
{
    Vy=V0y-a*delta;

}

void Parabolico::Desaparecer()
{
    scene()->removeItem(this);
}

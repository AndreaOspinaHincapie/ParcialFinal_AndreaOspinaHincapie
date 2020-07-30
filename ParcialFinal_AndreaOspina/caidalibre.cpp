#include "caidalibre.h"


CaidaLibre::CaidaLibre(double _posX, double _posY)
{
    posX=_posX;
    posY=_posY;
    setPos(posX,posY);
}

QRectF CaidaLibre::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);
}

void CaidaLibre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void CaidaLibre::rebotar()
{
    QList<QGraphicsItem*>colliding=collidingItems();
    for(int i=0; i<colliding.size();i++){
        if(typeid(colliding.at(i))==typeid (Obstaculo)){
            Vy=-Vy;
            radio-=5;
        }
    }



}

void CaidaLibre::ActualizarPosicion()
{
    //Segun ecuaciones de MRUA
        ActualizarVelocidad();
        rebotar();
        posY-=Vy*delta-0.5*a*delta*delta; //Resta por sistema de coordenadas de la escena
        setPos(posX,posY);
}

void CaidaLibre::ActualizarVelocidad()
{
     Vy=V0-a*delta;

}

void CaidaLibre::Desaparecer()
{
    scene()->removeItem(this);
}

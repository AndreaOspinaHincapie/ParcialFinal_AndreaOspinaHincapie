#ifndef OBSTACULO_H
#define OBSTACULO_H

#include<QGraphicsItem>
#include<QPainter>
class Obstaculo: public QGraphicsItem
{
private:
    double posX=0,posY=0,ancho=0,alto=20;//solo alto será constante
    int tiempoVida=5;
public:
    Obstaculo(double _posx,double _posy, double _ancho);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    int getTiempoVida() const;
    void setTiempoVida(int value);
};

#endif // OBSTACULO_H

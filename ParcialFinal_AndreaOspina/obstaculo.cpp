#include "obstaculo.h"
int Obstaculo::getTiempoVida() const
{
    return tiempoVida;
}

void Obstaculo::setTiempoVida(int value)
{
    tiempoVida = value;
}

Obstaculo::Obstaculo(double _posx, double _posy, double _ancho)
{
    posX=_posx;
    posY=_posy;
    ancho=_ancho;
    setPos(posX,posY);
}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(posX,posY,ancho,alto);
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::magenta);
    painter->drawRect(boundingRect());
}

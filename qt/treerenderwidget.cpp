#include "treerenderwidget.h"

#include <QPainter>

treerenderwidget::treerenderwidget(QWidget *parent):
    QWidget(parent)
{

}

void treerenderwidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    int w = this->width();
    int h = this->height();

    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(4);
    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);

//    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawEllipse(200,20, DIAMETER, DIAMETER);
    painter.drawEllipse(140,150, DIAMETER, DIAMETER);
    painter.drawEllipse(250,150, DIAMETER, DIAMETER);
    painter.drawLine(200+DIAMETER/2,20+DIAMETER,140+DIAMETER/2,150);
    painter.drawLine(200+DIAMETER/2,20+DIAMETER,250+DIAMETER/2,150);
}

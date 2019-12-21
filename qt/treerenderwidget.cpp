#include "treerenderwidget.h"

#include <iostream>
#include <QPainter>

treerenderwidget::treerenderwidget(QWidget *parent):
    QWidget(parent)
{
    this->setFixedSize(800,600);
//    this->setWindowState(Qt::WindowMaximized);
    this->show();
}

void treerenderwidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    int W = this->width();
    int H = this->height();
    Q_UNUSED(H)

    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(4);
    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);

    painter.setRenderHint(QPainter::Antialiasing, true);
/*  root=>[(W/2-DIAMETER/2),BORDER_GAP]
 *  root->lChild=>[(W/2-DIAMETER/2-HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP]
 *  root->rChild=>[(W/2-DIAMETER/2+HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP]
 */

    int curDepth = 0;
    int tarDepth = 5;
    drawRecursively(painter,W/2-DIAMETER/2,BORDER_GAP,curDepth,tarDepth);

//    painter.drawLine(W/2-DIAMETER/2,BORDER_GAP,W/2-DIAMETER/2-HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP);
//    painter.drawLine(W/2-DIAMETER/2,BORDER_GAP,W/2-DIAMETER/2+HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP);

//    painter.drawLine(W/2-DIAMETER/2-HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP,W/2-DIAMETER/2-HORIZONTAL_GAP*2,BORDER_GAP+VERTICAL_GAP*2);
//    painter.drawLine(W/2-DIAMETER/2-HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP,W/2-DIAMETER/2-HORIZONTAL_GAP*0,BORDER_GAP+VERTICAL_GAP*2);


//    painter.drawLine(W/2-DIAMETER/2+HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP,W/2-DIAMETER/2+HORIZONTAL_GAP*2,BORDER_GAP+VERTICAL_GAP*2);
//    painter.drawLine(W/2-DIAMETER/2+HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP,W/2-DIAMETER/2+HORIZONTAL_GAP*0,BORDER_GAP+VERTICAL_GAP*2);



//    painter.drawEllipse(200,20, DIAMETER, DIAMETER);
//    painter.drawEllipse(140,150, DIAMETER, DIAMETER);
//    painter.drawEllipse(250,150, DIAMETER, DIAMETER);
//    painter.drawLine(200+DIAMETER/2,20+DIAMETER,140+DIAMETER/2,150);
//    painter.drawLine(200+DIAMETER/2,20+DIAMETER,250+DIAMETER/2,150);


    std::cout << "OK!" << '\n';
}

void treerenderwidget::drawRecursively(QPainter &painter, int x, int y,int curDepth,const int tarDepth)
{


    painter.drawEllipse(x-DIAMETER/2,y-DIAMETER/2,DIAMETER,DIAMETER);
    painter.drawLine(x,y,x-HORIZONTAL_GAP,y+VERTICAL_GAP);
    painter.drawLine(x,y,x+HORIZONTAL_GAP,y+VERTICAL_GAP);

    if(curDepth == tarDepth){
        return;
    }
    else{

        drawRecursively(painter,x-HORIZONTAL_GAP,y+VERTICAL_GAP,curDepth+1,tarDepth);
        drawRecursively(painter,x+HORIZONTAL_GAP,y+VERTICAL_GAP,curDepth+1,tarDepth);
    }
}

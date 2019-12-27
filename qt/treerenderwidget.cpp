#include "treerenderwidget.h"

#include <iostream>
#include <QPainter>
#include <QFont>
#include <QApplication>
#include <fstream>
#include <iostream>
#include <sstream>

treerenderwidget::treerenderwidget(QWidget *parent/*,std::string source_path,std::string saving_path*/):
    QWidget(parent)
{
//    this->source_path = source_path;
//    this->saving_path = saving_path;
    this->setFixedSize(640*stiffness,480*stiffness);
//    this->setWindowState(Qt::WindowMaximized);
    this->show();
}

void treerenderwidget::read_file(){
    std::ifstream file(saving_path, std::ios::in);
    std::cout << this->saving_path << std::endl;
    while(!file.eof()){
        std::string each_line;
        std::getline(file,each_line);
        std::stringstream ss(each_line);
        std::string each_word;
        ss>>each_word;
        std::string ch = each_word;
        ss>>each_word;
        int tag = each_word[0]-'0';
        ss>>each_word;
        std::string freq = each_word;
        ss>>each_word;
        std::string code = each_word;
//        std::cout<< ch << " " << tag << " " << freq << " " << code << std::endl;
        this->nodes.push_back(node(ch,tag,freq,code));
    }
    nodes.pop_back();
    file.close();
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
    pen.setWidth(1);
    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    QFont font("微软雅黑",10,QFont::Thin,false);
    font.setLetterSpacing(QFont::AbsoluteSpacing,1);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setFont(font);

    painter.setRenderHint(QPainter::Antialiasing, true);
/*  root=>[(W/2-DIAMETER/2),BORDER_GAP]
 *  root->lChild=>[(W/2-DIAMETER/2-HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP]
 *  root->rChild=>[(W/2-DIAMETER/2+HORIZONTAL_GAP,BORDER_GAP+VERTICAL_GAP]
 */

    int curDepth = 0;
    int tarDepth = 5;
    drawRecursively(painter,W/2-DIAMETER/2,BORDER_GAP,curDepth,tarDepth,this->HORIZONTAL_GAP);
    brush.setColor(Qt::red);
    painter.setBrush(brush);
    addOn(painter);
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

void treerenderwidget::drawRecursively(QPainter &painter, int x, int y,int curDepth,const int tarDepth,int hGap)
{




    if(curDepth == tarDepth){
        painter.drawEllipse(x-DIAMETER/2,y-DIAMETER/2,DIAMETER,DIAMETER);
        painter.drawText(x-DIAMETER/4,y+DIAMETER/4,tr("-1"));
//        painter.drawText(x-DIAMETER/4,y+DIAMETER,tr("a"));
        return;
    }
    else{
        painter.drawLine(x,y,x-hGap,y+VERTICAL_GAP);
        painter.drawLine(x,y,x+hGap,y+VERTICAL_GAP);
        painter.drawEllipse(x-DIAMETER/2,y-DIAMETER/2,DIAMETER,DIAMETER);
        painter.drawText(x-DIAMETER/4,y+DIAMETER/4,tr("-1"));

        painter.drawText(x-hGap/2-DIAMETER/2,y+VERTICAL_GAP/2,tr("0"));
        painter.drawText(x+hGap/2,y+VERTICAL_GAP/2,tr("1"));

        drawRecursively(painter,x-hGap,y+VERTICAL_GAP,curDepth+1,tarDepth,hGap/2);
        drawRecursively(painter,x+hGap,y+VERTICAL_GAP,curDepth+1,tarDepth,hGap/2);
    }
}

void treerenderwidget::addOn(QPainter& painter){
    int x = this->width()/2-DIAMETER/2;
    int y = BORDER_GAP;
    for(auto node : nodes){
        if(node.tag == 2){
            painter.drawEllipse(x-DIAMETER/2,y-DIAMETER/2,DIAMETER,DIAMETER);
            painter.drawText(x-DIAMETER/4,y+DIAMETER/4,QString::fromStdString(node.freq));
            QPen pen;
            pen.setColor(Qt::blue);
            pen.setWidth(10);
            painter.setPen(pen);
            painter.drawText(x-DIAMETER/4+4,y+DIAMETER,QString::fromStdString(node.ch));
            pen.setColor(Qt::black);
            pen.setWidth(1);
            painter.setPen(pen);
            continue;
        }

        int posx = x;
        int hg = HORIZONTAL_GAP;
        for(int i = 0 ; i < node.code.length();i++){
            if(node.code[i]=='0'){
                posx -= hg;
            }
            else if(node.code[i]=='1'){
                posx += hg;
            }
            hg /= 2;
        }
        int posy = y + node.code.length()*VERTICAL_GAP;
        painter.drawEllipse(posx-DIAMETER/2,posy-DIAMETER/2,DIAMETER,DIAMETER);
        painter.drawText(posx-DIAMETER/4,posy+DIAMETER/4,QString::fromStdString(node.freq));
        QPen pen;
        pen.setColor(Qt::blue);
        pen.setWidth(10);
        painter.setPen(pen);
        painter.drawText(posx-DIAMETER/4+4,posy+DIAMETER,QString::fromStdString(node.ch));
        pen.setColor(Qt::black);
        pen.setWidth(1);
        painter.setPen(pen);
    }
}

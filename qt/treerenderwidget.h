#ifndef TREERENDERWIDGET_H
#define TREERENDERWIDGET_H

#include <QWidget>

class treerenderwidget:public QWidget
{
    Q_OBJECT
public:
    explicit treerenderwidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int stiffness = 3;
    const int DIAMETER = 15*stiffness/2;
    const int VERTICAL_GAP = 50*stiffness;
    const int HORIZONTAL_GAP = 100*stiffness;
    const int BORDER_GAP = 20*stiffness;
    void drawRecursively(QPainter& painter,int x, int y, int curDepth,const int tarDepth,int hGap);
};


#endif // TREERENDERWIDGET_H

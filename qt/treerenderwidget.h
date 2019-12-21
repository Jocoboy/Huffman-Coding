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
    const int DIAMETER = 15;
    const int VERTICAL_GAP = 30;
    const int HORIZONTAL_GAP = 40;
    const int BORDER_GAP = 20;
    void drawRecursively(QPainter& painter,int x, int y, int curDepth,const int tarDepth);
};


#endif // TREERENDERWIDGET_H

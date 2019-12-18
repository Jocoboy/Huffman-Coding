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
    const int DIAMETER = 50;
    const int HEIGHT = 30;
};


#endif // TREERENDERWIDGET_H

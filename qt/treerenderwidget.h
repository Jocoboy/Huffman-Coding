#ifndef TREERENDERWIDGET_H
#define TREERENDERWIDGET_H

#include <QWidget>
#include <string>
#include <vector>

class treerenderwidget:public QWidget
{
    Q_OBJECT
public:
    std::string source_path;
    std::string saving_path;
    struct node{
        std::string ch;   // char -> string
        int tag;
        std::string freq; // int -> string
        std::string code;
        node();
        node(std::string ch,int tag,std::string freq,std::string code):ch(ch),tag(tag),freq(freq),code(code){}
    };
    std::vector<node> nodes;
    void read_file();
    explicit treerenderwidget(QWidget *parent = nullptr/*,std::string source_path="",std::string saving_path=""*/);
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int stiffness = 3;
    const int DIAMETER = 15*stiffness;
    const int VERTICAL_GAP = 50*stiffness;
    const int HORIZONTAL_GAP = 150*stiffness;
    const int BORDER_GAP = 20*stiffness;

    void drawRecursively(QPainter& painter,int x, int y, int curDepth,const int tarDepth,int hGap);
    void addOn(QPainter& painter);
};


#endif // TREERENDERWIDGET_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "F:\Github\repositories\Huffman-Coding\HuffmanTree.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSize>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QPaintEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Huffman Coding");

    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    QLabel *label1 = new QLabel(centralWidget);
    label1->setText("Source path:");
    QLabel *label2 = new QLabel(centralWidget);
    label2->setText("Saving path:");

    QLineEdit *edit1 = new QLineEdit(centralWidget);
    edit1->setMinimumSize(QSize(400,10));
    edit1->setText("F:\\Github\\repositories\\Huffman-Coding\\original_text.txt");
    QLineEdit *edit2 = new QLineEdit(centralWidget);
    edit2->setText("F:\\Github\\repositories\\Huffman-Coding\\huffman_tree.txt");
    edit2->setMinimumSize(QSize(400,10));

    QGridLayout *layout = new QGridLayout(centralWidget);
    layout->addWidget(label1, 0, 0,Qt::AlignLeft);
    layout->addWidget(edit1, 0, 1);
    layout->addWidget(label2, 1, 0,Qt::AlignLeft);
    layout->addWidget(edit2, 1, 1);

    QHBoxLayout *hbox;
    layout->addLayout(hbox = new QHBoxLayout, 2, 0);
    QPushButton *btn = new QPushButton("Launch");
    connect(btn, SIGNAL(clicked()),SLOT(on_pushButton_clicked()));
    hbox->addWidget(btn);

    centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QList<QLineEdit*> editList = this->findChildren<QLineEdit*>();
    QString Qsource_path = editList[0]->text();
    QString Qsaving_path = editList[1]->text();

    HuffmanTree hf_2(HuffmanTree::get_inner_text(Qsource_path.toStdString()));
    hf_2.print_original_text();
    hf_2.encode();
    hf_2.print_encoded_string();
    hf_2.print_encode_table();
    hf_2.decode();
    hf_2.print_decoded_text();
//    hf_2.save_as_txt(Qsaving_path.toStdString());
//    hf_2.append_to_txt(Qsource_path.toStdString());

    QMessageBox msg;
    msg.setText("Successfully Launched!");
    msg.exec();



    dialog = new QDialog(this);
    renderWidget = new treerenderwidget(dialog);
    dialog->setWindowTitle("Huffman Tree");
    dialog->resize(800,600);
    dialog->setGeometry(400,300,800,600);
    dialog->setWhatsThis("Huffman Tree Visualization");
//    dialog->setWindowState(Qt::WindowMaximized);
    dialog->show();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    int w = this->width();
    int h = this->height();

    painter.setRenderHint(QPainter::Antialiasing, true);

    QRadialGradient radial(w/2, h/2, qMax(w/2,h/2), w/2, h/2);
    radial.setColorAt(0, Qt::white);
    radial.setColorAt(1, Qt::gray);
    radial.setSpread(QGradient::ReflectSpread);

    painter.setBrush(radial);
    painter.drawRect(this->rect());
}

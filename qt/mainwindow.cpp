#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "F:\Github\repositories\Huffman-Coding\HuffmanTree.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAction>
#include <QMessageBox>
#include <QSize>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Huffman Coding");

    widget = new QWidget(this);
    this->setCentralWidget(widget);

    QLabel *label1 = new QLabel(widget);
    label1->setText("Source path:");
    QLabel *label2 = new QLabel(widget);
    label2->setText("Saving path:");

    QLineEdit *edit1 = new QLineEdit(widget);
    edit1->setMinimumSize(QSize(400,10));
    edit1->setText("F:\\Github\\repositories\\Huffman-Coding\\");
    QLineEdit *edit2 = new QLineEdit(widget);
    edit2->setText("F:\\Github\\repositories\\Huffman-Coding\\");

    QGridLayout *layout = new QGridLayout(widget);
    layout->setRowStretch(0,1);
    layout->setColumnStretch(3,1);
    layout->addWidget(label1, 1, 1);
    layout->addWidget(edit1,1,2);
    layout->addWidget(label2, 2, 1);
    layout->addWidget(edit2, 2, 2);

    QHBoxLayout *hbox;
    layout->addLayout(hbox = new QHBoxLayout, 3, 2);
    hbox->addStretch(1);
    QPushButton *btn = new QPushButton("Launch");
    //btn->setObjectName("pushButton");
    connect(btn, SIGNAL(clicked()),SLOT(on_pushButton_clicked()));
    hbox->addWidget(btn);

    layout->setRowStretch(4,1);
    layout->setColumnStretch(0,1);

    widget->setLayout(layout);
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
    hf_2.save_as_txt(Qsaving_path.toStdString());
    hf_2.append_to_txt(Qsource_path.toStdString());

    QMessageBox msg;
    msg.setText("Successfully Launched!");
    msg.exec();
}

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Huffman Coding");

    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);

    QLabel label1;
    label1.setText("Source path:");
    QLabel label2;
    label2.setText("Saving path:");

    QLineEdit edit1;
    QLineEdit edit2;

    QGridLayout *layout = new QGridLayout();
    layout->setRowStretch(0,1);
    layout->setColumnStretch(3,1);
    layout->addWidget(&label1, 1, 1);
    layout->addWidget(&edit1,1,2);
    layout->addWidget(&label2, 2, 1);
    layout->addWidget(&edit2, 2, 2);

    QHBoxLayout *hbox;
    layout->addLayout(hbox = new QHBoxLayout, 3, 2);
    hbox->addStretch(1);
    QPushButton *btn = new QPushButton("Launch");
    btn->setObjectName("pushButton");
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
    HuffmanTree hf_2(HuffmanTree::get_inner_text());
    hf_2.print_original_text();
    hf_2.encode();
    hf_2.print_encoded_string();
    hf_2.print_encode_table();
    hf_2.decode();
    hf_2.print_decoded_text();
    hf_2.save_as_txt();
    hf_2.append_to_txt();

    QMessageBox msg;
    msg.setText("Successfully Launched!");
    msg.exec();
}

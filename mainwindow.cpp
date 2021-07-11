#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "collection.h"
#include "item.h"
#include "furniture.h"
#include "tech.h"
#include <iostream>
#include <QMessageBox>

Collection fc;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fc.fromFile("C:\\Users\\andre\\Documents\\laba1p3\\test.txt");
    string t = "";
    for(int i=0;i<fc.getLength();i++){
        t+= fc.get(i)->getType();
        t+= " " + fc.get(i)->getInformation();
        t+= "\n";
    }
    ui->textEdit->setText(QString::fromStdString(t));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    ui->lineEdit_10->setEnabled(!checked);
    ui->lineEdit_9->setEnabled(checked);
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    ui->lineEdit_10->setEnabled(checked);
    ui->lineEdit_9->setEnabled(!checked);
}

void MainWindow::on_pushButton_clicked()
{
    QLineEdit *le[8];
    le[0] = ui->lineEdit;
    le[1] = ui->lineEdit_2;
    le[2] = ui->lineEdit_4;
    le[3] = ui->lineEdit_6;
    le[4] = ui->lineEdit_7;
    le[5] = ui->lineEdit_5;
    le[6] = ui->lineEdit_9;
    le[7] = ui->lineEdit_10;
    bool isFilled = true;
    for(int i=0;i<8;i++){
        if(le[i]->text().toStdString() == ""){
            isFilled = false;
            if(ui->radioButton->isChecked() && le[6]->text().toStdString() != "") {
                isFilled = true;
            }
            if(ui->radioButton_2->isChecked() && le[7]->text().toStdString() != "") {
                isFilled = true;
            }
        }
    }
    if(!isFilled) {
        QMessageBox msgBox;
        msgBox.setText("Cannot add new element");
        msgBox.exec();
    } else {
        double x = ui->lineEdit->text().toDouble();
        double y = ui->lineEdit_2->text().toDouble();
        double z = ui->lineEdit_4->text().toDouble();
        double length = ui->lineEdit_6->text().toDouble();
        double width = ui->lineEdit_7->text().toDouble();
        double height = ui->lineEdit_5->text().toDouble();
        string type = ui->radioButton->isChecked() ? "Furniture" : "Tech";
        string info;
        if(type == "Furniture"){
            info = ui->lineEdit_9->text().toStdString();
        } else {
            info = ui->lineEdit_10->text().toStdString();
        }
    fc.add(info, x, y, z, length, width, height, type);
    string t = "";
    for(int i=0;i<fc.getLength();i++){
        t+= fc.get(i)->getType();
        t+= " " + fc.get(i)->getInformation();
        t+= "\n";
    }
    ui->textEdit->setText(QString::fromStdString(t));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    fc.clearall();
    string t = "";
    for(int i=0;i<fc.getLength();i++){
        t+= fc.get(i)->getType();
        t+= " " + fc.get(i)->getInformation();
        t+= "\n";
    }
    ui->textEdit->setText(QString::fromStdString(t));
}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_8->text().toInt();
    fc.del(id);
    ui->lineEdit_8->setText("");
    string t = "";
    for(int i=0;i<fc.getLength();i++){
        t+= fc.get(i)->getType();
        t+= " " + fc.get(i)->getInformation();
        t+= "\n";
    }
    ui->textEdit->setText(QString::fromStdString(t));
}

void MainWindow::on_pushButton_4_clicked()
{
    string path = ui->textEdit_2->toPlainText().toStdString();
    fc.fromFile(path);
    string t = "";
    for(int i=0;i<fc.getLength();i++){
        t+= fc.get(i)->getType();
        t+= " " + fc.get(i)->getInformation();
        t+= "\n";
    }
    ui->textEdit->setText(QString::fromStdString(t));
}

void MainWindow::on_pushButton_5_clicked()
{
    string path = ui->textEdit_2->toPlainText().toStdString();
    cout << path << endl;
    fc.toFile(path);
}

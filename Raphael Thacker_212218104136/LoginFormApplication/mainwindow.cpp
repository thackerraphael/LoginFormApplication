#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString user=ui->lineEdit_username->text();
     QString pwd=ui->lineEdit_password->text();
     if(user=="student"&&pwd=="13579")
     {
         QMessageBox::information(this,"Success","Username and Password is correct!");
         loop=new Dialog(this);
         loop->show();
         ui->statusbar->showMessage("App will be killed within 5 seconds",5000);


     }
     else
     {
         QMessageBox::warning(this,"Error","Incorrect Username or Password:(");
     }
}

#include "widget.h"
#include "ui_widget.h"
#include<QFontDialog>
#include<QMessageBox>
#include<QDebug>
#include<QColorDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_fontcolor_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::WindowText);
    QColor chosen_color = QColorDialog::getColor(color,this,"Choose text color");
    if(chosen_color.isValid())
    {
        palette.setColor(QPalette::WindowText, chosen_color);
        ui->label->setPalette(palette);
        qDebug()<<"User chosen a valid color";
    }
    else
    {
        qDebug()<<"User chosen an invalid color";
    }
}

void Widget::on_pushButton_bgcolor_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::Window);
    QColor chosen_color = QColorDialog::getColor(color,this,"Choose background color");
    if(chosen_color.isValid())
    {
        palette.setColor(QPalette::Window, chosen_color);
        ui->label->setPalette(palette);
        qDebug()<<"User chosen a valid color";
    }
    else
    {
        qDebug()<<"User chosen an invalid color";
    }

}

void Widget::on_pushButton_font_clicked()
{
    bool ok;
    QFont font_color = QFontDialog::getFont(&ok,QFont("Times new roman,10"),this);
    if(ok)
    {
        ui->label->setFont(font_color);
    }
    else
    {
        QMessageBox::information(this,"Message","User didn't choose any font");
    }
}

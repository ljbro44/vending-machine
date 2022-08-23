#include "widget.h"
#include "ui_widget.h"
#include <qmessagebox.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbMango->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    checkMoney();
}

void Widget::checkMoney()
{
    if(money<100)
    {
        ui->pbCoffee->setEnabled(false);
    }
    else
    {
        ui->pbCoffee->setEnabled(true);
    }

    if(money<300)
    {
        ui->pbMilk->setEnabled(false);
    }
    else
    {
        ui->pbMilk->setEnabled(true);
    }

    if(money<500)
    {
        ui->pbMango->setEnabled(false);
    }
    else
    {
        ui->pbMango->setEnabled(true);
    }

}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-300);
}

void Widget::on_pbMango_clicked()
{
    changeMoney(-500);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    int change1 = money/500;
    int change2 = (money%500)/100;
    int change3 = ((money%500)%100)/50;
    int change4 = (((money%500)%100)%50)/10;
    msgBox.information(NULL, "Reset","500: " + QString::number(change1)+" "+
                                     "100: " + QString::number(change2)+" "+
                                     "50: "  + QString::number(change3)+" "+
                                     "10: "  + QString::number(change4)+" ");
    money = 0;
    changeMoney(money);

}

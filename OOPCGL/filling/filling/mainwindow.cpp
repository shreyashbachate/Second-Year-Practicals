#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QColor"
#include "QColorDialog"
#include <iostream>
#include<QPainter>

using namespace std;
QColor c;
static QImage img(500, 500, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pos = 0;
       start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    c = qRgb(0,0,0);
        for(int y =0; y < 500; y++){
            dda(0, y, 499, y);
            ui->label->setPixmap(QPixmap::fromImage(img));

        }
        ui->label->setPixmap(QPixmap::fromImage(img));

        start=true;
        pos=0;
        c = QColorDialog::getColor();


}


void MainWindow::on_pushButton_2_clicked()
{
    c = QColorDialog::getColor();

        arr1[pos] = arr1[0];
        arr2[pos] = arr2[0];
        for(i = 0; i < pos; i++)
        {
            dy = arr2[i + 1] - arr2[i];
            dx = arr1[i + 1] - arr1[i];
            if(dx == 0.0f)
                {slp[i] = 1.0f;}
            if(dy == 0.0f)
                {slp[i] = 0.0f;}
            if(dx != 0.0f && dy != 0.0f)
            {
                slp[i] = dx / dy;
            }
        }


        for(int y =0; y < 500; y++)
        {
            k = 0;
            for(i =0; i < pos; i++)
            {
                if(((arr2[i] <= y) && (arr2[i + 1] > y))||((arr2[i + 1] <= y) && (arr2[i] > y)))
                {
                    xi[k] = int(arr1[i] + (slp[i] * (y - arr2[i])));
                    k ++;
                }
            }


            for(i = 0; i < k - 1; i++)
            {
                for(j = 0; j < k - 1 - i; j++)
                {
                    if(xi[j] > xi[j + 1])
                    {
                        temp = xi[j];
                        xi[j] = xi[j + 1];
                        xi[j + 1] = temp;
                    }
                }
            }

            for(j = 0; j < k; j+=2)
            {
                dda(xi[j], y, xi[j + 1] + 1, y);


            }
        }
        ui->label->setPixmap(QPixmap::fromImage(img));

}
void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    float dx, dy, step, i, x , y;
    float Xinc, Yinc;
    dx = x2 - x1;
    dy = y2-y1;
    if(abs(dx) >= abs (dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    Xinc = dx/step;
    Yinc=dy/step;

    i = 0;
    x = x1;
    y = y1;
    while(i <= step)
    {

        img.setPixel(x,y,c.rgb());
        x = x + Xinc;
        y = y + Yinc;
        i++;
    }
     ui->label->setPixmap(QPixmap::fromImage(img));

}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{

    if (start){
        int p = ev->pos().x();
        int q = ev->pos().y();
        arr1[pos] = p;
        arr2[pos] = q;
        if (ev->button() == Qt::RightButton){
            dda(arr1[0], arr2[0], arr1[pos], arr2[pos]);
            dda(arr1[pos - 1], arr2[pos - 1], arr1[pos], arr2[pos]);
            ui->label->setPixmap(QPixmap::fromImage(img));

            start = false;
        }
        else{
            if (pos > 0){
                dda(arr1[pos - 1], arr2[pos - 1], arr1[pos], arr2[pos]);
                ui->label->setPixmap(QPixmap::fromImage(img));

            }
        }
        pos++;
    }
  ui->label->setPixmap(QPixmap::fromImage(img));

}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
     QPainter qp(this);
     //bresenhams(&qp);

}

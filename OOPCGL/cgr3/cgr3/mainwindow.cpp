#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage img(500,500, QImage :: Format_RGB888);
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


void MainWindow::on_pushButton_clicked()
{
    int x1, y1, x2, y2;
        x1 = ui->textEdit->toPlainText().toInt();
        y1 = ui->textEdit_2->toPlainText().toInt();
        x2 = ui-> textEdit_3->toPlainText().toInt();
        y2 = ui-> textEdit_4->toPlainText().toInt();
        dda(x1,y1,x2,y2);
//        dda(140,55,140,136);
//        dda(140,136,284,136);
//        dda(284,55,284,136);
//        dda(140,55,284,55);
//        dda(140,95,212,55);
//        dda(212,55,284,95);
//        dda(212,137,140,95);
//        dda(284,95,212,136);

//     bresenham(212,95,37);
        ui->label5->setPixmap(QPixmap :: fromImage(img));
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

        img.setPixel(x,y, qRgb(255,255,255));
        x = x + Xinc;
        y = y + Yinc;
        i++;
    }

}
void MainWindow::bresenham(int x1,int y1,int r)
{
    float x,y,p;
           x=0;
           y=r;
           p=3-(2*r);
           while(x<=y)
           {
               img.setPixel(x1+x,y1+y,qRgb(255,255,255));
               img.setPixel(x1-x,y1+y,qRgb(255,255,255));
               img.setPixel(x1+x,y1-y,qRgb(255,255,255));
               img.setPixel(x1-x,y1-y,qRgb(255,255,255));
               img.setPixel(x1+y,y1+x,qRgb(255,255,255));
               img.setPixel(x1+y,y1-x,qRgb(255,255,255));
               img.setPixel(x1-y,y1+x,qRgb(255,255,255));
              img.setPixel(x1-y,y1-x,qRgb(255,255,255));
               x=x+1;
               if(p<0)
               {
                    p=p+4*(x)+6;
               }
               else
               {
                    p=p+4*(x-y)+10;
                    y=y-1;
               }

          }
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1, y1, r;
    x1 = ui->textEdit_6->toPlainText().toInt();
    y1 = ui->textEdit_5->toPlainText().toInt();
    r = ui-> textEdit_7->toPlainText().toInt();
    bresenham(x1,y1,r);
    ui->label5->setPixmap(QPixmap :: fromImage(img));
}


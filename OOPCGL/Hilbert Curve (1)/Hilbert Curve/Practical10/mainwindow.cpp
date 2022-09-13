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

void MainWindow ::  move(int j,int h,int &x,int &y)
{
int Xb,Yb;
Xb = x;
Yb = y;
    if(j==1)
        y-=h;
    else if(j==2)
        x+=h;
    else if(j==3)
        y+=h;
    else if(j==4)
        x-=h;
DDA(Xb,Yb,x,y);
}

void MainWindow :: hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y)
{
if(i>0)
{
i--;
hilbert(d,r,u,l,i,h,x,y);
move(r,h,x,y);
hilbert(r,d,l,u,i,h,x,y);
move(d,h,x,y);
hilbert(r,d,l,u,i,h,x,y);
move(l,h,x,y);
hilbert(u,l,d,r,i,h,x,y);
}
}
void MainWindow :: DDA(int x1, int y1, int x2, int y2)
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


void MainWindow::on_pushButton_clicked()
{


    int n,x,y,h=10,r=2,d=3,l=4,u=1;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    n=ui->textEdit_8->toPlainText().toInt();

    hilbert(r,d,l,u,n,h,x,y);

    ui->label->setPixmap(QPixmap :: fromImage(img));



}


void MainWindow::on_pushButton_2_clicked()
{
    for (int x=0;x<500;++x)
    {
        for(int y=0;y<500;++y)
        {
            img.setPixel(x,y,qRgb(0,0,0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


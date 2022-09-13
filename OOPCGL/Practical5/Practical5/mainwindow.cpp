#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "QMouseEvent"

QImage img(500,500, QImage :: Format_RGB888);
QImage img2(500,500, QImage :: Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    check = false;
    start = true;
    pos = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: window()
{
    DDA(150,150,350,150);
    DDA(350,150,350,350);
    DDA(350,350,150,350);
    DDA(150,350,150,150);
}

void MainWindow :: TBRL(char c[4], float x, float y)
{
    c[0] = (x < 150) ? '1' : '0';
    c[1] = (x > 350) ? '1' : '0';
    c[2] = (y < 150) ? '1' : '0';
    c[3] = (y > 350) ? '1' : '0';
}

void MainWindow :: clipping(char c[], char d[], float &x, float &y, float m)
{
    int flag=1,i=0;
        for (i=3;i>=0;i--)
        {
            if(c[i]!='0' && d[i]!='0')
            {
                flag=0;
//                x= 0;
//                y = 0;
                break;
            }

            if(flag)
            {
                if(c[0]!='0')
                {
                    y=m*(150-x)+y;
                    x=150;
                }
                else if(c[1]!='0')
                {
                    y=m*(350-x)+y;
                    x=350;
                }
                else if(c[2]!='0')
                {
                    x=((150-y)/m)+x;
                    y=150;
                }
                else if(c[3]!='0')
                {
                    x=((350-y)/m)+x;
                    y=350;
                }
            }
            if(flag == 0)
            {
                x = 0;
                y = 0;
            }
            TBRL(c,x,y);
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

    if(!check){
        while(i <= step)
        {

            img.setPixel(x,y, qRgb(255,255,255));
            x = x + Xinc;
            y = y + Yinc;
            i++;
        }
    }
    else{
        while(i <= step)
        {

            img2.setPixel(x,y, qRgb(255,255,255));
            x = x + Xinc;
            y = y + Yinc;
            i++;
        }
    }

}

void MainWindow::on_pushButton_clicked()
{

    check = false;

    window();
    ui->label->setPixmap(QPixmap :: fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    float x1, y1, x2, y2, m;
    char c[4], d[4];

    check = true;


    for(int i = 0; i < pos; i=i+2)
    {
        x1 = x[i];
        y1 = y[i];
        x2 = x[i+1];
        y2 = y[i+1];
        m = float((y2-y1)/(x2-x1));
        TBRL(c,x1,y1);
        TBRL(d,x2,y2);

        clipping(c,d,x1,y1,m);
        clipping(d,c,x2,y2,m);


        DDA(x1,y1,x2,y2);

     }

        window();


    ui->label->setPixmap(QPixmap :: fromImage(img2));

}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{

    if (start){
        int p = ev->pos().x();
        int q = ev->pos().y();
        x[pos] = p;
        y[pos] = q;
        if (pos > 0  && pos % 2 != 0){
                DDA(x[pos - 1], y[pos - 1], x[pos], y[pos]);
                ui->label->setPixmap(QPixmap::fromImage(img));
        }
        pos++;
    }
  ui->label->setPixmap(QPixmap::fromImage(img));

}


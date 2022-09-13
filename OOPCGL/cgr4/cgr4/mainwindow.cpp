#include "mainwindow.h"
#include "ui_mainwindow.h"
#define PI acos(-1)
QImage img(800,500, QImage :: Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->textEdit->setVisible(false);
     ui->textEdit_2->setVisible(false);
     ui->pushButton_3->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
         ui->label_3->clear();
        dda(200,100,150,200);
        dda(250,200,150,200);
        dda(250,200,200,100);
        ui->label->setPixmap(QPixmap :: fromImage(img));
    }
    else if(ui->radioButton_2->isChecked()){
         ui->label_3->clear();
        dda(100,100,50,150);
        dda(50,150,100,200);
        dda(100,200,150,150);
        dda(150,150,100,100);
        ui->label->setPixmap(QPixmap :: fromImage(img));
    }
    else{
        ui->label_3->setText("Select One Of the Options ..");
    }

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
void MainWindow::on_pushButton_2_clicked()
{
    if(ui->radioButton_3->isChecked()){
        ui->label_4->setText("Enter Translation Factor  TX & TY Respectively:");
        ui->textEdit->setVisible(true);
        ui->textEdit_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_3->setText("Translate");

    }
    else if(ui->radioButton_4->isChecked()){
        ui->label_4->setText("Enter Scaling Factor SX & SY Respectively:");
        ui->textEdit->setVisible(true);
        ui->textEdit_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_3->setText("Scale");

    }
    else if(ui->radioButton_5->isChecked()){
        ui->label_4->setText("Enter Rotation Angle");
        ui->textEdit->setVisible(true);
        ui->textEdit_2->setVisible(false);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_3->setText("Rotate");

    }

}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->radioButton->isChecked()){
    int x,y;
    x = ui->textEdit->toPlainText().toInt();
    y = ui->textEdit_2->toPlainText().toInt();
    if(ui->radioButton_3->isChecked()){
    for(int i=0;i<=2;i++){
        for(int j=0;j<2;j++){
            if(j%2==0){
                tri[i][j]=tri[i][j]+x;
            }
            else{
                tri[i][j]=tri[i][j]+y;
            }
        }
    }
    dda(tri[0][0],tri[0][1],tri[1][0],tri[1][1]);
    dda(tri[1][0],tri[1][1],tri[2][0],tri[2][1]);
    dda(tri[2][0],tri[2][1],tri[0][0],tri[0][1]);
    ui->label->setPixmap(QPixmap :: fromImage(img));
    }
    else if(ui->radioButton_4->isChecked()){
    for(int i=0;i<=2;i++){
        for(int j=0;j<2;j++){
            if(j%2!=0){
                tri[i][j]=tri[i][j]*x;
            }
            else{
                tri[i][j]=tri[i][j]*y;
            }
        }
    }
    dda(tri[0][0],tri[0][1],tri[1][0],tri[1][1]);
    dda(tri[1][0],tri[1][1],tri[2][0],tri[2][1]);
    dda(tri[2][0],tri[2][1],tri[0][0],tri[0][1]);
    ui->label->setPixmap(QPixmap :: fromImage(img));
    }
    else if(ui->radioButton_5->isChecked()){
        int c,s;
        int x1,x2,x3,y1,y2,y3;

             c = cos(x * PI /180);
            s = sin(x * PI /180);

            x1 = floor(tri[0][0] * c + tri[0][1] * s);
            y1 = floor(-tri[0][0] * s +tri[0][1] * c);

            x2 = floor(tri[1][0] * c + tri[1][1] * s);
            y2 = floor(-tri[1][0] * s + tri[1][1] * c);

            x3 = floor(tri[2][0] * c + tri[2][1] * s);
            y3 = floor(-tri[2][0] * s + tri[2][1] * c);

//        dda(abs(tri[0][0]),abs(tri[0][1]),abs(tri[1][0]),abs(tri[1][1]));
//        dda(abs(tri[1][0]),abs(tri[1][1]),abs(tri[2][0]),abs(tri[2][1]));
//        dda(abs(tri[2][0]),abs(tri[2][1]),abs(tri[0][0]),abs(tri[0][1]));

             dda(x1+300,y1+250,x2+300,y2+250);
             dda(x2+300,y2+250,x3+300,y3+250);
             dda(x3+300,y3+250,x1+300,y1+250);

        ui->label->setPixmap(QPixmap :: fromImage(img));

    }
    }
    else if(ui->radioButton_2->isChecked()){
        int x,y;
        x = ui->textEdit->toPlainText().toInt();
        y = ui->textEdit_2->toPlainText().toInt();
        if(ui->radioButton_3->isChecked()){
        for(int i=0;i<=3;i++){
            for(int j=0;j<2;j++){
                if(j%2==0){
                    rho[i][j]=rho[i][j]+x;
                }
                else{
                    rho[i][j]=rho[i][j]+y;
                }
            }
        }
        dda(rho[0][0],rho[0][1],rho[1][0],rho[1][1]);
        dda(rho[1][0],rho[1][1],rho[2][0],rho[2][1]);
        dda(rho[2][0],rho[2][1],rho[3][0],rho[3][1]);
        dda(rho[3][0],rho[3][1],rho[0][0],rho[0][1]);
        ui->label->setPixmap(QPixmap :: fromImage(img));

    }
        else if(ui->radioButton_4->isChecked()){
        for(int i=0;i<=3;i++){
            for(int j=0;j<2;j++){
                if(j%2!=0){
                    rho[i][j]=rho[i][j]*x;
                }
                else{
                    rho[i][j]=rho[i][j]*y;
                }
            }
        }
        dda(rho[0][0],rho[0][1],rho[1][0],rho[1][1]);
        dda(rho[1][0],rho[1][1],rho[2][0],rho[2][1]);
        dda(rho[2][0],rho[2][1],rho[3][0],rho[3][1]);
        dda(rho[3][0],rho[3][1],rho[0][0],rho[0][1]);
        ui->label->setPixmap(QPixmap :: fromImage(img));
        }
        else if(ui->radioButton_5->isChecked()){
            int c,s;
            int x1,x2,x3,y1,y2,y3,x4,y4;

                 c = cos(x * PI /180);
                s = sin(x * PI /180);

                x1 = floor(rho[0][0] * c + rho[0][1] * s);
                y1 = floor(-rho[0][0] * s +rho[0][1] * c);

                x2 = floor(rho[1][0] * c + rho[1][1] * s);
                y2 = floor(-rho[1][0] * s + rho[1][1] * c);

                x3 = floor(rho[2][0] * c + rho[2][1] * s);
                y3 = floor(-rho[2][0] * s + rho[2][1] * c);

                x4 = floor(rho[3][0] * c + rho[3][1] * s);
                y4 = floor(-rho[3][0] * s + rho[3][1] * c);
                 dda(x1+300,y1+250,x2+300,y2+250);
                 dda(x2+300,y2+250,x3+300,y3+250);
                 dda(x3+300,y3+250,x4+300,y4+250);
                  dda(x4+300,y4+250,x1+300,y1+250);

            ui->label->setPixmap(QPixmap :: fromImage(img));
}

}
}


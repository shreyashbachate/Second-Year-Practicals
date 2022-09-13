#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int x[20], y[20], pos;
    void window();
    void DDA(int,int,int,int);
    void clipping(char [],char [], float&, float&, float);
    void TBRL(char[],float,float);
    void mousePressEvent(QMouseEvent *ev);

    bool check,start;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

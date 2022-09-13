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
    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
    void dda(int,int,int,int);
    void on_pushButton_2_clicked();



private:
    Ui::MainWindow *ui;
    int pos, arr1[20], arr2[20], i, j, k, xi[20], temp;
        float dx, dy, x, y, slp[20];
        bool start;
};
#endif // MAINWINDOW_H

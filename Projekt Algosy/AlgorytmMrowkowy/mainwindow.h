#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QGraphicsScene>
#include <algorithm.h>
#include <graph.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SzybkoscAnimacji_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *elipse;
    QGraphicsLineItem *line;
    Algorithm Algo;
    Graph g;
};
#endif // MAINWINDOW_H

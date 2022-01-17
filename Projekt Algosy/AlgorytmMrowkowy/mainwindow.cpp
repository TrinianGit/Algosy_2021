#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithm.h"
#include <iostream>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Algo = new Algorithm();
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SzybkoscAnimacji_valueChanged(int value)
{
    QString s = QStringLiteral("Szybkość animacji = %1").arg(value + 1);
    ui->label->setText(s);
    Algo->set_speed(value + 1);

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QString s = QStringLiteral("Ilość mrówek = %1").arg((value + 1) * 10);
    ui->label_2->setText(s);
    Algo->set_ants((value + 1) * 10);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if (value + 1 == 100) {
        value = value - 1;
    }
    QString s = QStringLiteral("Wspł. parowania feromonu = %1").arg((value + 1) * 0.01);
    ui->label_3->setText(s);
    Algo->set_vaporize((value + 1) * 0.01);
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    QString s = QStringLiteral("Wpływ feromonu (alfa) = %1").arg(1 + (value + 1) * 0.03);
    ui->label_4->setText(s);
    Algo->set_alpha(1 + (value + 1) * 0.03);
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    QString s = QStringLiteral("Wpływ dł. trasy (beta) = %1").arg(1.0 + (value + 1) * 0.005);
    ui->label_5->setText(s);
    Algo->set_beta(!.0 + (value + 1) * 0.005);
}

void MainWindow::on_pushButton_5_clicked()
{
    if (!Algo->GetActive()){
        ui->SzybkoscAnimacji->setEnabled(false);
        ui->horizontalSlider->setEnabled(false);
        ui->horizontalSlider_2->setEnabled(false);
        ui->horizontalSlider_3->setEnabled(false);
        ui->horizontalSlider_4->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_6->setEnabled(true);

        if (!Algo->getState()){
            Algo->ChangeActive();
            ui->pushButton_5->setText("Zakończ sym.");
            if (Algo->GetActive()){
                Algo->startAnt();
                ui->pushButton_5->setText("Rozpocznij sym.");
                Algo->ChangeActive();
            }
        }
    }
    else{
        ui->SzybkoscAnimacji->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);
        ui->horizontalSlider_2->setEnabled(true);
        ui->horizontalSlider_3->setEnabled(true);
        ui->horizontalSlider_4->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_5->setText("Rozpocznij sym.");
        if(!Algo->getState()){
            Algo->pendFinish();
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(!Algo->getGraph().get_changingP()){
        ui->label_6->setText("Jesteś w trybie dodawania punktów");
        ui->pushButton->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        std::string file_name = QFileDialog::getOpenFileName(this, tr("Otworz Plik z Punktami"), QDir::currentPath(), "Plik tekstowy (*.txt);;Wszystkie pliki(*.*)").toStdString();
        std::string file_name2 = QFileDialog::getOpenFileName(this, tr("Otworz Plik z Krawedziami"), QDir::currentPath(), "Plik tekstowy (*.txt);;Wszystkie pliki(*.*)").toStdString();
        Algo->getGraph().points_to_graph(file_name);
        Algo->getGraph().connect_points(file_name2, scene);
        ui->label_6->setText("");
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    scene->clear();
    ui->graphicsView->viewport()->update();
    ui->pushButton->setEnabled(true);
    ui->pushButton_5->setEnabled(false);
}

void MainWindow::on_pushButton_6_clicked()
{

}

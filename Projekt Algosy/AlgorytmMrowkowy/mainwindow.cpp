#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithm.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Algo = Algorithm();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SzybkoscAnimacji_valueChanged(int value)
{
    QString s = QStringLiteral("Szybkość animacji = %1").arg(value + 1);
    ui->label->setText(s);

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QString s = QStringLiteral("Ilość mrówek = %1").arg((value + 1) * 10);
    ui->label_2->setText(s);
    Algo.set_ants((value + 1) * 10);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if (value + 1 == 100) {
        value = value - 1;
    }
    QString s = QStringLiteral("Wspł. parowania feromonu = %1").arg((value + 1) * 0.01);
    ui->label_3->setText(s);
    Algo.set_vaporize((value + 1) * 0.01);
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    QString s = QStringLiteral("Wpływ feromonu (alfa) = %1").arg(1 + (value + 1) * 0.03);
    ui->label_4->setText(s);
    Algo.set_alpha(1 + (value + 1) * 0.03);
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    QString s = QStringLiteral("Wpływ dł. trasy (beta) = %1").arg((value + 1) * 0.005);
    ui->label_5->setText(s);
    Algo.set_beta((value + 1) * 0.005);
}

void MainWindow::on_pushButton_5_clicked()
{
    if (!Algo.GetActive()){
        ui->SzybkoscAnimacji->setEnabled(false);
        ui->horizontalSlider->setEnabled(false);
        ui->horizontalSlider_2->setEnabled(false);
        ui->horizontalSlider_3->setEnabled(false);
        ui->horizontalSlider_4->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_5->setText("Zakończ sym.");
    }
    else{
        ui->SzybkoscAnimacji->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);
        ui->horizontalSlider_2->setEnabled(true);
        ui->horizontalSlider_3->setEnabled(true);
        ui->horizontalSlider_4->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_5->setText("Rozpocznij sym.");
    }
    Algo.ChangeActive();
}

void MainWindow::on_pushButton_clicked()
{
    if(!Algo.getGraph().get_changingP()){
        ui->label_6->setText("Jesteś w trybie dodawania punktów");
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
    }
    else{
        ui->label_6->setText("");
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
    }
    Algo.getGraph().change_changingP();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!Algo.getGraph().get_changingP()){
        ui->label_6->setText("Jesteś w trybie usuwania punktów");
        ui->pushButton->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
    }
    else{
        ui->label_6->setText("");
        ui->pushButton->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
    }
    Algo.getGraph().change_changingP();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(!Algo.getGraph().get_changingK()){
        ui->label_6->setText("Jesteś w trybie dodawania połączeń");
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
    }
    else{
        ui->label_6->setText("");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
    }
    Algo.getGraph().change_changingK();
}

void MainWindow::on_pushButton_4_clicked()
{
    if (!Algo.getGraph().get_changingK()){
        ui->label_6->setText("Jesteś w trybie usuwania połączeń");
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
    }
    else{
        ui->label_6->setText("");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
    }
    Algo.getGraph().change_changingK();
}

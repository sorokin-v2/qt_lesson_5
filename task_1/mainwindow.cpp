#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   _timer = new Stopwatch(_timeStep, this);
   _timer->setObjectName("SigTimerCollection");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RcvTimeSignal()
{
   _currentTime += _timeStep / 1000.0;
   ui->lb_time->setText(QString::number(_currentTime, 'f', 1));
}


void MainWindow::on_pbt_startStop_clicked()
{
    if(ui->pbt_laps->isEnabled()){
        _timer->Stop();
        disconnect(_timer, SIGNAL(sig_TimeSignal()), this, SLOT(RcvTimeSignal()));
        ui->pbt_startStop->setText("Старт");
        ui->pbt_laps->setEnabled(false) ;
    }
    else{
         ui->pbt_laps->setEnabled(true) ;
         ui->pbt_startStop->setText("Стоп");
        _timer->Start();
        connect(_timer, SIGNAL(sig_TimeSignal()), this, SLOT(RcvTimeSignal()));
    }
}


void MainWindow::on_pbt_laps_clicked()
{
    ui->te_lapsLog->append("Круг № " + QString::number(++_lapsCount) + ", время: " + ui->lb_time->text() + " сек.");
}


void MainWindow::on_pbt_clear_clicked()
{
   ui->te_lapsLog->clear();
   _lapsCount = 0;
   _currentTime = 0.0;
   if(!ui->pbt_laps->isEnabled()){
       ui->lb_time->setText("0.0");
   }
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Stopwatch* _timer;
    double _currentTime {0.0};
    const int _timeStep {100};   //Шаг обновления времени в мс
    int _lapsCount {0};         //Количество кругов

public slots:
    void RcvTimeSignal(void);
private slots:
    void on_pbt_startStop_clicked();
    void on_pbt_laps_clicked();
    void on_pbt_clear_clicked();
};
#endif // MAINWINDOW_H

#include "stopwatch.h"
//#include "qdebug.h"

Stopwatch::Stopwatch(const int TimeInterval, QObject* parent = nullptr) : QObject{parent}
{
    _timer = new QTimer(this);
    _timer->setInterval(TimeInterval);
}

void Stopwatch::Start()
{
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    _timer->start();
}

void Stopwatch::Stop()
{
    disconnect(_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    _timer->stop();
}

void Stopwatch::SendTimeSignal()
{
    //Код
    emit sig_TimeSignal();
    //Продолжение кода
}

void Stopwatch::updateTime()
{
    emit sig_TimeSignal();
}

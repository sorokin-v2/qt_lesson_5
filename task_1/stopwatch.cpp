#include "stopwatch.h"
//#include "qdebug.h"

Stopwatch::Stopwatch(const int TimeInterval, QObject* parent = nullptr) : QObject{parent}
{
    _timer = new QTimer(this);
    _timer->setInterval(TimeInterval);
}

Stopwatch::~Stopwatch()
{
    delete _timer;
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
    emit sigTimeSignal();
    //Продолжение кода
}

void Stopwatch::updateTime()
{
    emit sigTimeSignal();
}

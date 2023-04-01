#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(const int, QObject* );
    ~Stopwatch();
    void Start( void);
    void Stop(void);
    void SendTimeSignal(void);

private:
    QTimer* _timer;

signals:
    void sigTimeSignal(void);

private slots:
    void updateTime();

};

#endif // STOPWATCH_H

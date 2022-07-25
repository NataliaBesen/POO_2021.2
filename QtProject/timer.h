#ifndef TIMER_H
#define TIMER_H

#include <QtWidgets>
#include <QTimer>
#include <QTime>

class Timer : public QWidget

{
    Q_OBJECT
public:
   explicit Timer(QWidget *parent = nullptr);

   ~Timer();
    void setTime(QString h,QString m);
    QTime getTime();
    void playTimer();
    void pauseTimer();


private slots:
    void updateTime();

private:


    QVBoxLayout *_timerLayout;
    QLabel *_timeLbl;
    QString _stime;
    QTime _time;
    QTimer *_timer;
    QPalette _pal;


};

#endif // TIMER_H

#include "timer.h"

Timer::Timer(QWidget *parent) :
    QWidget(parent)
{
    _pal = QPalette();

    this->setAutoFillBackground(true);

   _timeLbl = new QLabel("00:00:00");
   _timer = new QTimer();
   _time = QTime(0,0,0);
   _timerLayout = new QVBoxLayout;

  connect(_timer, SIGNAL(timeout()),this,SLOT(updateTime()));

    _timerLayout->addWidget(_timeLbl);
    setLayout(_timerLayout);
}


Timer ::~Timer()
{

}

void Timer::setTime(QString h, QString m)
{
  _time = QTime(h.toInt(),m.toInt(),0);
  _timeLbl->setText(_time.toString("hh:mm:ss"));
}

void Timer::playTimer()
{
    _timer->start(1000);

    _pal.setColor(QPalette::Window, Qt::green);

    this->setPalette(_pal);
}

void Timer::pauseTimer()
{
    _timer->stop();
    _pal.setColor(QPalette::Window, Qt::gray);

    this->setPalette(_pal);
}

void Timer::updateTime()
{
    if(_time.operator>(QTime(0,0,0)))
    {
    _time= _time.addSecs(-1);
    _timeLbl->setText(_time.toString("hh:mm:ss"));

    }
    else
    {
    _pal.setColor(QPalette::Window, Qt::gray);

    this->setPalette(_pal);
    }

}

QTime Timer::getTime()
{

    return _time;
}



#ifndef TASK_H
#define TASK_H


#include <QtWidgets>
#include <QCalendarWidget>
#include <QDate>
#include "checklist.h"
#include "timer.h"

class Task : public QWidget

{
    Q_OBJECT
public:
   explicit Task(QString text, QWidget *parent = nullptr);

   ~Task();
private slots:
    void editText();
    void editDate();
    void showCalendar();
    void showChecklist();
    void playTimer();
    void setTime();
    void deleteDate();
    void deleteTask();


private:

    QPushButton * _editTaskBtn;
    QPushButton * _editDateBtn;
    QPushButton * _showCheklistBtn;
    QPushButton * _playTimerBtn;
    QPushButton * _setTimeBtn;
    QPushButton *_delDateBtn;
    QPushButton * _delTaskBtn;
    QVBoxLayout * _taskLayout;
    QHBoxLayout * _dateLayout;
    QHBoxLayout * _timeLayout;
    QCalendarWidget *_calendar;
    QDate _date;
    QString _stime;
    QString _hour;
    QString _minutes;
    Timer *_timer;
    Checklist * _checklist = new Checklist;
    bool _clickedDateBtn = false;
    bool _clickedChecklistBtn = false;
    bool _clickedPlayBtn = false;
    QPalette _pal;
    static bool _timerTaskOn;

};

#endif // TASK_H

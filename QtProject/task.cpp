#include "task.h"
#include <QDebug>

bool Task::_timerTaskOn=false;

Task::Task(QString text, QWidget *parent) :
    QWidget(parent)

{
    _pal = QPalette();

    _pal.setColor(QPalette::Window, Qt::gray);

    this->setAutoFillBackground(true);
    this->setPalette(_pal);

    setAttribute(Qt::WA_DeleteOnClose);
    _taskLayout = new QVBoxLayout;
    _dateLayout = new QHBoxLayout;
    _timeLayout = new QHBoxLayout;

    _editTaskBtn = new QPushButton(text);
    _editDateBtn = new QPushButton("Adicionar data");
    _delDateBtn = new QPushButton("X");
    _showCheklistBtn = new QPushButton("Checklist");
    _delTaskBtn = new QPushButton("X");
    _setTimeBtn = new QPushButton("...");
    _playTimerBtn = new QPushButton("Play");

    _timer = new Timer();


    connect(_editTaskBtn, SIGNAL(clicked()), this, SLOT(editText()));
    connect(_editDateBtn, SIGNAL(clicked()), this, SLOT(showCalendar()));
    connect(_delDateBtn, SIGNAL(clicked()), this, SLOT(deleteDate()));
    connect(_showCheklistBtn, SIGNAL(clicked()), this, SLOT(showChecklist()));
    connect(_delTaskBtn, SIGNAL(clicked()), this, SLOT(deleteTask()));
    connect(_setTimeBtn, SIGNAL(clicked()), this, SLOT(setTime()));
    connect(_playTimerBtn, SIGNAL(clicked()), this, SLOT(playTimer()));

    _dateLayout -> addWidget(_editDateBtn);
    _dateLayout -> addWidget(_delDateBtn);

    _timeLayout -> addWidget(_timer);
    _timeLayout -> addWidget(_playTimerBtn);
    _timeLayout -> addWidget(_setTimeBtn);


    _taskLayout ->addWidget(_delTaskBtn);
    _taskLayout ->addWidget(_editTaskBtn);
    _taskLayout ->addLayout(_dateLayout);
    _taskLayout ->addLayout(_timeLayout);
    _taskLayout ->addWidget(_showCheklistBtn);
    _taskLayout ->addWidget(_checklist);
    _checklist ->hide();
    _taskLayout->addStretch();
    setLayout(_taskLayout);

}

void Task :: editText()
{
    bool ok;
    QString taskText = QInputDialog::getText(this, tr("Editar Tarefa"),
                                             tr("Descricao da tarefa:"), QLineEdit::Normal,
                                             "", &ok);
    if (ok && !taskText.isEmpty()){

    _editTaskBtn ->setText(taskText);
    }
}

void Task :: showCalendar()
{
    if(!_clickedDateBtn)
    {
        _calendar = new QCalendarWidget;
        _taskLayout->addWidget(_calendar);

        connect(_calendar, SIGNAL(selectionChanged()), this, SLOT(editDate()));
    }
    else
    {
     _calendar->close();
     _taskLayout->removeWidget(_calendar);

    }

    _clickedDateBtn=!_clickedDateBtn;

}



void Task :: editDate()
{

   _date = _calendar->selectedDate();
    QString dateText = _date.toString();
    _editDateBtn ->setText(dateText);
    _taskLayout->removeWidget(_calendar);
    _calendar->close();
    _clickedDateBtn=!_clickedDateBtn;



}

void Task::deleteDate()

{

    _editDateBtn->setText("Adicionar data");



}

void Task::showChecklist()
{ if(!_clickedChecklistBtn)
    {
      _checklist->show();
    }
    else
    {
      _checklist->hide();

    }

    _clickedChecklistBtn=!_clickedChecklistBtn;

}

void Task::deleteTask()
{
    this->close();
}

void Task::setTime()
{
    if(!_clickedPlayBtn || _timer->getTime().operator==(QTime(0,0,0)))
    {
    bool ok1;
    QString taskText1 = QInputDialog::getText(this, tr("Alocar Tempo"),
                                             tr("Horas:"), QLineEdit::Normal,
                                             "", &ok1);
    bool ok2;
    QString taskText2 = QInputDialog::getText(this, tr("Alocar Tempo"),
                                             tr("Minutos:"), QLineEdit::Normal,
                                             "", &ok2);
    if (ok1 && ok2 ){

    _hour = taskText1;
    _minutes = taskText2;

    _timer->setTime(_hour,_minutes);

    _clickedPlayBtn = false;
    _timer->pauseTimer();


    }
    }
}

void Task::playTimer()

{
    if(!_clickedPlayBtn && _timerTaskOn == false)
    {
        _timer->playTimer();
        _timerTaskOn = true;
        _clickedPlayBtn=true;
        _playTimerBtn->setText("Pause");
    }
    else if (_clickedPlayBtn)
    {
        _timer->pauseTimer();
        _timerTaskOn = false;
        _clickedPlayBtn=false;
        _playTimerBtn->setText("Play");
    }
}

Task :: ~Task()
{

}

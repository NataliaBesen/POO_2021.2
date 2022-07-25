#include "focusmode.h"

FocusMode *FocusMode::_instance=0;

FocusMode::FocusMode(QWidget*parent):
    QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    _focusBtnLayout = new QHBoxLayout;
    _focusLayout = new QVBoxLayout;

    _focusLbl = new QLabel("Intervalo");

    _timer= new Timer();
    _readTimer = new QTimer();

    _playBtn = new QPushButton("Play");
    _pauseBtn = new QPushButton("Pause");
    _resetBtn = new QPushButton("Reset");
    _closeBtn = new QPushButton("X");

    connect(_playBtn,SIGNAL(clicked()),this,SLOT(playFocus()));
    connect(_pauseBtn,SIGNAL(clicked()),this,SLOT(pauseFocus()));
    connect(_resetBtn,SIGNAL(clicked()),this,SLOT(resetFocus()));
    connect(_closeBtn,SIGNAL(clicked()),this,SLOT(closeFocus()));
    connect(_readTimer,SIGNAL(timeout()),this,SLOT(startFocus()));

    _focusBtnLayout->addWidget(_playBtn);
    _focusBtnLayout->addWidget(_pauseBtn);
    _focusBtnLayout->addWidget(_resetBtn);
    _focusBtnLayout->addWidget(_closeBtn);
    _focusLayout->addLayout(_focusBtnLayout);
    _focusLayout->addWidget(_focusLbl);
    _focusLayout->addWidget(_timer);
    setLayout(_focusLayout);
    _readTimer->start(1000);
    this->show();



}

FocusMode *FocusMode::getInstanceOf()
{
    if(_instance==0)
    {
        _instance = new FocusMode();
    }
    return _instance;
}


void FocusMode::startFocus()
{ 

    if(i<3)
    {
        if((operator==(_timer->getTime(),QTime(0,0,0)) )&&(_focusOn == true))
        {
        _timer->setTime("0","2");
         _focusLbl->setText("Foco!");
         _focusOn = false;

        }
        if(operator==(_timer->getTime(),QTime(0,0,0))&& (_focusOn == false))
        {
            _timer->setTime("0","1");
            _focusLbl->setText("Intervalo!");
            _focusOn = true;
            i++;
        }

    }
    if(i==3)
    {
        if((operator==(_timer->getTime(),QTime(0,0,0)) )&&(_focusOn == true))
        _timer->setTime("0","2");
         _focusLbl->setText("Foco!");
         _focusOn = false;

        if(operator==(_timer->getTime(),QTime(0,0,0))&& (_focusOn == false))
        {
            _timer->setTime("0","3");
            _focusLbl->setText("Intervalo!");
            _focusOn = true;
        }
        this->resetFocus();
    }

}

void FocusMode:: playFocus()
{
    _timer->playTimer();
}

void FocusMode:: pauseFocus()
{
    _timer->pauseTimer();
}

void FocusMode:: resetFocus()
{
    i=0;
    _focusOn = true;
    _timer->setTime("0","0");
    this->startFocus();
}

void FocusMode:: closeFocus()
{
    this->close();
    _instance=0;
}

FocusMode::~FocusMode()
{

}

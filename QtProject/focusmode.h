#ifndef FOCUSMODE_H
#define FOCUSMODE_H


#include <QtWidgets>
#include "timer.h"


class FocusMode : public QWidget

{
    Q_OBJECT
public:
   explicit FocusMode(QWidget *parent = nullptr);

   ~FocusMode();

    static FocusMode *getInstanceOf();


private slots:
    void playFocus();
    void pauseFocus();
    void resetFocus();
    void closeFocus();
    void startFocus();

private:
    static FocusMode *_instance;
    QVBoxLayout *_focusLayout;
    QHBoxLayout *_focusBtnLayout;
    QLabel *_focusLbl;
    QPushButton *_playBtn;
    QPushButton *_pauseBtn;
    QPushButton *_resetBtn;
    QPushButton *_closeBtn;
    Timer *_timer;
    QTimer *_readTimer;
    int i = 0;
    bool _focusOn= true;
};



#endif // FOCUSMODE_H

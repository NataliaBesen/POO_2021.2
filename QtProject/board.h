#ifndef BOARD_H
#define BOARD_H

#include <QtWidgets>
#include <QDebug>
#include "list.h"
#include "focusmode.h"

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private slots:
    void newList();
    void startFocusMode();

private:
    QPushButton * _addListBtn;
    QPushButton * _focusModeBtn;
    QVBoxLayout * _mainLayout;
    QHBoxLayout * _listsLayout;

};

#endif // QUADRO_H

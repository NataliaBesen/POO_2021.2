#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QtWidgets>
#include <QCalendarWidget>
#include <QDate>
#include "checkbox.h"

class Checklist : public QWidget
{
        Q_OBJECT
    public:
       explicit Checklist(QWidget *parent = nullptr);

    ~Checklist();

public slots:
    void newCheckbox();

    private:
    QVBoxLayout * _checklistLayout;
    QPushButton * _addCheckboxBtn;
    Checkbox *_newCheckbox;




};

#endif // CHECKLIST_H

#ifndef LISTA_H
#define LISTA_H

#include <QtWidgets>
#include "task.h"

class List : public QWidget

{
    Q_OBJECT
public:
   explicit List(QString name, QWidget *parent = nullptr);

   ~List();
private slots:
    void newTask();
    void deleteList();

private:
    QLabel * _name;
    QPushButton * _addTaskBtn;
    QPushButton * _delListBtn;
    QVBoxLayout * _listLayout;
    QHBoxLayout * _nameLayout;
    QPalette _pal;

};

#endif // LISTA_H

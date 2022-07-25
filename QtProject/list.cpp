#include "list.h"

List::List(QString name, QWidget *parent) :
    QWidget(parent)
{
    _pal = QPalette();

    _pal.setColor(QPalette::Window, Qt::darkGray);

    this->setAutoFillBackground(true);
    this->setPalette(_pal);

    setAttribute(Qt::WA_DeleteOnClose);

    _listLayout = new QVBoxLayout;
    _nameLayout = new QHBoxLayout;

    _name = new QLabel(name);
    _delListBtn = new QPushButton("X");
    _addTaskBtn = new QPushButton(tr("Criar Tarefa"));

    connect(_addTaskBtn, SIGNAL(clicked()), this, SLOT(newTask()));
    connect(_delListBtn, SIGNAL(clicked()), this, SLOT(deleteList()));


    _nameLayout->addWidget(_name);
    _nameLayout->addWidget(_delListBtn);
    _listLayout->addLayout(_nameLayout);
    _listLayout->addWidget(_addTaskBtn);
    //_listLayout->addStretch();
    setLayout(_listLayout);

}

void List::newTask(){
    bool ok;
    QString taskText = QInputDialog::getText(this, tr("Criar Tarefa"),
                                             tr("Descricao da tarefa:"), QLineEdit::Normal,
                                             "", &ok);
    if (ok && !taskText.isEmpty()){

        Task * newTask = new Task(taskText);

        _listLayout->addWidget(newTask);
    }
}

void List::deleteList()
{
    this->close();
}
List::~List()
{

}

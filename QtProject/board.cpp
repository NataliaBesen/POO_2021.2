#include "board.h"


Board::Board(QWidget *parent) :
    QWidget(parent)
{
    _addListBtn = new QPushButton(tr("Criar Lista"));
    _focusModeBtn = new QPushButton("Modo Foco");

    _mainLayout = new QVBoxLayout;
    _listsLayout = new QHBoxLayout;

    connect(_addListBtn, SIGNAL(clicked()), this, SLOT(newList()));
    connect(_focusModeBtn, SIGNAL(clicked()), this, SLOT(startFocusMode()));

    _mainLayout->addWidget(_focusModeBtn);
    _mainLayout->addWidget(_addListBtn);
    _mainLayout->addLayout(_listsLayout);

    setLayout(_mainLayout);

    setWindowTitle(tr("Planner"));

}

void Board::newList() {
    bool ok;
    QString listName = QInputDialog::getText(this, tr("Criar Lista"),
                                             tr("Nome da lista:"), QLineEdit::Normal,
                                             "", &ok);
    if (ok && !listName.isEmpty()){

        List * newList = new List(listName);

        _listsLayout->addWidget(newList);
    }

}

void Board::startFocusMode()
{
    FocusMode::getInstanceOf();
}

Board::~Board()
{

}

#include "checklist.h"

Checklist::Checklist(QWidget *parent):
    QWidget(parent)
{
    _checklistLayout = new QVBoxLayout;
    _addCheckboxBtn = new QPushButton("+");

    connect( _addCheckboxBtn, SIGNAL(clicked()), this, SLOT(newCheckbox()));


    _checklistLayout ->addWidget(_addCheckboxBtn);
    _checklistLayout->addStretch();
    setLayout(_checklistLayout);
}

Checklist::~Checklist()
{

}

void Checklist :: newCheckbox()
{
    bool ok;
    QString boxText = QInputDialog::getText(this, tr("Criar Checkbox"),
                                             tr("Descricao:"), QLineEdit::Normal,
                                             "", &ok);
    if (ok && !boxText.isEmpty())
    {
    Checkbox *_newCheckbox = new Checkbox(boxText);
    _checkboxVector.push_back(_newCheckbox);

    _checklistLayout->addWidget(_newCheckbox);


    }

}


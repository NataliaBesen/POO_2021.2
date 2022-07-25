#include "checkbox.h"

Checkbox::Checkbox(QString text, QWidget *parent):
    QWidget (parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    _checkboxLayout = new QHBoxLayout;
    _box = new QCheckBox(text);
    _editBtn = new QPushButton("...");
    _delBtn = new QPushButton("X");

    connect(_editBtn, SIGNAL(clicked()), this, SLOT(editText()));
    connect(_delBtn, SIGNAL(clicked()), this, SLOT(clearLayout()));

    _checkboxLayout->addWidget(_box);
    _checkboxLayout->addWidget(_editBtn);
    _checkboxLayout->addWidget(_delBtn);
    setLayout(_checkboxLayout);
}



Checkbox::~Checkbox()
{

}

void Checkbox :: editText()
{
    bool ok;
    QString boxText = QInputDialog::getText(this, tr("Criar Checkbox"),
                                             tr("Descricao:"), QLineEdit::Normal,
                                             "", &ok);
    if (ok && !boxText.isEmpty())
    {
    _box->setText(boxText);
    }
}

void Checkbox::clearLayout() {
    this->close();
}

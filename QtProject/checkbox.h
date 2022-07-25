#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QtWidgets>
#include <QCalendarWidget>
#include <QDate>


class Checkbox : public QWidget
{
        Q_OBJECT
    public:
       explicit Checkbox(QString text, QWidget *parent = nullptr);

    ~Checkbox();
private slots:
    void editText();
    void clearLayout();

    private:
    QHBoxLayout *_checkboxLayout;
    QCheckBox *_box;
    QPushButton *_editBtn;
    QPushButton *_delBtn;
};
#endif // CHECKBOX_H

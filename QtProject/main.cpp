#include "board.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board *w = new Board;
    w->show();

    return a.exec();
}

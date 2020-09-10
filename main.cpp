#include "texteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    textEditor w;
    w.show();
    return a.exec();
}

#include "userwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserWindow w;
    w.setMinimumSize(1000, 700);
    w.show();
    return a.exec();
}

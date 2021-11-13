#include "Mainwindow.h"
#include "Sharecount.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShareCount shareCount = ShareCount();
    Mainwindow w(&shareCount);
    w.show();
    return a.exec();
}

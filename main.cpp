#include "qgridplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGridPlayer w;
    w.show();

    return a.exec();
}

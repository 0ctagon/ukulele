#include "uku.h"
#include <QApplication>
#include "bars.h"
#include "chords.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uku w;
    w.show();
    return a.exec();
}

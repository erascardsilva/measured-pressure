#include "pressao.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pressao w;
    w.show();
    return a.exec();
}

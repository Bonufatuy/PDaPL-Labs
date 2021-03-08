#include "register_distributor_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    register_distributor_Window w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"

#include <QApplication>
#include <QSize>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // set window icon
    w.setWindowIcon(QIcon(":/images/WindowIcon.png"));

    w.show();
    return a.exec();
}

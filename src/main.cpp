#include <QApplication>
#include <QTime>

#include "MainWindow.h"
#include "FirstWindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    auto fw = new FirstWindow();
    fw->show();

    return app.exec();
}
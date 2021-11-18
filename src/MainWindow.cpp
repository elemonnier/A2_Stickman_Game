#include <QHBoxLayout>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->mainScene = new MainScene();
    this->timer = new QTimer(this);
    this->timer->start();

    auto stickman = this->mainScene->getStickman();

    // view on the character
    auto stickmanView = new QGraphicsView();
    stickmanView->setScene(mainScene);
    stickmanView->resize(600, 600);
    stickmanView->setWindowTitle(stickman->getDescription());
    stickmanView->show();

    // view on the scene
    this->mainView = new QGraphicsView();
    this->mainView->setScene(mainScene);
    this->mainView->scale(0.15, 0.15);

    // main window
    this->setCentralWidget(mainView);
    this->setWindowTitle("Main view");
    this->resize(900, 300);
}

#ifndef GAME_MAINWINDOW_H
#define GAME_MAINWINDOW_H


#include "MainScene.h"
#include <QMainWindow>
#include <QGraphicsView>

class MainWindow : public QMainWindow {
Q_OBJECT

private :
    MainScene* mainScene;
    QGraphicsView* mainView;
    QTimer* timer;
public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow() {};
};


#endif //GAME_MAINWINDOW_H

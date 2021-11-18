#ifndef GAME_MAINSCENE_H
#define GAME_MAINSCENE_H


#include <QGraphicsScene>
#include <QPixmap>
#include "Stickman.h"
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QKeyEvent>
#include <QtWidgets/QMainWindow>

class MainScene : public QGraphicsScene {
    Q_OBJECT
private:
    QPixmap background;
    QTimer* timer;
    Stickman* stickman;
protected:
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
public:
    MainScene(QGraphicsScene* = nullptr);
    void drawBackground(QPainter* painter, const QRectF& rect);
    Stickman* getStickman(){ return this->stickman; }
    virtual ~MainScene();

public slots :
    void update();
};


#endif //GAME_MAINSCENE_H

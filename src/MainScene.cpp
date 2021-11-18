#include "MainScene.h"
#include "LeaderboardAfterGame.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QVector>

MainScene::MainScene(QGraphicsScene* parent) : QGraphicsScene(parent) {
    this->background.load("background.jpg");
    this->setSceneRect(0, 0, background.width(), background.height());

    this->timer = new QTimer(this);
    this->timer->start(30);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    this->stickman = new Stickman("j1", "stickman.png");
    this->addItem(this->stickman);
    this->stickman->setPos(50, 1600);
}

void MainScene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

MainScene::~MainScene() {
    delete this;
}

void MainScene::update() {
    // to know if the character has reached the finish
    if (this->stickman->pos().x() >= 3520 && this->stickman->pos().y() > 1500){
        timer->start(50000000);
        auto a = new LeaderboardAfterGame();
        a->show();
    }
    // to apply some gravity to the character
    if (this->stickman->pos().y() < 1600){
        this->stickman->setPos(this->stickman->pos().x(), this->stickman->pos().y() + 5);
    }
    // to fall in a hole, and to teleport the player to the start
    if (this->stickman->pos().y() > 1650){
        this->stickman->setPos(50, 1600);
    }
    // to know where the character can fall
    if (((this->stickman->pos().x() > 1715 && this->stickman->pos().x() < 1865) && this->stickman->pos().y() >= 1600) || ((this->stickman->pos().x() > 2070 && this->stickman->pos().x() < 2180) && this->stickman->pos().y() >= 1600) || ((this->stickman->pos().x() > 2360 && this->stickman->pos().x() < 2470) && this->stickman->pos().y() >= 1600)){
        this->stickman->setPos(this->stickman->pos().x(), this->stickman->pos().y() + 5);
    }
    // to know where the character can die from hitting an obstacle, and to teleport the player to the start
    if (((this->stickman->pos().x() >= 840) && (this->stickman->pos().x() <= 890) && (this->stickman->pos().y() > 1404) && (this->stickman->pos().y() <= 1600)) || ((this->stickman->pos().x() >= 1250) && (this->stickman->pos().x() <= 1290) && (this->stickman->pos().y() > 1404) && (this->stickman->pos().y() <= 1600)) || ((this->stickman->pos().x() >= 2470) && (this->stickman->pos().x() <= 2520) && (this->stickman->pos().y() > 1404) && (this->stickman->pos().y() <= 1600))){
        this->stickman->setPos(50, 1600);
    }
    // view update
    QGraphicsView* view = this->views().at(0);
    view->centerOn(this->stickman);
}

void MainScene::keyPressEvent(QKeyEvent *event) {
    // overriding the keyPressEvent method from Qt libraries
    if (event->key() == Qt::Key_Up){
        this->stickman->jump();
    }
    if (event->key() == Qt::Key_Left){
        this->stickman->moveleft();
    }
    if (event->key() == Qt::Key_Right){
        this->stickman->moveright();
    }
}

void MainScene::keyReleaseEvent(QKeyEvent *event) {
    // overriding the keyReleaseEvent method from Qt libraries
    QGraphicsScene::keyReleaseEvent(event);
}
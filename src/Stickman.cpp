#include "Stickman.h"
#include <QObject>
#include <QPointF>
#include <unistd.h>

Stickman::Stickman(QString description, QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description) {
}

void Stickman::moveleft() {
    this->setPos(this->pos().x() - 10, this->pos().y());
}

void Stickman::moveright() {
    this->setPos(this->pos().x() + 10, this->pos().y());
}

void Stickman::jump() {
    // jump is allowed only if the character is touching the ground
    if (this->pos().y() == 1600) {
        this->setPos(this->pos().x(), this->pos().y() - 400);
    }
}


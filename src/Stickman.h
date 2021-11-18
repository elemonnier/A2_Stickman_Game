#ifndef GAME_STICKMAN_H
#define GAME_STICKMAN_H


#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Stickman : public QGraphicsPixmapItem {
private:
    QString description;
public:
    Stickman(QString, QString);
    const QString &getDescription() const { return this->description; }
    void moveleft();
    void moveright();
    void jump();
};


#endif //GAME_STICKMAN_H

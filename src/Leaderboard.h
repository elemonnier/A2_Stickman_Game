#ifndef QT_PROJECT_LEADERBOARD_H
#define QT_PROJECT_LEADERBOARD_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

class Leaderboard : public QWidget {
    Q_OBJECT
private:
    QLabel* bestResult;
    QPushButton* back;
public:
    Leaderboard(QWidget* = nullptr);
public slots:
    void backToFirstWindow();
};


#endif //QT_PROJECT_LEADERBOARD_H

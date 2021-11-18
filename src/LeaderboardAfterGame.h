#ifndef GAME_LEADERBOARDAFTERGAME_H
#define GAME_LEADERBOARDAFTERGAME_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

class LeaderboardAfterGame : public QWidget {
Q_OBJECT
private:
    QLabel* bestResult;
    QPushButton* mainMenu;
    QPushButton* restart;
public:
    LeaderboardAfterGame(QWidget* = nullptr);
public slots:
    void backToMainMenu();
    void newGame();
};


#endif //GAME_LEADERBOARDAFTERGAME_H

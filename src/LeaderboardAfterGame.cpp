#include <QtWidgets/QVBoxLayout>
#include "LeaderboardAfterGame.h"
#include "FirstWindow.h"
#include "MainWindow.h"

LeaderboardAfterGame::LeaderboardAfterGame(QWidget * parent) : QWidget(parent) {
    this->setWindowTitle("Leaderboard");
    auto layout = new QVBoxLayout;
    this->bestResult = new QLabel();
    this->bestResult->setText("Etienne 0:50.295");
    layout->addWidget(this->bestResult);
    this->mainMenu = new QPushButton("Main Menu");
    layout->addWidget(this->mainMenu);
    this->restart = new QPushButton("Restart Game");
    layout->addWidget(this->restart);
    this->setLayout(layout);

    connect(this->mainMenu, SIGNAL(clicked()), this, SLOT(backToMainMenu()));
    connect(this->restart, SIGNAL(clicked()), this, SLOT(newGame()));
}

void LeaderboardAfterGame::backToMainMenu() {
    this->close();
    auto fw = new FirstWindow();
    fw->show();
}

void LeaderboardAfterGame::newGame() {
    this->close();
    auto ng = new MainWindow();
    ng->show();
}

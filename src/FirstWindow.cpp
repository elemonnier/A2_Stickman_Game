#include <QtWidgets/QVBoxLayout>
#include "FirstWindow.h"
#include "Leaderboard.h"
#include "MainWindow.h"

FirstWindow::FirstWindow(QWidget* parent) : QWidget(parent) { // displaying the main menu window
    this->setWindowTitle("Welcome!");
    this->setMinimumSize(600, 400);
    auto layout = new QVBoxLayout;
    this->newGame = new QPushButton("New Game");
    layout->addWidget(this->newGame);
    this->leaderboard = new QPushButton("Leaderboard");
    layout->addWidget(this->leaderboard);
    this->quitGame = new QPushButton("Quit Game");
    layout->addWidget(this->quitGame);
    this->setLayout(layout);

    // all button signals
    connect(this->newGame, SIGNAL(clicked()), this, SLOT(newGameWindow()));
    connect(this->leaderboard, SIGNAL(clicked()), this, SLOT(printLeaderboard()));
    connect(this->quitGame, SIGNAL(clicked()), this, SLOT(close()));
}

void FirstWindow::newGameWindow() {
    this->close();
    auto game = new MainWindow();
    game->show();
}

void FirstWindow::printLeaderboard() {
    this->close();
    auto lead = new Leaderboard();
    lead->show();
}
#include <QtWidgets/QVBoxLayout>
#include "Leaderboard.h"
#include "FirstWindow.h"

Leaderboard::Leaderboard(QWidget* parent) : QWidget(parent) {
    this->setWindowTitle("Leaderboard");
    auto layout = new QVBoxLayout;
    this->bestResult = new QLabel();
    this->bestResult->setText("Etienne 0:50.295");
    layout->addWidget(this->bestResult);
    this->back = new QPushButton("Back");
    layout->addWidget(this->back);
    this->setLayout(layout);

    connect(this->back, SIGNAL(clicked()), this, SLOT(backToFirstWindow()));
}

void Leaderboard::backToFirstWindow() {
    this->close();
    auto FW = new FirstWindow();
    FW->show();
}


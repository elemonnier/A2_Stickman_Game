#ifndef QT_PROJECT_FIRSTWINDOW_H
#define QT_PROJECT_FIRSTWINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

class FirstWindow : public QWidget {
    Q_OBJECT
private:
    QPushButton* newGame;
    QPushButton* leaderboard;
    QPushButton* quitGame;
public:
    FirstWindow(QWidget* = nullptr);
public slots:
    void newGameWindow();
    void printLeaderboard();
};


#endif //QT_PROJECT_FIRSTWINDOW_H

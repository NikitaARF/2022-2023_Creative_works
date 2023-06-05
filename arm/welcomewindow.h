#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class WelcomeWindow : public QDialog {
    Q_OBJECT

public:
    WelcomeWindow(QWidget *parent = nullptr);

private slots:
    void startTraining();

private:
    QLabel *titleLabel;
    QLabel *messageLabel;
    QPushButton *startButton;
};

#endif // WELCOMEWINDOW_H

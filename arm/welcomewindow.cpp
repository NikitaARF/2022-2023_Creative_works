#include "welcomewindow.h"
#include "mainwindow.h"
#include <QVBoxLayout>

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Приветствие");
    setFixedSize(1000, 500);

    QVBoxLayout *layout = new QVBoxLayout(this);

    titleLabel = new QLabel("Привет, я твой личный фитнесс тренер!");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold;");

    messageLabel = new QLabel("С помощью меня ты сможешь узнать свои рекомендации по тренировкам.\nБудь честным со мной, когда будешь вводить свои параметры!\nУдачи!");
    messageLabel->setWordWrap(true);
    messageLabel->setStyleSheet("font-size: 14px;");

    startButton = new QPushButton("Начать тренировку");
    startButton->setFixedSize(150, 50);
    startButton->setStyleSheet("font-size: 16px;");

    layout->addWidget(titleLabel);
    layout->addWidget(messageLabel);
    layout->addWidget(startButton);
    layout->setAlignment(Qt::AlignCenter);

    connect(startButton, &QPushButton::clicked, this, &WelcomeWindow::startTraining);

    setLayout(layout);
}

void WelcomeWindow::startTraining()
{
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
    close();
}

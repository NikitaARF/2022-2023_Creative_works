#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void generateRecommendations();
    void saveRecommendationsToFile(const QString &recommendations);

private:
    QString getStrengthTrainingRecommendation(int strength);
    QString getAgilityTrainingRecommendation(int agility);
    QString getEnduranceTrainingRecommendation(int endurance);

    QLabel *strengthLabel;
    QSlider *strengthSlider;
    QLabel *agilityLabel;
    QSlider *agilitySlider;
    QLabel *enduranceLabel;
    QSlider *enduranceSlider;
    QPushButton *generateButton;
    QLabel *recommendationsLabel;
};

#endif // MAINWINDOW_H

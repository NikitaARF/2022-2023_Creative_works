#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QFileDialog>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setGeometry(100, 100, 1000, 500);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    strengthLabel = new QLabel("Оцените свою силу (от 1 до 10):");
    strengthSlider = new QSlider(Qt::Horizontal);
    strengthSlider->setRange(1, 10);

    agilityLabel = new QLabel("Оцените свою ловкость (от 1 до 10):");
    agilitySlider = new QSlider(Qt::Horizontal);
    agilitySlider->setRange(1, 10);

    enduranceLabel = new QLabel("Оцените свою выносливость (от 1 до 10):");
    enduranceSlider = new QSlider(Qt::Horizontal);
    enduranceSlider->setRange(1, 10);

    generateButton = new QPushButton("Сгенерировать рекомендации");

    recommendationsLabel = new QLabel;
    recommendationsLabel->setWordWrap(true);

    layout->addWidget(strengthLabel);
    layout->addWidget(strengthSlider);
    layout->addWidget(agilityLabel);
    layout->addWidget(agilitySlider);
    layout->addWidget(enduranceLabel);
    layout->addWidget(enduranceSlider);
    layout->addWidget(generateButton);
    layout->addWidget(recommendationsLabel);

    connect(generateButton, &QPushButton::clicked, this, &MainWindow::generateRecommendations);
}

void MainWindow::generateRecommendations() {
    int strength = strengthSlider->value();
    int agility = agilitySlider->value();
    int endurance = enduranceSlider->value();

    QString recommendations = "Рекомендации по тренировкам:\n\n";

    recommendations += "Понедельник: Силовая тренировка\n";
    recommendations += getStrengthTrainingRecommendation(strength) + "\n\n";

    recommendations += "Вторник: Тренировка на ловкость\n";
    recommendations += getAgilityTrainingRecommendation(agility) + "\n\n";

    recommendations += "Среда: Тренировка на выносливость\n";
    recommendations += getEnduranceTrainingRecommendation(endurance) + "\n\n";

    recommendations += "Четверг: Силовая тренировка\n";
    recommendations += getStrengthTrainingRecommendation(strength) + "\n\n";

    recommendations += "Пятница: Тренировка на ловкость\n";
    recommendations += getAgilityTrainingRecommendation(agility) + "\n\n";

    recommendationsLabel->setText(recommendations);
    saveRecommendationsToFile(recommendations);
}

QString MainWindow::getStrengthTrainingRecommendation(int strength) {
    QString recommendation;

    if (strength >= 7) {
        recommendation = "Высокая интенсивность, большой вес, меньше повторений.";
    } else if (strength >= 4) {
        recommendation = "Средняя интенсивность, средний вес, умеренное количество повторений.";
    } else {
        recommendation = "Низкая интенсивность, малый вес, большое количество повторений.";
    }

    return recommendation;
}

QString MainWindow::getAgilityTrainingRecommendation(int agility) {
    QString recommendation;

    if (agility >= 7) {
        recommendation = "Быстрые и координационные упражнения, тренировки на равновесие.";
    } else if (agility >= 4) {
        recommendation = "Средняя интенсивность, упражнения на точность и реакцию.";
    } else {
        recommendation = "Упражнения на растяжку, улучшение гибкости.";
    }

    return recommendation;
}

QString MainWindow::getEnduranceTrainingRecommendation(int endurance) {
    QString recommendation;

    if (endurance >= 7) {
        recommendation = "Длительные кардио-тренировки, бег, плавание.";
    } else if (endurance >= 4) {
        recommendation = "Интервальные тренировки, силовые тренировки с меньшими перерывами.";
    } else {
        recommendation = "Поддерживайте активный образ жизни, ходите на прогулки.";
    }

    return recommendation;
}

void MainWindow::saveRecommendationsToFile(const QString &recommendations) {
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить рекомендации", "", "Текстовый файл (*.txt)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream.setGenerateByteOrderMark(true);
            stream << recommendations << "\n\n";
            file.close();
        } else {
            qDebug() << "Ошибка при открытии файла для записи.";
        }
    }
}


#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include<QPushButton>
#include <paintscene.h>
#include"neuron.h"
//менюБар
#include <QGridLayout>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>

namespace Ui {
class Paint;
}

class Paint : public QWidget, public Neuron
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = nullptr);

    ~Paint();

    std::vector<std::vector<unsigned int>>pxl; //массив картинок
    std::vector<int> number; //массив правильных ответов
    int example_count = 0; //счетчик примеров

private:
    Ui::Paint *ui;
    QTimer *timer;      // Определяем таймер для подготовки актуальных размеров графической сцены
    paintScene *scene;  // Объявляем кастомную графическую сцену

private:
    // Переопределяем событие изменения размера окна для пересчёта размеров графической сцены
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void saveExamples();
    void readExamples();
    void clearExamples();
    void saveWeights();
    void dropWeights();
    void readWeights();
    void quit();
    void about();
};

#endif // PAINT_H

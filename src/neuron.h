#ifndef NEURON_H
#define NEURON_H

#define SIZE_ARRAY_IN 900
#define SIZE_ARRAY_1 32
#define SIZE_ARRAY_2 32
#define SIZE_ARRAY_OUT 10
#define ERA 10000 // макс кол-во эпох
#define LEARN 0.005 //задаем шаг обучения
#include<vector>
#include<cmath>
#include "stdlib.h"

class Neuron
{
public:
    //нейроны
    double *layerIN = new double [SIZE_ARRAY_IN];
    double *layer1 = new double [SIZE_ARRAY_1];
    double *layer2 = new double [SIZE_ARRAY_2];
    double *layerOUT = new double [SIZE_ARRAY_OUT];
    //веса
    double **weight1 = new double* [SIZE_ARRAY_1];
    double **weight2 = new double* [SIZE_ARRAY_2];
    double **weight3 = new double* [SIZE_ARRAY_OUT];
    //сдвиги
    double *shift1 = new double [SIZE_ARRAY_1];
    double *shift2 = new double [SIZE_ARRAY_2];
    double *shift3 = new double [SIZE_ARRAY_OUT];
    //ошибки
    double *error1 = new double [SIZE_ARRAY_1];
    double *error2 = new double [SIZE_ARRAY_2];
    double *error3 = new double [SIZE_ARRAY_OUT];

    void getMistake(int symbol);
    int getLayer(std::vector<unsigned int> pxl);
    bool is_exit = false;
    void getRandomWeights();
    double getRandom();
    void uploadWeights(std::vector<double> &number_in);
    ~Neuron();
};

#endif // NEURON_H

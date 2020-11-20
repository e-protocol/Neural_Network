#include"neuron.h"

double Neuron::getRandom()
{
    double f = (double)rand() / RAND_MAX;
    return -1.0 + f * (1.0 - ( -1.0));
}

void Neuron::getRandomWeights()
{
    for(int k = 0; k < SIZE_ARRAY_1; k++)
        weight1[k] = new double[SIZE_ARRAY_IN];
    for (int k = 0; k < SIZE_ARRAY_1; k++)
        for (int j = 0; j < SIZE_ARRAY_IN; j++)
            weight1[k][j] = getRandom();

    for(int k = 0; k < SIZE_ARRAY_2; k++)
        weight2[k] = new double[SIZE_ARRAY_1];
    for (int k = 0; k < SIZE_ARRAY_2; k++)
        for (int j = 0; j < SIZE_ARRAY_1; j++)
            weight2[k][j] = getRandom();

    for(int k = 0; k < SIZE_ARRAY_OUT; k++)
        weight3[k] = new double[SIZE_ARRAY_2];
    for (int k = 0; k < SIZE_ARRAY_OUT; k++)
        for (int j = 0; j < SIZE_ARRAY_2; j++)
            weight3[k][j] = getRandom();

    for (int k = 0; k < SIZE_ARRAY_1; k++)
        shift1[k] = getRandom();
    for (int k = 0; k < SIZE_ARRAY_2; k++)
        shift2[k] = getRandom();
    for (int k = 0; k < SIZE_ARRAY_OUT; k++)
        shift3[k] = getRandom();
}

int Neuron::getLayer(std::vector<unsigned int> pxl)
{

    //входной слой
    for (int k = 0; k < SIZE_ARRAY_IN; k++)
    {
        if(pxl[k] == 4294967295) //this is value of white int pixel
            layerIN[k] = -1.0;
        else
            layerIN[k] = 1.0;
    }
    //первый слой
    for (int k = 0; k < SIZE_ARRAY_1; k++)
    {
        double val = 0.0;
        for (int j = 0; j < SIZE_ARRAY_IN; j++)
            val += layerIN[j] * weight1[k][j];
        val += shift1[k];
        if(val > 0)
            layer1[k] = 1.0;
        else
            layer1[k] = -1.0;
    }
    //второй слой
    for (int k = 0; k < SIZE_ARRAY_2; k++)
    {
        double val = 0.0;
        for (int j = 0; j < SIZE_ARRAY_1; j++)
            val += layer1[j] * weight2[k][j];
        val += shift2[k];
        if(val > 0)
            layer2[k] = 1.0;
        else
            layer2[k] = -1.0;
    }
    //выходной слой
    double max = 0.0;
    int max_element = 0;
    for (int k = 0; k < SIZE_ARRAY_OUT; k++)
    {
        double val = 0.0;
        for (int j = 0; j < SIZE_ARRAY_2; j++)
            val += layer2[j] * weight3[k][j];
        val += shift3[k];
        if(val > 0)
            layerOUT[k] = 1.0;
        else
            layerOUT[k] = -1.0;
        //запоминаем элемент с максимальным значением
        if (layerOUT[k] > max)
        {
            max = layerOUT[k];
            max_element = k;
        }
    }
    return max_element;
}

void Neuron::getMistake(int symbol)
{
    //определяем ошибку
    //выходной слой
    for (int k = 0; k < SIZE_ARRAY_OUT; k++)
    {
        if (k == symbol)
            error3[k] = (1.0 - layerOUT[k]);
        else
            error3[k] = (-1.0 - layerOUT[k]);
    }
    //второй слой
    for (int k = 0; k < SIZE_ARRAY_2; k++)
    {
        error2[k] = 0.0;
        for (int j = 0; j < SIZE_ARRAY_OUT; j++)
            error2[k] += weight3[j][k] * error3[j];
    }
    //первый слой
    for (int k = 0; k < SIZE_ARRAY_1; k++)
    {
        error1[k] = 0.0;
        for (int j = 0; j < SIZE_ARRAY_2; j++)
            error1[k] += weight2[j][k] * error2[j];
    }

    //определяем веса
    //первый слой
    for (int k = 0; k < SIZE_ARRAY_1; k++)
    {
        for (int j = 0; j < SIZE_ARRAY_IN; j++)
            weight1[k][j] += LEARN * error1[k] * layerIN[j];
        shift1[k] += LEARN * error1[k];
    }
    //второй слой
    for (int k = 0; k < SIZE_ARRAY_2; k++)
    {
        for (int j = 0; j < SIZE_ARRAY_1; j++)
            weight2[k][j] += LEARN * error2[k] * layer1[j];
        shift2[k] += LEARN * error2[k];
    }
    //выходной слой
    for (int k = 0; k < SIZE_ARRAY_OUT; k++)
    {
        for (int j = 0; j < SIZE_ARRAY_2; j++)
            weight3[k][j] += LEARN * error3[k] * layer2[j];
        shift3[k] += LEARN * error3[k];
    }
}

void Neuron::uploadWeights(std::vector<double> &number_in)
{
    //заменяем веса
    int count = 0;
    for(int k = 0; k < SIZE_ARRAY_1; k++)
        for(int j = 0; j < SIZE_ARRAY_IN; j++)
        {
            weight1[k][j] = number_in[count];
            count++;
        }
    for(int k = 0; k < SIZE_ARRAY_2; k++)
        for(int j = 0; j < SIZE_ARRAY_1; j++)
        {
            weight2[k][j] = number_in[count];
            count++;
        }
    for(int k = 0; k < SIZE_ARRAY_OUT; k++)
        for(int j = 0; j < SIZE_ARRAY_2; j++)
        {
            weight3[k][j] = number_in[count];
            count++;
        }
    for(int k = 0; k < SIZE_ARRAY_1; k++)
    {
        shift1[k] = number_in[count];
        count++;
    }
    for(int k = 0; k < SIZE_ARRAY_2; k++)
    {
        shift2[k] = number_in[count];
        count++;
    }
    for(int k = 0; k < SIZE_ARRAY_OUT; k++)
    {
        shift3[k] = number_in[count];
        count++;
    }
}

Neuron::~Neuron()
{
    delete[] layerIN;
    delete[] layer1;
    delete[] layer2;
    delete[] layerOUT;

    for(int k = 0; k < SIZE_ARRAY_1; k++)
        delete[] weight1[k];
    delete[] weight1;

    for(int k = 0; k < SIZE_ARRAY_2; k++)
        delete[] weight2[k];
    delete[] weight2;

    for(int k = 0; k < SIZE_ARRAY_OUT; k++)
        delete[] weight3[k];
    delete[] weight3;

    delete[] shift1;
    delete[] shift2;
    delete[] shift3;
    delete[] error1;
    delete[] error2;
    delete[] error3;
}

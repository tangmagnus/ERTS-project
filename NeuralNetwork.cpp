// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "ArrayDefinitions.h"
#include "InputImages.h"


#define numInputs 784
#define numHiddenNodes 30
#define numOutputs 18


int relu(int x)
{
    return (x > 0) ? x : 0;
}

void softmax(double* input, size_t size) {

    assert(0 <= size <= sizeof(input) / sizeof(double));

    int i;
    double m, sum, constant;

    m = -INFINITY;
    for (i = 0; i < size; ++i) {
        if (m < input[i]) {
            m = input[i];
        }
    }

    sum = 0.0;
    for (i = 0; i < size; ++i) {
        sum += exp(input[i] - m);
    }

    constant = m + log(sum);
    for (i = 0; i < size; ++i) {
        input[i] = exp(input[i] - constant);
    }

}


int main(void)
{
    // needs to get a images as and 784 array
    double input[numInputs];
    double hiddenLayer[numHiddenNodes];
    double output[numOutputs];

    for (int i = 0; i < numHiddenNodes; i++)
    {
        double sum = fc1_bias[i];
        for (int j = 0; j < numInputs; j++)
        {
            sum += test_array[j] * fc1_weights[i][j];
        }
        hiddenLayer[i] = relu(sum);
    }

    for (int i = 0; i < numOutputs; i++)
    {
        double sum = fc2_bias[i];
        for (int j = 0; j < numHiddenNodes; j++)
        {
            sum += hiddenLayer[j] * fc2_weights[i][j];
        }
        output[i] = sum;

        printf("prediction for it to be %d is %g \n", i, output[i]);
    }

    softmax(output, numOutputs);
    //To print
    // printf("Softmax Array: ");
    // for (int i = 0; i < numOutputs; ++i)
    //     printf("%lf ", output[i]);
    // printf("\n\n");
    
}
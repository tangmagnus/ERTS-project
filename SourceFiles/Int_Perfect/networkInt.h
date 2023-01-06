#ifndef NETWORK 
#define NETWORK_H

//#include <systemc.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <algorithm>

#include "ArrayDefinitionsInt.h"

#define numInputs 784
#define numHiddenNodes 30
#define numOutputs 18


class Network {
private:

public:

    //network functions
    //reLu activation function
    int reLU(int x) {
        return (x > 0) ? x : 0;
    }
    //void outActiviation_softMax();
    int forward(int input_array[numInputs])
    {
        int hiddenLayer[numHiddenNodes];
        int intOutput[numOutputs];
        int sum1[numHiddenNodes];
        int digitis = 100;


        for (int i = 0; i < numHiddenNodes; i++)
        {
            sum1[i] = fc1_bias[i];
            if (i < numOutputs)
            {
                intOutput[i] = fc2_bias[i];
            }

        }

        for (int i = 0; i < numHiddenNodes; i++)
        {
            for (int j = 0; j < numInputs; j++)
            {
                sum1[i] += input_array[j] * fc1_weights[i][j];
            }
        }

        for (int i = 0; i < numHiddenNodes; i++)
        {
            hiddenLayer[i] = reLU(sum1[i]);
        }


        for (int i = 0; i < numOutputs; i++)
        {
            for (int j = 0; j < numHiddenNodes; j++)
            {
                intOutput[i] += hiddenLayer[j] * fc2_weights[i][j];
            }
        }

        int element = 0;
        for (int i = 0; i < numOutputs; i++)
        {
            if (intOutput[element] < intOutput[i])
                element = i;
        }

        return element;
    }

};



#endif 


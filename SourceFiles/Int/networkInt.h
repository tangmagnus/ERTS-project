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
    static Network* network_;
    
    Network()
    {
    }
    
    int digitis;

    int input[numInputs];
    int hiddenLayer[numHiddenNodes];
    int intOutput[numOutputs];

public:

    Network(const Network& other) = delete;
    
    static Network *Network::GetInstance()
    {
        return network_;
    }

    //network functions
    //reLu activation function
    int reLU(int x) {
        return (x > 0) ? x : 0;
    }
    //void outActiviation_softMax();
    int forward(float input_array[numInputs])
    {
        digitis = 100;
        if (input_array == NULL)
        {
            return -1;
        }
        for (int i = 0; i < numInputs; i++) {
            input[i] = static_cast<int>(input_array[i] * digitis);
        }

        int sum1[numHiddenNodes];

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
        fc1_inner:for (int j = 0; j < numInputs; j++)
        {
            sum1[i] += input[j] * fc1_weights[i][j];
        }
        }

        for (int i = 0; i < numHiddenNodes; i++)
        {
            hiddenLayer[i] = reLU(sum1[i]);
        }


        for (int i = 0; i < numOutputs; i++)
        {
        fc2_inner:for (int j = 0; j < numHiddenNodes; j++)
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

Network *Network::network_ = new Network();

/**
 * Static methods should be defined outside the class.
 */


#endif 


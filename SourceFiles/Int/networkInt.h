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
protected:
    Network(void):digitis(100)
    {
    }
    static Network* network_;


private:
    int digitis;

    int input[numInputs];
    int hiddenLayer[numHiddenNodes];
    int intOutput[numOutputs];

public:

    /**
         * Singletons should not be cloneable.
         */
    Network(Network& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Network&) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
     //constructor

    static Network* GetInstance();

    //network functions
    //reLu activation function
    int reLU(int x) {
        return (x > 0) ? x : 0;
    }
    //void outActiviation_softMax();
    int forward(float input_array[numInputs])
    {
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

        /*for (int i = 0; i < numOutputs; i++)
        {
            printf("Label: %d - Probability: %d \n", i, intOutput[i]);
        }*/
    }

};

Network* Network::network_ = nullptr;;

/**
 * Static methods should be defined outside the class.
 */
Network *Network::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(network_== nullptr){
    	network_ = new Network();
    }
    return network_;
}

#endif 


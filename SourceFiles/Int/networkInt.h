#ifndef NETWORK 
#define NETWORK_H

//#include <systemc.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <algorithm>

#define numInputs 784
#define numHiddenNodes 30
#define numOutputs 18


class Network {
private:
    int digitis = 100;

    int input[numInputs];
    int hiddenLayer[numHiddenNodes] = {};
    int intOutput[numOutputs] = {};

public:
    //network functions
    int reLU(int x);
    void outActiviation_softMax();
    void forward();

    //constructor
    Network(float input_array[]);
};

#endif 


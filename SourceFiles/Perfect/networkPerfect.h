#ifndef NETWORKPERFECT 
#define NETWORKPERFECT_H

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


class NetworkPerfect {
private:
    float input[numInputs];
    float hiddenLayer[numHiddenNodes] = {};
    float output[numOutputs] = {};

public:
    //network functions
    float reLU(float x);
    //void outActiviation_softMax();
    void forward();

    //constructor
    NetworkPerfect(float input_array[]);
};

#endif 


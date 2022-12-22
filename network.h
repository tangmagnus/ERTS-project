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


/*
SC_MODULE(Network) {
    //ports


    //functions 
    


    //constructor
}
*/


class Network {
private:
    double input[numInputs];
    double hiddenLayer[numHiddenNodes] = {};
    double output[numOutputs] = {};

public:
    //network functions
    int reLU(int x);
    void outActiviation_softMax();
    void forward();

    //constructor
    Network(double input_array[]);
};

#endif 


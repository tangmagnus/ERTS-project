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
protected:
	Network();


private:
	static Network* network_;

    int digitis;

    int input[numInputs];
    int hiddenLayer[numHiddenNodes];
    int intOutput[numOutputs];

public:
    //network functions
    int reLU(int x);
    //void outActiviation_softMax();
    int forward(float input_array[numInputs]);


    /**
         * Singletons should not be cloneable.
         */
    //Network(Network &other) = delete;
        /**
         * Singletons should not be assignable.
         */
    //void operator=(const Network &) = delete;
        /**
         * This is the static method that controls the access to the singleton
         * instance. On the first run, it creates a singleton object and places it
         * into the static field. On subsequent runs, it returns the client existing
         * object stored in the static field.
         */
    //constructor
    static Network *GetInstance();
};

/**
 * Static methods should be defined outside the class.
 */
Network *Network::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(network_== NULL){
    	network_ = new Network();
    }
    return network_;
}

#endif 


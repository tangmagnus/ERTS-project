// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "networkInt.h"
#include "InputImages.h"


int main(void) {
	Network newNetwork(test_array2);
	newNetwork.forward();
	newNetwork.outActiviation_softMax();

}
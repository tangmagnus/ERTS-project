// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "networkPerfect.h"
#include "InputImages.h"


int main(void) {
	NetworkPerfect newNetwork(two_array);
	newNetwork.forward();
	newNetwork.outActiviation_softMax();

}

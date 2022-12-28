// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "networkInt.h"

int NeuralNetwork(float img_array[numInputs]) {
	Network* newNetwork = Network::GetInstance();
	int res = newNetwork->forward(img_array);
	return res;
}

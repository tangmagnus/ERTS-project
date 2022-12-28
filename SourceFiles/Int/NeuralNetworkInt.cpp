// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "networkInt.h"
#include "InputImages.h"

int NeuralNetwork(float img_array[numInputs]) {
	Network *network = Network::GetInstance();
	int res = network->forward(img_array);
	return res;
}

int main(void) {
	NeuralNetwork(test_array0);
}

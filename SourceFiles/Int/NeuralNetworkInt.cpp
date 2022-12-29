// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "NeuralNetworkInt.hpp"

int NeuralNetwork(float img_array[numInputs]) {
	return Network::Instance().forward(img_array);

}


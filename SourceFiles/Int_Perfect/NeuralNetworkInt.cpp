// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "InputImages.h"
#include "networkInt.h"


int main() 
{
	Network network = Network();
	printf("%d", network.forward(test_array0));
}
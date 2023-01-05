// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "InputImages.h"
#include "networkInt.h"


int main() 
{
	printf("%d", Network::Instance().forward(test_array0));
}
// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "InputImages.h"
#include "networkInt.h"


int main() 
{

	printf("%d", Network::getInstance().image_process(test_array0));
	printf("%d", Network::getInstance().image_process(test_array1));
	printf("%d", Network::getInstance().image_process(test_array2));
	printf("%d", Network::getInstance().image_process(test_array3));
	printf("%d", Network::getInstance().image_process(test_array4));
	printf("%d", Network::getInstance().image_process(test_array5));
	printf("%d", Network::getInstance().image_process(test_array6));
	printf("%d", Network::getInstance().image_process(test_array7));
	printf("%d", Network::getInstance().image_process(test_array8));
	printf("%d", Network::getInstance().image_process(test_array9));
	printf("%d", Network::getInstance().image_process(test_arrayplus));
	printf("%d", Network::getInstance().image_process(test_arrayminus));
	printf("%d", Network::getInstance().image_process(test_arraydot));
	printf("%d", Network::getInstance().image_process(test_arrayslash));
	printf("%d", Network::getInstance().image_process(test_arrayw));
	printf("%d", Network::getInstance().image_process(test_arrayx));
	printf("%d", Network::getInstance().image_process(test_arrayy));
	printf("%d", Network::getInstance().image_process(test_arrayz));
	
}
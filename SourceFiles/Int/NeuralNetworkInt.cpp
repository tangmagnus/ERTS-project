// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "InputImages.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <algorithm>


int main() 
{
	printf("static int test_arrayz[784] = {");
	for (int i = 0; i < 784; i++) {
		printf("%d, ", static_cast<int>(test_arrayz[i] * 100));
	}
	printf("};");
}
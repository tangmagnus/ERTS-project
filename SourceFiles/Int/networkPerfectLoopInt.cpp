
#include "networkInt.h"
#include "ArrayDefinitionsInt.h"

//constructor
Network::Network() {
	digitis = 100;
}


//reLu activation function
int Network::reLU(int x) {
	return (x > 0) ? x : 0;
}


//softmax function to get probabilities in range [0,1]
/*void Network::outActiviation_softMax() {
    int element = 0;
    for (int i = 0; i < numOutputs; i++)
    {
        if (intOutput[element] < intOutput[i])
            element = i;
    }
    printf("\nThe number is Label: %d\n", element);
}*/

//calculation of network layers
int Network::forward(float input_array[numInputs]) {

	if(input_array == NULL)
	{
		return -1;
	}
	for (int i = 0; i < numInputs; i++) {
		input[i] = static_cast<int>(input_array[i] * digitis);
	}

    int sum1[numHiddenNodes];

    for (int i = 0; i < numHiddenNodes; i++)
    {
        sum1[i] = fc1_bias[i];
        if (i < numOutputs)
        {
            intOutput[i] = fc2_bias[i];
        }
        
    }

    for (int i = 0; i < numHiddenNodes; i++)
    {   
        fc1_inner:for (int j = 0; j < numInputs; j++)
        {
            sum1[i] += input[j] * fc1_weights[i][j];            
        }
    }

    for (int i = 0; i < numHiddenNodes; i++)
    {
        hiddenLayer[i] = reLU(sum1[i]);
    }


    for (int i = 0; i < numOutputs; i++)
    {
        fc2_inner:for (int j = 0; j < numHiddenNodes; j++)
        {
            intOutput[i] += hiddenLayer[j] * fc2_weights[i][j];
        } 
    }
    
    int element = 0;
    for (int i = 0; i < numOutputs; i++)
    {
    	if (intOutput[element] < intOutput[i])
        element = i;
    }
    return element;

    /*for (int i = 0; i < numOutputs; i++)
    {
        printf("Label: %d - Probability: %d \n", i, intOutput[i]);
    }*/
     
}




#include "networkInt.h"
#include "ArrayDefinitions.h"

//constructor
Network::Network(float input_array[]) {
    for (int i = 0; i < numInputs; i++) {
        input[i] = static_cast<int>(input_array[i] * digits);
    }
}


//reLu activation function
int Network::reLU(int x) {
	return (x > 0) ? x : 0;
}


/*
//softmax function to get probabilities in range [0,1]
void Network::outActiviation_softMax() {
    int element = 0;
    for (int i = 0; i < numOutputs; i++)
    {
        if (intOutput[element] < intOutput[i])
            element = i;
    }
    //printf("\nThe number is Label: %d\n", element);

}
*/

//calculation of network layers
void Network::forward() {
    
    int sum1[numHiddenNodes];
    int sum2[numOutputs];
    
    //step 1: insert bias 
    for (int i = 0; i < numHiddenNodes; i++)
    {
        sum1[i] = fc1_bias[i];

        if (i < numOutputs)
        {
            intOutput[i] = fc2_bias[i];
        }
    }

    //step 2: calculate hidden layer
    for (int i = 0; i < numHiddenNodes; i++)
    {   
        for (int j = 0; j < numInputs; j++)
        {
            sum1[i] += input[j] * fc1_weights[i][j]; 
        }
    }

    //step 3: relu on hidden layer 
    for (int i = 0; i < numHiddenNodes; i++)
    {
        hiddenLayer[i] = reLU(sum1[i]);
    }

    //step 4: calulcate output layer
    for (int i = 0; i < numOutputs; i++)
    {
        for (int j = 0; j < numHiddenNodes; j++)
        {
            intOutput[i] += hiddenLayer[j] * fc2_weights[i][j];
        } 
    }

    /*
    for (int i = 0; i < numOutputs; i++)
    {
        printf("Label: %d - Probability: %lld \n", i, intOutput[i]);
    }
    */
       
}



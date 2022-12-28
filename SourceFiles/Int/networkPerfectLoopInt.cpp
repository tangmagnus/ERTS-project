
#include "networkInt.h"
#include "ArrayDefinitionsInt.h"

//constructor
Network::Network(float input_array[]) {
    for (int i = 0; i < numInputs; i++) {
        input[i] = static_cast<int>(input_array[i] * digitis);
    }
}


//reLu activation function
int Network::reLU(int x) {
	return (x > 0) ? x : 0;
}


//softmax function to get probabilities in range [0,1]
void Network::outActiviation_softMax() {
    int element = 0;
    for (int i = 0; i < numOutputs; i++)
    {
        if (intOutput[element] < intOutput[i])
            element = i;
    }
    printf("\nThe number is Label: %d\n", element);
}

//calculation of network layers
void Network::forward() {
    
    double sum1[numHiddenNodes];

    int lasti = -1;
    for (int i = 0; i < numHiddenNodes; i++)
    {   
        for (int j = 0; j < numInputs; j++)
        {
            if (lasti < i)
            {
                lasti = i;
                sum1[i] = fc1_bias[i];
                if (i > 0)
                {
                    hiddenLayer[i-1] = reLU(sum1[i-1]);
                }
                
            }
            sum1[i] += input[j] * fc1_weights[i][j];            
        }
    }

    hiddenLayer[numHiddenNodes - 1] = reLU(sum1[numHiddenNodes - 1]);

    lasti = -1;
    for (int i = 0; i < numOutputs; i++)
    {
        for (int j = 0; j < numHiddenNodes; j++)
        {
            if (lasti < i)
            {
                lasti = i;
                intOutput[i] = fc2_bias[i];
            }
            intOutput[i] += hiddenLayer[j] * fc2_weights[i][j];
        } 
    }
    
    for (int i = 0; i < numOutputs; i++)
    {
        printf("Label: %d - Probability: %d \n", i, intOutput[i]);
    }
     
}



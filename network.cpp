
#include "network.h"
#include "ArrayDefinitions.h"

//constructor
Network::Network(double input_array[]) {
    for (int i = 0; i < numInputs; i++) {
        input[i] = input_array[i];
    }
}



//reLu activation function
int Network::reLU(int x) {
	return (x > 0) ? x : 0;
}


//softmax function to get probabilities in range [0,1]
void Network::outActiviation_softMax() {

    assert(0 <= numOutputs <= sizeof(output) / sizeof(double));

    int i;
    double m, sum, constant;

    m = -INFINITY;
    for (i = 0; i < numOutputs; ++i) {
        if (m < output[i]) {
            m = output[i];
        }
    }

    sum = 0.0;
    for (i = 0; i < numOutputs; ++i) {
        sum += exp(output[i] - m);
    }

    constant = m + log(sum);
    for (i = 0; i < numOutputs; ++i) {
        output[i] = exp(output[i] - constant);
    }

    //To print
    printf("\n\nSoftmax Array:\n ");
    for (int i = 0; i < numOutputs; ++i) {
        printf("Label: %d - Probability: %lf ", i, output[i]);
        printf("\n");
    }
}

//calculation of network layers
void Network::forward() {

    for (int i = 0; i < numHiddenNodes; i++)
    {
        double sum = fc1_bias[i];
        for (int j = 0; j < numInputs; j++)
        {
            sum += input[j] * fc1_weights[i][j];
        }
        hiddenLayer[i] = reLU(sum);
    }

    for (int i = 0; i < numOutputs; i++)
    {
        double sum = fc2_bias[i];
        for (int j = 0; j < numHiddenNodes; j++)
        {
            sum += hiddenLayer[j] * fc2_weights[i][j];
        }
        output[i] = sum;

        printf("Label: %d - Probability: %g \n", i, output[i]);
    }
}



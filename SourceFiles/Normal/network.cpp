
#include "network.h"
#include "ArrayDefinitions.h"
#include <iomanip>

/*
//dictionary 
std::map<int, std::string> digits{
    {0, "0"},
    {1, "1"},
    {2, "2"},
    {3, "3"},
    {4, "4"},
    {5, "5"},
    {6, "6"},
    {7, "7"},
    {8, "8"},
    {9, "9"},
    {10, "plus"},
    {11, "minus"},
    {12, "slash"},
    {13, "dot"},
    {14, "w"},
    {15, "x"},
    {16, "y"},
    {17, "z"}
};
*/

//constructor
Network::Network(float input_array[]) {
    for (int i = 0; i < numInputs; i++) {
        input[i] = input_array[i];
    }
}


//reLu activation function
float Network::reLU(float x) {
	return (x > 0) ? x : 0;
}


/*
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
    printf("\n\nSoftmax Probabilities:\n");
    for (int i = 0; i < numOutputs; ++i) {
        //printf("Label: %d  /  Probability: %lf\n", i, output[i]);
        std::cout << std::fixed << "Label: " << digits[i] << "  /  Probability: " << output[i] << endl;
    }
}
*/


//calculation of network layers
void Network::forward() {
    //std::cout << "Logit Probabilities:" << endl;

    for (int i = 0; i < numHiddenNodes; i++)
    {
    	float sum = fc1_bias[i];
        forward_label0:for (int j = 0; j < numInputs; j++)
        {

            sum += input[j] * fc1_weights[i][j];
        }
        hiddenLayer[i] = reLU(sum);
    }

    for (int i = 0; i < numOutputs; i++)
    {
    	float sum = fc2_bias[i];
        forward_label1:forward_label2:for (int j = 0; j < numHiddenNodes; j++)
        {
            sum += hiddenLayer[j] * fc2_weights[i][j];
        }
        output[i] = sum;

        //std::cout << "Label: " << digits[i] << "  /  Probability: " << output[i] << endl;
    }

 
}




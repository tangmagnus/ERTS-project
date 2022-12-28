
#include "networkPerfect.h"
#include "ArrayDefinitions.h"

//constructor
NetworkPerfect::NetworkPerfect(float input_array[]) {
    for (int i = 0; i < numInputs; i++) {
        input[i] = input_array[i];
    }
}


//reLu activation function
float NetworkPerfect::reLU(float x) {
	return (x > 0) ? x : 0;
}



//softmax function to get probabilities in range [0,1]
void NetworkPerfect::outActiviation_softMax() {

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
void NetworkPerfect::forward() {
    
    float sum1[numHiddenNodes];
    
    int lasti = -1;
    //step 2: calculate hidden layer
    for (int i = 0; i < numHiddenNodes; i++)
    {
        forward_label0:for (int j = 0; j < numInputs; j++)
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
    //step 4: calculate output layer
    for (int i = 0; i < numOutputs; i++)
    {
        forward_label1:for (int j = 0; j < numHiddenNodes; j++)
        {
            if (lasti < i)
            {
                lasti = i;
                output[i] = fc2_bias[i];
            }
            output[i] += hiddenLayer[j] * fc2_weights[i][j];
        }  
    }

    
    for (int i = 0; i < numOutputs; i++)
    {
        printf("Label: %d - Probability: %g \n", i, output[i]);
    }
    
       
}



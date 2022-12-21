#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int relu(int x)
{
    return (x > 0 ) ? x : 0;
}

#define numInputs 784
#define numHiddenNodes 30
#define numOutputs 18
int main(void)
{
    // needs to get a immages as and 784 array
    double input[numInputs];


    double hiddenLayer[numHiddenNodes];
    double output[numOutputs];



    for (int i = 0; i < numHiddenNodes; i++)
    {
        double sum = fc1Bias[i];
        for (int j = 0; j < numInputs; j++)
        {
            sum += input[j] * fc1Weights[j][i];
        }
        hiddenLayer[i] = relu(sum);
    }

    for (int i = 0; i < numOutputs; i++)
    {
        double sum = fc2Bias[i];
        for (int j = 0; j < numHiddenNodes; j++)
        {
            sum += hiddenLayer[j] * fc2Weights[j][i];
        }
        output[i] = sum;

        printf("prediction for it to be %d is %g \n", i, output[i]);
    }
    


}

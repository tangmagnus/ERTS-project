
#include "networkInt.h"
#include "ArrayDefinitions.h"

//constructor
Network::Network(double input_array[]) {
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
    double sum2[numOutputs];
    
    //std::cout << "int fc1_bias[] = {";
    for (int i = 0; i < numHiddenNodes; i++)
    {
        sum1[i] = fc1_bias[i];

        //std::cout << static_cast<int>(fc1_bias[i]*digitis) << ", ";

        if (i < numOutputs)
        {
            intOutput[i] = fc2_bias[i];
        }
    }
    //std::cout << "};" << std::endl << std::endl;

    /*std::cout << "int fc2_bias[] = {";
    for (int i = 0; i < numOutputs; i++)
    {

            output[i] = fc2_bias[i];
            std::cout << static_cast<int>(fc2_bias[i] * digitis) << ", ";
    }
    std::cout << "};" << std::endl << std::endl;
    */
    
    //std::cout << "int fc1_weights[30][784] ={";
    for (int i = 0; i < numHiddenNodes; i++)
    {   
        //std::cout << "{";
        for (int j = 0; j < numInputs; j++)
        {
            sum1[i] += input[j] * fc1_weights[i][j];
            /*
            if (j == numInputs - 1)
            {
                std::cout << static_cast<int>(fc1_weights[i][j] * digitis);
            }
            else
            {
                std::cout << static_cast<int>(fc1_weights[i][j] * digitis) << ", ";
            }
            */
            
        }
        /*
        if (i == numHiddenNodes - 1)
        {
            std::cout << "}" << std::endl;
        }
        else
        {
            std::cout << "}," << std::endl;
        }
        */
    }
    //std::cout << "};" << std::endl << std::endl;

    for (int i = 0; i < numHiddenNodes; i++)
    {
        hiddenLayer[i] = reLU(sum1[i]);
    }

    //std::cout << "int fc2_weights[18][30] = {";
    for (int i = 0; i < numOutputs; i++)
    {
        //std::cout << "{";
        for (int j = 0; j < numHiddenNodes; j++)
        {
            intOutput[i] += hiddenLayer[j] * fc2_weights[i][j];
            /*
            if (j == numHiddenNodes - 1)
            {
                std::cout << static_cast<int>(fc2_weights[i][j] * digitis);
            }
            else
            {
                std::cout << static_cast<int>(fc2_weights[i][j] * digitis) << ", ";
            }*/
            
        } 
        /*if (i == numOutputs - 1)
        {
           std::cout << "}" << std::endl;
        }
        else
        {
            std::cout << "}," << std::endl;
        }*/
    }
    //std::cout << "};" << std::endl << std::endl;

    for (int i = 0; i < numOutputs; i++)
    {
        printf("Label: %d - Probability: %lld \n", i, intOutput[i]);
    }
       
}



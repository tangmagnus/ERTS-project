#ifndef NETWORK 
#define NETWORK_H

#include <stdio.h>


#define numInputs 784

class Network {
private:    
	Network(){};
	Network(Network const&);
	void operator=(Network const&);
	//~Network();

    int test;


public:

    static Network& getInstance()
    {
        static Network inst;
        return inst;
    }
    
    int image_process(int input_array[numInputs])
    {
        return 1;
    }


};

#endif 


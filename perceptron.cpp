#include <iostream>
#include <string>

class Perceptron {
    public:

        Perceptron(int length, int size, int outLength) {
            idataLength = length;
            idataSize = size;
            ioutLength = outLength;

            input_array();
            expected_outputarray();
        }

        int fill_array();

    private:
        int idataLength;
        int idataSize;
        int ioutLength;

        float **ineuronInputs;

        float *expectedOutput;

        int input_array();
        int expected_outputarray();

};


//make the array for the inputs
int Perceptron::input_array(){
    
    ineuronInputs = new float*[idataSize];

    for(int i = 0; i < idataLength; i++){
        ineuronInputs[i] = new float[idataLength];
    }

    return 0;
}

int Perceptron::expected_outputarray(){
    expectedOutput = new float[ioutLength];
}


//Fill the array with the needed input
//Soon: fill the array with the input from a file
int Perceptron::fill_array(){
    return 0;
}
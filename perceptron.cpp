#include <iostream>
#include <string>
#include <fstream>

class Perceptron {
    public:
        Perceptron(int length, int size, int outLength) {
            idataLength = length;
            idataSize = size;
            ioutLength = outLength;

            initInput();
            initExpectedOut();
            initOut();

        }

        int fillData();
        void printArray();

    private:
        int idataLength;
        int idataSize;
        int ioutLength;

        float **ineuronIn;
        float *ineuronOut;
        float *iexpectedOut;

        int initInput();
        int initExpectedOut();
        int initOut();
        
};

int Perceptron::initInput() {
    ineuronIn = new float *[idataSize];

    for (int i = 0; i < idataSize; i++) {
        ineuronIn[i] = new float[idataLength]();
    }

    return 0;
}

int Perceptron::initOut(){
    ineuronOut = new float[ioutLength]();

    return 0;
}

int Perceptron::initExpectedOut(){
    iexpectedOut = new float[idataSize]();

    return 0;
}

int Perceptron::fillData(){
    std::ifstream inputFile;

    inputFile.open("dataset.dat");

    for (int i = 0; i < idataSize; i++) 
    {
        inputFile >> iexpectedOut[i];
        for (int j = 0; j < idataLength; j++)
        {
            inputFile >> ineuronIn[i][j];
        }
    }

    inputFile.close();
    return 0;
}

void Perceptron::printArray(){
    for (int i = 0; i < idataSize; i++)
    {
        std::cout << iexpectedOut[i]<< "\n";
        for (int j = 0; j < idataLength; j++)
        {
            std::cout << ineuronIn[i][j] << " ";
        }
        std::cout << "\n";
    }
}
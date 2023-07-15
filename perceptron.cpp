#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class Perceptron {
    public:
        Perceptron(int length, int size, int outLength) {
            idataLength = length;
            idataSize = size;
            ioutLength = outLength;

            initInput();
            initExpectedOut();
            initOut();
            initNeuronWeights();

        }

        int fillData();
        void printArray();

        double sigmoid(double num);
        double sigmoidPrime(double num);

    private:
        int idataLength;
        int idataSize;
        int ioutLength;

        double **ineuronIn;
        double *ineuronOut;
        double *iexpectedOut;
        double *ineuronWeight;

        int initInput();
        int initExpectedOut();
        int initOut();
        int initNeuronWeights();



};

int Perceptron::initInput() {
    ineuronIn = new double *[idataSize];

    for (int i = 0; i < idataSize; i++) {
        ineuronIn[i] = new double[idataLength]{};
    }

    return 0;
}

int Perceptron::initOut(){
    ineuronOut = new double[ioutLength]{};

    return 0;
}

int Perceptron::initExpectedOut(){
    iexpectedOut = new double[idataSize]{};

    return 0;
}

int Perceptron::initNeuronWeights(){
    ineuronWeight = new double[(idataLength * ioutLength)]{};

    return 0;
}

int Perceptron::fillData(){
    std::ifstream dataFile;

    dataFile.open("dataset.dat");

    for (int i = 0; i < idataSize; i++) 
    {
        dataFile >> iexpectedOut[i];
        for (int j = 0; j < idataLength; j++)
        {
            dataFile >> ineuronIn[i][j];
        }
    }

    dataFile.close();
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

double Perceptron::sigmoid(double num){
  
  double y = 1 / (1 + exp(-num));
  
  return y;
}

double Perceptron::sigmoidPrime(double num){
  
  double y = exp(num) / pow(1 + exp(num), 2);
  
  return y;
}
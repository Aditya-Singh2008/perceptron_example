#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

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
        void printOut();
        double feedForward(int irow);
        double lossFunction(int irow);


        double sigmoid(double num);
        double sigmoidPrime(double num);

    private:
        int idataLength;
        int idataSize;
        int ioutLength;

        double **dneuronIn;
        double *dneuronOut;
        double *dexpectedOut;
        double *dneuronWeight;

        double dactivation = 0.0;
        double dloss = 0.0;

        int initInput();
        int initExpectedOut();
        int initOut();
        int initNeuronWeights();

};

int Perceptron::initInput() {
    dneuronIn = new double *[idataSize];

    for (int i = 0; i < idataSize; i++) {
        dneuronIn[i] = new double[idataLength]{};
    }

    return 0;
}

int Perceptron::initOut(){
    dneuronOut = new double[ioutLength]{};

    return 0;
}

int Perceptron::initExpectedOut(){
    dexpectedOut = new double[idataSize]{};

    return 0;
}

int Perceptron::initNeuronWeights(){
    dneuronWeight = new double[(idataLength * ioutLength)];
    std::srand(std::time(0));

    for(int i = 0; i < (idataLength * ioutLength); i++){
        dneuronWeight[i] = std::rand() % 21 - 10;
    }

    return 0;
}

int Perceptron::fillData(){
    std::ifstream dataFile;

    dataFile.open("dataset.dat");

    for (int i = 0; i < idataSize; i++) 
    {
        dataFile >> dexpectedOut[i];
        for (int j = 0; j < idataLength; j++)
        {
            dataFile >> dneuronIn[i][j];
        }
    }

    dataFile.close();
    return 0;
}

void Perceptron::printArray(){
    for (int i = 0; i < idataSize; i++)
    {
        std::cout << dexpectedOut[i]<< "\n";
        for (int j = 0; j < idataLength; j++)
        {
            std::cout << dneuronIn[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Perceptron::printOut(){
    for (int i = 0; i < idataSize; i++)
    {
        std::cout << dneuronOut[i] << "\n";
    }
}

double Perceptron::sigmoid(double num){
  double y = 1.0 / (1.0 + exp(-num));
  
  return y;
}

double Perceptron::sigmoidPrime(double num){
  double y = exp(num) / pow(1.0 + exp(num), 2);
  
  return y;
}

double Perceptron::feedForward(int irow){
    double dneuronWeightedSum = 0.0;

    for(int i = 0; i < idataLength; i++){
        dneuronWeightedSum += dneuronIn[irow][i] * dneuronWeight[i];
    }

    dactivation  = sigmoid(dneuronWeightedSum);

    dneuronOut[irow] = dactivation;

    return dactivation;
}

double Perceptron::lossFunction(int irow){

    for(int i = 0; i < idataLength; i++){
        dloss = (1.0 / 2.0) * pow((dexpectedOut[irow] - dneuronOut[irow]), 2.0);
    }

    return dloss;
}
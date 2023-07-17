#include "perceptron.cpp"
#include <iostream>

int main(){
    
    std::cout << "New Perceptron:\n\n";

    Perceptron *newPerceptron = new Perceptron(2, 10, 1);

    newPerceptron->fillData();
    newPerceptron->printArray();
    //std::cout << "FF:\n";
    //for(int i = 0; i < 10; i++){
        //newPerceptron->feedForward(i);
    //}
    //newPerceptron->printOut();

    for(int i = 0; i < 10; i++){
        std::cout << "\nFF:\n";
        std::cout << newPerceptron->feedForward(i);
        std::cout << "\nLSS\n";
        std::cout << newPerceptron->lossFunction(i);
        std::cout << "\nLSSP\n";
        std::cout << newPerceptron->lossFunctionPrime(i);
        std::cout << "\n";
    }

    

    delete  newPerceptron;
    
    return 0;
}

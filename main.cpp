#include "perceptron.cpp"
#include <iostream>

int main(){

    std::cout << "New Perceptron:\n\n";

    Perceptron *newPerceptron = new Perceptron(2, 10, 1);

    newPerceptron->fillData();
    newPerceptron->printArray();
    std::cout << "\n";
    for(int i = 0; i < 10; i++){
        newPerceptron->feedForward(i);
    }
    newPerceptron->printOut();

    for(int i = 0; i < 10; i++){
        std::cout << "\n";
        std::cout << newPerceptron->lossFunction(i);
    }

    

    delete  newPerceptron;
    
    return 0;
}
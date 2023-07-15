#include "perceptron.cpp"

int main(){

    std::cout << "Making New Perceptron\n";

    Perceptron *newPerceptron = new Perceptron(2, 10, 1);

    newPerceptron->fillData();
    newPerceptron->printArray();

    delete  newPerceptron;
    
    return 0;
}
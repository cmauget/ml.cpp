#include "../include/Neuron.hpp"

#include <cmath>
//cmd line to compile and run this file: g++ -std=c++14 -o TestNeuron.out TestNeuron.cpp Neuron.cpp Tensor.cpp
#ifndef fmeakzjbfmezaufb

vector<double> x1_data = {0.3, 0.5};
vector<double> x2_data = {1.0,2.0};
vector<double> x3_data = {0.7, 0.1};
vector<double> x4_data = {2.0, 1.0};
vector<double> y1_data = {1.0};
vector<double> y2_data = {1.0};
vector<double> y3_data = {-1.0};
vector<double> y4_data = {-1.0};

int main(){
    Tensor x1({1,2}, x1_data);
    Tensor x2({1,2}, x2_data);
    Tensor x3({1,2}, x3_data);
    Tensor x4({1,2}, x4_data);
    Tensor y1({1,1}, y1_data);
    Tensor y2({1,1}, y2_data);
    Tensor y3({1,1}, y3_data);
    Tensor y4({1,1}, y4_data);

    Neuron n1(2, 1);

    Tensor bias({1,1}, {0.5});

    //n1.setBias(bias);

    cout << "Initial dimensions" << x1 << endl;


    double learning_rate = 0.01;

    

    for(int i = 0; i < 1000; i++){

        double total_error = 0.0;
        //cout << "flag1" << endl;
        n1.forward(x1);
        //cout << "flag2" << endl;
        Tensor error = n1.backward(y1);
        //cout << "flag3" << endl;
        n1.updateWeights(x1, error, learning_rate);
        //cout << "flag4" << endl;
        total_error += pow(error.getData()[0],2);

        n1.forward(x2);
        error = n1.backward(y2);
        n1.updateWeights(x2, error, learning_rate);
        total_error += pow(error.getData()[0],2);

        n1.forward(x3);
        error = n1.backward(y3);
        n1.updateWeights(x3, error, learning_rate);
        total_error += pow(error.getData()[0],2);

        n1.forward(x4);
        error = n1.backward(y4);
        n1.updateWeights(x4, error, learning_rate);
        total_error += pow(error.getData()[0],2);

        cout << "ERROR : " << total_error/4.0 << endl;
    }

    cout << n1.getWeights() << endl;
    cout << n1.getBias() << endl;

    cout << "---------------" << endl;

    n1.forward(x1);
    cout << n1.getOutput() << endl;
    n1.forward(x2);
    cout << n1.getOutput() << endl;
    n1.forward(x3);
    cout << n1.getOutput() << endl;
    n1.forward(x4);
    cout << n1.getOutput() << endl;


    

    return 0;
}

#endif
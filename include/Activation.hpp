#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

#include "../include/Tensor.hpp"

#include <cmath>
#include <iostream>

using namespace std;

class Activation {

public:

    static double sigmoid(double x);

    static double sigmoid_prime(double x); 

    static double linear(double x); 

    static double relu(double x); 

    static double relu_prime(double x);

    static double leakyRelu(double x);

    static double leakyRelu_prime(double x);

    static double tanh(double x); 

    static double tanh_prime(double x);

    static Tensor sigmoid(Tensor x);

    static Tensor sigmoid_prime(Tensor x);

    static Tensor linear(Tensor x); 

    static Tensor relu(Tensor x);

    static Tensor relu_prime(Tensor x);

    static Tensor leakyRelu(Tensor x);

    static Tensor leakyRelu_prime(Tensor x);

    static Tensor tanh(Tensor x);

    static Tensor tanh_prime(Tensor x);

};


#endif
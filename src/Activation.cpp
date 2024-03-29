#include "../include/Activation.hpp"
#include <cmath>
#include <math.h> 

double Activation::sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double Activation::sigmoid_prime(double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

double Activation::linear(double x) {
    return x;
}

double Activation::relu(double x) {
    return x > 0 ? x : 0;
}

double Activation::relu_prime(double x) {
    return x > 0 ? 1 : 0;
}

double Activation::leakyRelu(double x) {
    return x > 0 ? x : 0.01 * x;
}

double Activation::leakyRelu_prime(double x) {
    return x > 0 ? 1 : 0.01;
}

double Activation::tanh(double x) {
    return ::tanh(x);
}

double Activation::tanh_prime(double x) {
    return 1 - pow(::tanh(x), 2);
}

Tensor Activation::sigmoid(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::sigmoid(data[i]);
    }
    return Tensor(x.getDim(), data);
}

Tensor Activation::sigmoid_prime(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::sigmoid_prime(data[i]);
    }
    return Tensor(x.getDim(), data);
}

Tensor Activation::linear(Tensor x) {
    return x;
}

Tensor Activation::relu(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::relu(data[i]);
    }
    return Tensor(x.getDim(), data);
}

Tensor Activation::relu_prime(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::relu_prime(data[i]);
    }
    return Tensor(x.getDim(), data);
}

Tensor Activation::leakyRelu(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::leakyRelu(data[i]);
    }
    return Tensor(x.getDim(), data);
}

Tensor Activation::leakyRelu_prime(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::leakyRelu_prime(data[i]);
    }
    return Tensor(x.getDim(), data);
}

Tensor Activation::tanh(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::tanh(data[i]);
    }
    return Tensor(x.getDim(), data);
}

Tensor Activation::tanh_prime(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::tanh_prime(data[i]);
    }
    return Tensor(x.getDim(), data);
}




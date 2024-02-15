#include "../include/Activation.hpp"

double Activation::sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double Activation::linear(double x) {
    return x;
}

double Activation::relu(double x) {
    return x > 0 ? x : 0;
}

double Activation::leakyRelu(double x) {
    return x > 0 ? x : 0.01 * x;
}

double Activation::tanh(double x) {
    return tanh(x);
}

Tensor Activation::sigmoid(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::sigmoid(data[i]);
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

Tensor Activation::leakyRelu(Tensor x) {
    vector<double> data = x.getData();
    for (int i = 0; i < data.size(); i++) {
        data[i] = Activation::leakyRelu(data[i]);
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


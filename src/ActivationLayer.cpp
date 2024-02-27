#include "../include/ActivationLayer.hpp"
#include "../include/Activation.hpp"

#include <stdexcept>

ActivationLayer::ActivationLayer(string activation_type) {
    if (activation_type == "sigmoid") {
        activation = Activation::sigmoid;
        activation_prime = Activation::sigmoid_prime;
    } else if (activation_type == "linear") {
        activation = Activation::linear;
        activation_prime = Activation::linear;
    } else if (activation_type == "relu") {
        activation = Activation::relu;
        activation_prime = Activation::relu;
    } else if (activation_type == "leakyRelu") {
        activation = Activation::leakyRelu;
        activation_prime = Activation::leakyRelu;
    } else if (activation_type == "tanh") {
        activation = Activation::tanh;
        activation_prime = Activation::tanh_prime;
    } else {
        throw invalid_argument("Activation type not recognized");
    }
}

Tensor ActivationLayer::forward(Tensor input_) {
    input = input_;
    Tensor act = activation(input);
    output = act;
    return output;
}

Tensor ActivationLayer::backward(Tensor grad,  double learning_rate) {
    return grad.element_wise_mult(activation_prime(input));
}
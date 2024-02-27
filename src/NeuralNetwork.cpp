#include "../include/NeuralNetwork.hpp"

#include <stdexcept>

NeuralNetwork::NeuralNetwork() {
    learning_rate = 0.01;
}

NeuralNetwork::NeuralNetwork(double learning_rate_, string loss_type_) {
    learning_rate = learning_rate_;

    if (loss_type_ == "mean_squared_error") {
        loss = Loss::mean_squared_error;
        loss_prime = Loss::mean_squared_error_prime;
    } else if (loss_type_ == "cross_entropy") {
        loss = Loss::cross_entropy;
        loss_prime = Loss::cross_entropy_prime;
    } else {
        throw invalid_argument("Loss type not recognized");
    }
}

void NeuralNetwork::setLearningRate(double learning_rate_) {
    learning_rate = learning_rate_;
}


void NeuralNetwork::setLoss(string loss_type_) {
    if (loss_type_ == "mean_squared_error") {
        loss = Loss::mean_squared_error;
        loss_prime = Loss::mean_squared_error_prime;
    } else if (loss_type_ == "cross_entropy") {
        loss = Loss::cross_entropy;
        loss_prime = Loss::cross_entropy_prime;
    } else {
        throw invalid_argument("Loss type not recognized");
    }
}

void NeuralNetwork::addLayer(Layer* layer) {
    layers.push_back(layer);
}

Tensor NeuralNetwork::forward(Tensor input) {
    Tensor output = input;
    for (int i = 0; i < layers.size(); i++) {
        output = layers[i]->forward(output);
    }
    return output;
}

double NeuralNetwork::compute_loss(Tensor output, Tensor label) {
    return loss(output, label);
}

Tensor NeuralNetwork::compute_loss_grad(Tensor output, Tensor label) {
    return loss_prime(output, label);
}

void NeuralNetwork::backward(Tensor error) {
    for (int i = layers.size() - 1; i >= 0; i--) {
        //cout << "Layer " << i << endl;
        //cout << "Error: " << error << endl;
        error = layers[i]->backward(error, learning_rate);
    }
}




#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include "Layer.hpp"
#include "Tensor.hpp"
#include "Loss.hpp"

class NeuralNetwork {

    public:
        vector<Layer*> layers; //I have to pass through pointers because Layer is abstract
        double learning_rate;

        double (*loss)(Tensor, Tensor);
        Tensor (*loss_prime)(Tensor, Tensor);

    public:
        NeuralNetwork();

        NeuralNetwork(double learning_rate, string loss_type);

        void setLearningRate(double learning_rate);

        void setLoss(string loss_type);

        void addLayer(Layer* layer);

        Tensor forward(Tensor input);

        void backward(Tensor label);

        double compute_loss(Tensor output, Tensor label);

        Tensor compute_loss_grad(Tensor output, Tensor label);

};

#endif // NEURALNETWORK_HPP
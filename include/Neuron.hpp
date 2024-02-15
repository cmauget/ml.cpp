#ifndef NEURON_HPP
#define NEURON_HPP

#include "Tensor.hpp"


class Neuron {
    
    public:
        int n_inputs;
        int n_outputs;
        Tensor weights;
        Tensor bias;
        Tensor output;

    public:
        Neuron();
        Neuron(int n_inputs);
        Neuron(int n_inputs, Tensor weights, Tensor bias);

        void setWeights(Tensor weights);
        void setBias(Tensor bias);
        void setOutput(Tensor output);

        Tensor getWeights();
        Tensor getBias();
        Tensor getOutput();

        void forward(Tensor inputs);
        Tensor backward(Tensor label);
        void updateWeights(Tensor inputs, Tensor error, double learning_rate);
        void updateBias(double learning_rate);
};

#endif
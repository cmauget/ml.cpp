#ifndef LAYER_HPP
#define LAYER_HPP

#include "Tensor.hpp"

class Layer {

    public:
        int n_inputs;
        int n_outputs;
        Tensor input;
        Tensor output;

    public:
        virtual Tensor forward(Tensor input) = 0;
        virtual Tensor backward(Tensor grad, double learning_rate) = 0;
};

#endif // LAYER_HPP

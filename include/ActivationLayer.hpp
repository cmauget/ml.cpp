#ifndef ACTIVATIONLAYER_HPP
#define ACTIVATIONLAYER_HPP

#include "Tensor.hpp"
#include "Layer.hpp"
#include "Activation.hpp"

class ActivationLayer : public Layer {

    public:
        // int n_inputs;
        // int n_outputs;
        // Tensor input;
        // Tensor output;

        Tensor (*activation)(Tensor);
        Tensor (*activation_prime)(Tensor);

    public:
    
        ActivationLayer(string activation_type);

        Tensor forward(Tensor input) override;

        Tensor backward(Tensor grad, double learning_rate) override;

};

#endif // ACTIVATIONLAYER_HPP
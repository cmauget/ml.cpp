#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "Layer.hpp"
#include "Tensor.hpp"

#include <stdlib.h>

using namespace std;

class Linear : public Layer {

    public:
        // int n_inputs;
        // int n_outputs;
        // Tensor input;
        // Tensor output;
        Tensor weights;
        Tensor bias;

    public:
        Linear(int input_size, int output_size);

        static Tensor generateRandomWeights(std::vector<int> dim, double min, double max);

    
        void randomizeWeights(double min, double max);
        
        Tensor forward(Tensor input) override ;
        Tensor backward(Tensor grad, double learning_rate) override;

};

#endif // LINEAR_HPP
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

        //constructors and destructors
        Linear(int input_size, int output_size, bool randomize = true);

        //getters and setters
        void setWeights(Tensor weights);
        void setBias(Tensor bias);
        Tensor getWeights();
        Tensor getBias();
        
        //forward and backward
        Tensor forward(Tensor input) override ;
        Tensor backward(Tensor grad, double learning_rate) override;

        //utils functions
        static Tensor generateRandomWeights(std::vector<int> dim, double min, double max);
        void randomizeWeights(double min, double max);

};

#endif // LINEAR_HPP
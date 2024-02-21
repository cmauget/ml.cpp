#include "../include/Linear.hpp"

Linear::Linear(int input_size, int output_size) {
    n_inputs = input_size;
    n_outputs = output_size;
    weights = Tensor({n_inputs, n_outputs});
    bias = Tensor({n_outputs, 1});
    output = Tensor({n_outputs, 1});
}

Tensor Linear::forward(Tensor input_) {
    input = input_;
    //cout << "weights: " << weights << endl;
    output = weights.T() * input;
    output = output + bias;
    return output;
}

Tensor Linear::backward(Tensor grad, double learning_rate) {
    Tensor grad_weights = input * grad.T();
    Tensor grad_bias = grad;
    Tensor grad_input = grad * weights;
    weights = weights -  grad_weights * learning_rate; //Always use on this order : Tensor * double
    bias = bias - grad_bias * learning_rate;
    return grad_input;
}

Tensor Linear::generateRandomWeights(vector<int> dim, double min, double max) {
    //randomly generate data
    vector<double> data;
    for(int i = 0; i < (dim[0]*dim[1]); i++) {
        data.push_back(((double)rand() / RAND_MAX)*(max-min)+min);
        cout << data[i] << endl;
    }

    Tensor t(dim, data);
    return t;
}

void Linear::randomizeWeights(double min, double max) {
    weights = generateRandomWeights({n_outputs, n_inputs}, min, max);
    bias = generateRandomWeights({n_outputs, 1}, min, max);
}
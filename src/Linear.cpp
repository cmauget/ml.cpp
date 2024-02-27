#include "../include/Linear.hpp"

Linear::Linear(int input_size, int output_size, bool randomize) {
    n_inputs = input_size;
    n_outputs = output_size;
    weights = Tensor({n_inputs, n_outputs});
    bias = Tensor({n_outputs, 1});
    output = Tensor({n_outputs, 1});
    //if (randomize){
     //   this->randomizeWeights(0, 1);
   // }
}

void Linear::setWeights(Tensor weights_) {
    weights = weights_;
}

void Linear::setBias(Tensor bias_) {
    bias = bias_;
}

Tensor Linear::getWeights() {
    return weights;
}

Tensor Linear::getBias() {
    return bias;
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
    Tensor grad_input =  weights * grad;
    //cout << "grad" << grad << endl;
    //cout << "grad_weights" << grad_weights << endl;
   //cout << "update" << grad_weights*learning_rate << endl;
    weights = weights -  grad_weights * learning_rate; //Always use on this order : Tensor * double
    bias = bias - grad_bias * learning_rate;

    //cout << "grad_inputs" << grad_input << endl;

    return grad_input;
}

Tensor Linear::generateRandomWeights(vector<int> dim, double min, double max) {
    //randomly generate data
    vector<double> data;
    for(int i = 0; i < (dim[0]*dim[1]); i++) {
        data.push_back(((double)rand() / RAND_MAX)*(max-min)+min);
        //cout << data[i] << endl;
    }

    Tensor t(dim, data);
    return t;
}

void Linear::randomizeWeights(double min, double max) {
    weights = generateRandomWeights({n_inputs, n_outputs}, min, max);
    bias = generateRandomWeights({n_outputs, 1}, min, max);
}
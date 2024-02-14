#include "../include/Neuron.hpp"


//--------------------Constructors and Destructors--------------------//
Neuron::Neuron(){
    n_inputs = 0;
    n_outputs = 0;
    weights = Tensor();
    bias = Tensor();
    output = Tensor();
}

Neuron::Neuron(int n_inputs_, int n_outputs_){
    n_inputs = n_inputs_;
    n_outputs = n_outputs_;
    weights = Tensor({n_inputs, n_outputs});
    bias = Tensor({1,n_outputs});
    output = Tensor({1,n_outputs});
}

Neuron::Neuron(int n_inputs_, int n_outputs_, Tensor weights_, Tensor bias_){
    n_inputs = n_inputs_;
    n_outputs = n_outputs_;
    weights = weights_;
    bias = bias_;
    output = Tensor({1,n_outputs});
}


//--------------------Getters and Setters--------------------//
void Neuron::setWeights(Tensor weights_){
    weights = weights_;
}

void Neuron::setBias(Tensor bias_){
    bias = bias_;
}

void Neuron::setOutput(Tensor output_){
    output = output_;
}

Tensor Neuron::getWeights(){
    return weights;
}

Tensor Neuron::getBias(){
    return bias;
}

Tensor Neuron::getOutput(){
    return output;
}

//--------------------Forward and Backward--------------------//
void Neuron::forward(Tensor inputs){
    output = inputs * weights;
    output = output + bias;
}

Tensor Neuron::backward(Tensor label){
    cout << "Label: " << label << endl;
    cout << "Output: " << output << endl;
    Tensor error = label - output;
    cout << "Error: " << error << endl;
    return error;
}

void Neuron::updateWeights(Tensor inputs, Tensor error, double learning_rate){
    Tensor update_val = error * inputs * learning_rate;
    //cout << "Update Val: " << update_val << endl;
    Tensor update_bias = error * learning_rate;
    update_val.T();
   // cout << "Update Val: " << update_val << endl;
    weights = weights + update_val;
    //bias = bias + update_bias;
}




#include "../include/Neuron.hpp"

#include <cmath>
#include <iostream>
#include <fstream>
#include <stdlib.h>

//cmd line to compile and run this file: g++ -std=c++14 -o TestNeuron.out TestNeuron.cpp ../src/Neuron.cpp ../src/Tensor.cpp


void writeToCSV(const vector<double>& vector, const string& fileName) {
    // Open the CSV file for writing
    ofstream outputFile(fileName);

    // Check if the file is opened successfully
    if (outputFile.is_open()) {
        // Iterate through the vector and write each value to the file
        outputFile << "Epoch, MSE" << endl;
        for (int i = 0; i < vector.size(); i++) {
            outputFile << i << ", "<< vector[i] << endl;
        }
        // Move the cursor back to overwrite the last comma with a newline character
        outputFile.seekp(-1, ios_base::end);
        outputFile << endl;

        // Close the file
        outputFile.close();

        cout << "Vector successfully written to " << fileName << endl;
    } else {
        cerr << "Unable to open the file: " << fileName << endl;
    }
}

#ifndef fmeakzjbfmezaufb

vector<double> x1_data = {0.3, 0.5};
vector<double> x2_data = {1.0,2.0};
vector<double> x3_data = {0.7, 0.1};
vector<double> x4_data = {2.0, 1.0};
vector<double> y1_data = {1.0};
vector<double> y2_data = {1.0};
vector<double> y3_data = {-1.0};
vector<double> y4_data = {-1.0};


int main(){

    Tensor x1({1,2}, x1_data);
    Tensor x2({1,2}, x2_data);
    Tensor x3({1,2}, x3_data);
    Tensor x4({1,2}, x4_data);
    Tensor y1({1,1}, y1_data);
    Tensor y2({1,1}, y2_data);
    Tensor y3({1,1}, y3_data);
    Tensor y4({1,1}, y4_data);

    vector<Tensor> inputs = {x1, x2, x3, x4};
    vector<Tensor> labels = {y1, y2, y3, y4};

    Neuron n1(2);

    Tensor bias({1,1}, {0.5});

    //n1.setBias(bias);

    vector<double> errors;


    double learning_rate = 0.01;

    for(int i = 0; i <= 200; i++){

        double total_error = 0.0;

        for (int j = 0; j < inputs.size(); j++){
            
            //cout << "flag1" << endl;
            n1.forward(inputs[j]);
            //cout << "flag2" << endl;
            Tensor error = n1.backward(labels[j]);
            //cout << "flag3" << endl;
            n1.updateWeights(inputs[j], error, learning_rate);
            //cout << "flag4" << endl;
            total_error += pow(error.getData()[0],2);
        }

        errors.push_back(total_error/inputs.size());

        cout << i << " error : " << total_error/inputs.size() << endl;
    }

    cout << n1.getWeights() << endl;
    cout << n1.getBias() << endl;

    cout << "---------------" << endl;

    n1.forward(x1);
    cout << n1.getOutput() << endl;
    n1.forward(x2);
    cout << n1.getOutput() << endl;
    n1.forward(x3);
    cout << n1.getOutput() << endl;
    n1.forward(x4);
    cout << n1.getOutput() << endl;

    writeToCSV(errors, "output/NeuronErrors.csv");

    Tensor x5({1,3}, {-1.0, -1.0, 1.0});
    Tensor x6({1,3}, {0.5, 0.5, 0.3});
    Tensor x7({1,3}, {-0.45, 1.2, -0.4});
    Tensor x8({1,3}, {-1.0, -2.0, 0.5});

    inputs = {x5, x6, x7, x8};

    Neuron n2(3);

    //cout << x5 << endl;
    //cout << n2.getWeights() << endl;

    for(int i = 0; i <= 200; i++){

        double total_error = 0.0;

        for (int j = 0; j < inputs.size(); j++){
            
            //cout << "flag1" << endl;
            //cout << inputs[j] << endl;
            n2.forward(inputs[j]);
            //cout << "flag2" << endl;
            Tensor error = n2.backward(labels[j]);
            //cout << "flag3" << endl;
            n2.updateWeights(inputs[j], error, learning_rate);
            //cout << "flag4" << endl;
            total_error += pow(error.getData()[0],2);
        }

        errors.push_back(total_error/inputs.size());

        cout << i << " error : " << total_error/inputs.size() << endl;
    }

    cout << n2.getWeights() << endl;
    cout << n2.getBias() << endl;

    cout << "---------------" << endl;

    n2.forward(x5);
    cout << n2.getOutput() << endl;
    n2.forward(x6);
    cout << n2.getOutput() << endl;
    n2.forward(x7);
    cout << n2.getOutput() << endl;
    n2.forward(x8);
    cout << n2.getOutput() << endl;
    

    return 0;
}

#endif
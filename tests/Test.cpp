#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include <iostream>
#include <cmath>

#include "../include/Tensor.hpp"
#include "../include/Neuron.hpp"
#include "../include/Activation.hpp"

using namespace std;

//g++ -std=c++14 -o TestTensor.out TestTensor.cpp catch_amalgamated.cpp ../src/Tensor.cpp

TEST_CASE("TestTensor Constructors", "[Tensor]") {
    SECTION("Default Constructor") {
        Tensor t1;
        REQUIRE(t1.getDim().size() == 1);
        REQUIRE(t1.getDim()[0] == 1);
        REQUIRE(t1.getData().size() == 1);
        REQUIRE(t1.getData()[0] == 0.0);
        REQUIRE(t1.getSize() == 1);
    }

    SECTION("Constructor with specified dimensions") {
        vector<int> dim = {2, 3, 4};
        Tensor t2(dim);
        REQUIRE(t2.getDim().size() == 3);
        REQUIRE(t2.getDim()[0] == 2);
        REQUIRE(t2.getDim()[1] == 3);
        REQUIRE(t2.getDim()[2] == 4);
        REQUIRE(t2.getData().size() == 24);
        REQUIRE(t2.getSize() == 24);
    }

    SECTION("Constructor with specified dimensions and data") {
        vector<int> dim = {2, 3, 4};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t3(dim, data);
        REQUIRE(t3.getDim().size() == 3);
        REQUIRE(t3.getDim()[0] == 2);
        REQUIRE(t3.getDim()[1] == 3);
        REQUIRE(t3.getDim()[2] == 4);
        REQUIRE(t3.getData().size() == 24);
        REQUIRE(t3.getData()[0] == 1.0);
        REQUIRE(t3.getData()[1] == 2.0);
        REQUIRE(t3.getData()[2] == 3.0);
        REQUIRE(t3.getData()[3] == 4.0);
        REQUIRE(t3.getSize() == 24);
    }

    SECTION("Constructor with mismatched dimensions and data") {
        vector<int> dim = {1, 3};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t4(dim, data);
        REQUIRE(t4.getDim().size() == 2);
        REQUIRE(t4.getDim()[0] == 1);
        REQUIRE(t4.getDim()[1] == 3);
        REQUIRE(t4.getData().size() == 3);
        REQUIRE(t4.getData()[0] == 1.0);
        REQUIRE(t4.getData()[1] == 2.0);
        REQUIRE(t4.getData()[2] == 3.0);
        REQUIRE(t4.getSize() == 3);
    } 
}

TEST_CASE("TestTensor Operators", "[Tensor]") {
    
    SECTION("+ operator"){
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        Tensor t2(dim, data);
        Tensor t3 = t1 + t2;
        data = t3.getData();
        REQUIRE(data[0] == 2.0);
        REQUIRE(data[1] == 4.0);
        REQUIRE(data[2] == 6.0);
        REQUIRE(data[3] == 8.0);
        REQUIRE(data.size() == 4);
    }

    // test the - operator
    SECTION("- operator"){
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        Tensor t2(dim, data);
        Tensor t4 = t1 - t2;
        data = t4.getData();
        REQUIRE(data[0] == 0.0);
        REQUIRE(data[1] == 0.0);
        REQUIRE(data[2] == 0.0);
        REQUIRE(data[3] == 0.0);
        REQUIRE(data.size() == 4);
    }
    // test the + operator with mismatched dimensions
    SECTION("+ operator with mismatched dimensions"){ 
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        vector<int> dim2 = {2, 1};
        Tensor t5(dim2, data);
        Tensor t6;
        CHECK_THROWS(t6 = t1 + t5);
        
    }

    // test the - operator with mismatched dimensions
    SECTION("- operator with mismatched dimensions"){

        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        vector<int> dim2 = {2, 1};
        Tensor t5(dim2, data);
        Tensor t6;
        CHECK_THROWS(t6 = t1 - t5);
    }

}

TEST_CASE("TestTensor Assesors", "[Tensor]") {

    vector<int> dim = {2, 3};
    vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    Tensor t1(dim, data);
    REQUIRE(t1[0][0] == 1.0);
    REQUIRE(t1[0][1] == 2.0);
    REQUIRE(t1[1][0] == 4.0);
    REQUIRE(t1({1,0}) == 4.0);
    REQUIRE(t1[1][2] == 6.0);
    REQUIRE(t1[2][0] == 1.0);
    REQUIRE(t1[-2][0] == 1.0);

    t1.set({0,0},2.0);
    REQUIRE(t1[0][0] == 2.0);

}

TEST_CASE("TestTensor Mult", "[Tensor]") {

    SECTION("Mult with a double"){
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        double d = 2.0;
        Tensor t3 = t1 * d;
        data = t3.getData();
        REQUIRE(data[0] == 2.0);
        REQUIRE(data[1] == 4.0);
        REQUIRE(data[2] == 6.0);
        REQUIRE(data[3] == 8.0);
        REQUIRE(data.size() == 4);
    }

    SECTION("Mult with a Tensor"){
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        Tensor t2(dim, data);
        Tensor t3 = t1 * t2;
        data = t3.getData();
        REQUIRE(data[0] == 7.0);
        REQUIRE(data[1] == 10.0);
        REQUIRE(data[2] == 15.0);
        REQUIRE(data[3] == 22.0);
        REQUIRE(data.size() == 4);

        vector<int> dim2 = {2, 1};
        data = {1.0, 2.0};
        Tensor t4(dim2, data);
        Tensor t5 = t1 * t4;
        dim = t5.getDim();
        data = t5.getData();
        REQUIRE(dim[0] == 2);
        REQUIRE(dim[1] == 1);
        REQUIRE(data[0] == 5.0);
        REQUIRE(data[1] == 11.0);
        REQUIRE(data.size() == 2);
    }

    SECTION("Mult with mismatched dimensions"){

        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        vector<int> dim2 = {1, 2};
        data = {1.0, 2.0};
        Tensor t6(dim2, data);
        Tensor t7;
        CHECK_THROWS(t7 = t1 * t6);
    
    }

    SECTION("Element wise mult"){
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        Tensor t2(dim, data);
        Tensor t3 = t1.element_wise_mult(t2);
        data = t3.getData();
        REQUIRE(data[0] == 1.0);
        REQUIRE(data[1] == 4.0);
        REQUIRE(data[2] == 9.0);
        REQUIRE(data[3] == 16.0);
        REQUIRE(data.size() == 4);
    }

    SECTION("Element wise mult with mismatched dimensions"){
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        vector<int> dim2 = {1, 2};
        data = {1.0, 2.0};
        Tensor t6(dim2, data);
        Tensor t7;
        CHECK_THROWS(t7 = t1.element_wise_mult(t6));
    }
}



TEST_CASE("TestNeuron Constructors", "[Neuron]") {
    SECTION("Default Constructor") {
        Neuron n1;
        REQUIRE(n1.getWeights().getDim().size() == 1);
        REQUIRE(n1.getWeights().getDim()[0] == 1);
        REQUIRE(n1.getWeights().getData().size() == 1);
        REQUIRE(n1.getWeights().getData()[0] == 0.0);
        REQUIRE(n1.getBias().getDim().size() == 1);
        REQUIRE(n1.getBias().getDim()[0] == 1);
        REQUIRE(n1.getBias().getData().size() == 1);
        REQUIRE(n1.getBias().getData()[0] == 0.0);
        REQUIRE(n1.getOutput().getDim().size() == 1);
        REQUIRE(n1.getOutput().getDim()[0] == 1);
        REQUIRE(n1.getOutput().getData().size() == 1);
        REQUIRE(n1.getOutput().getData()[0] == 0.0);
    }

    SECTION("Constructor with specified dimensions") {
        Neuron n2(2);
        REQUIRE(n2.getWeights().getDim().size() == 2);
        REQUIRE(n2.getWeights().getDim()[0] == 2);
        REQUIRE(n2.getWeights().getDim()[1] == 1);
        REQUIRE(n2.getWeights().getData().size() == 2);
        REQUIRE(n2.getBias().getDim().size() == 2);
        REQUIRE(n2.getBias().getDim()[0] == 1);
        REQUIRE(n2.getBias().getData().size() == 1);
        REQUIRE(n2.getOutput().getDim().size() == 2);
        REQUIRE(n2.getOutput().getDim()[0] == 1);
        REQUIRE(n2.getOutput().getData().size() == 1);
    }

}

TEST_CASE("TestNeuron Binary classification"){

    vector<double> x1_data = {0.3, 0.5};
    vector<double> x2_data = {1.0,2.0};
    vector<double> x3_data = {0.7, 0.1};
    vector<double> x4_data = {2.0, 1.0};
    vector<double> y1_data = {1.0};
    vector<double> y2_data = {1.0};
    vector<double> y3_data = {-1.0};
    vector<double> y4_data = {-1.0};


    Tensor x1({2,1}, x1_data);
    Tensor x2({2,1}, x2_data);
    Tensor x3({2,1}, x3_data);
    Tensor x4({2,1}, x4_data);
    Tensor y1({1,1}, y1_data);
    Tensor y2({1,1}, y2_data);
    Tensor y3({1,1}, y3_data);
    Tensor y4({1,1}, y4_data);

    Neuron n1(2);

    Tensor bias({1,1}, {0.5});
    //n1.setBias(bias);

    double learning_rate = 0.01;

    for(int i = 0; i < 1000; i++){

        double total_error = 0.0;
        //cout << "flag1" << endl;
        n1.forward(x1);
        //cout << "flag2" << endl;
        Tensor error = n1.backward(y1);
        //cout << "flag3" << endl;
        n1.updateWeights(x1, error, learning_rate);
        //cout << "flag4" << endl;
        total_error += pow(error.getData()[0],2);

        n1.forward(x2);
        error = n1.backward(y2);
        n1.updateWeights(x2, error, learning_rate);
        total_error += pow(error.getData()[0],2);

        n1.forward(x3);
        error = n1.backward(y3);
        n1.updateWeights(x3, error, learning_rate);
        total_error += pow(error.getData()[0],2);

        n1.forward(x4);
        error = n1.backward(y4);
        n1.updateWeights(x4, error, learning_rate);
        total_error += pow(error.getData()[0],2);
    }

    n1.forward(x1);
    //cout << n1.getOutput() << endl;
    CHECK(n1.getOutput().getData()[0] > 0.0);
    n1.forward(x2);
    //cout << n1.getOutput() << endl;
    CHECK(n1.getOutput().getData()[0] > 0.0);
    n1.forward(x3);
    //cout << n1.getOutput() << endl;
    CHECK(n1.getOutput().getData()[0] < 0.0);
    n1.forward(x4);
    //cout << n1.getOutput() << endl;
    CHECK(n1.getOutput().getData()[0] < 0.0);

}

TEST_CASE("TestActivation Functions", "[Activation]") {
    SECTION("Sigmoid") {
        double x = -0.5;
        double y = Activation::sigmoid(x);
        y = round(y * 1000.0) / 1000.0;
        REQUIRE(y == 0.378);

        x = 0.5;
        y = Activation::sigmoid(x);
        y = round(y * 1000.0) / 1000.0;
        REQUIRE(y == 0.622);
    }

    SECTION("Linear") {
        double x = 0.0;
        double y = Activation::linear(x);
        REQUIRE(y == 0.0);

        x = 1.0;
        y = Activation::linear(x);
        REQUIRE(y == 1.0);

        x = -1.0;
        y = Activation::linear(x);
        REQUIRE(y == -1.0);
    }

    SECTION("Relu") {
        double x = -1.0;
        double y = Activation::relu(x);
        REQUIRE(y == 0.0);

        x = 0.0;
        y = Activation::relu(x);
        REQUIRE(y == 0.0);

        x = 1.0;
        y = Activation::relu(x);
        REQUIRE(y == 1.0);
    }

    SECTION("LeakyRelu") {
        double x = 0.0;
        double y = Activation::leakyRelu(x);
        REQUIRE(y == 0.0);
    }
    
}
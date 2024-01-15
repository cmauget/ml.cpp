#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include <iostream>

#include "../include/Tensor.hpp"

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

    // Add more sections for other constructors and edge cases...
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
        Tensor t6 = t1 + t5;
        dim = t6.getDim();
        data = t6.getData();
        REQUIRE(dim[0] == 2);
        REQUIRE(dim[1] == 2);
        REQUIRE(data[0] == 1.0);
        REQUIRE(data[1] == 2.0);
        REQUIRE(data[2] == 3.0);
        REQUIRE(data[3] == 4.0);
        REQUIRE(data.size() == 4);
    }

    // test the - operator with mismatched dimensions
    SECTION("- operator with mismatched dimensions"){

        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        vector<int> dim2 = {2, 1};
        Tensor t5(dim2, data);
        Tensor t6 = t1 - t5;
        dim = t6.getDim();
        data = t6.getData();
        REQUIRE(dim[0] == 2);
        REQUIRE(dim[1] == 2);
        REQUIRE(data[0] == 1.0);
        REQUIRE(data[1] == 2.0);
        REQUIRE(data[2] == 3.0);
        REQUIRE(data[3] == 4.0);
        REQUIRE(data.size() == 4);
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

    dim2 = {1, 2};
    data = {1.0, 2.0, 3.0, 4.0};
    Tensor t6(dim2, data);
    Tensor t7 = t1 * t6;
    dim = t7.getDim();
    data = t7.getData();
    REQUIRE(dim[0] == 2);
    REQUIRE(dim[1] == 2);
    REQUIRE(data[0] == 1.0);
    REQUIRE(data[1] == 2.0);
    REQUIRE(data[2] == 3.0);
    REQUIRE(data[3] == 4.0);
    REQUIRE(data.size() == 4);
}

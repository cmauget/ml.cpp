#ifndef TENSOR_HPP
#define TENSOR_HPP

// necessary libraries
#include <vector>

#include <iostream>

// necessary namespaces
using namespace std;


class Tensor {

    public:
        /* data */
        vector<int> dim; //stores the dimensions of the tensor
        int size; //stores the total size of the tensor (may not be necessary)
        vector<double> data; //stores all the data of the tensor in a 1D array

    public:
        //constructors and Destructors
        Tensor();
        Tensor(vector<int> dim);
        Tensor(vector<int> dim, vector<double> data);
        ~Tensor();

        //getters
        vector<int> getDim();
        int getSize();
        vector<double> getData();

        //setters
        void setDim(vector<int> dim);
        void setData(vector<double> data);
        void set(vector<int> indx, double data);

        //custom accessors
        vector<double> operator[](int i);
        double operator()(vector<int> indx);

        //basics operators
        Tensor operator+(Tensor t);
        Tensor operator-(Tensor t);
        Tensor operator*(Tensor t);

        Tensor operator+(double d);
        Tensor operator-(double d);
        Tensor operator*(double d);
        Tensor operator/(double d);

        static void matmult(Tensor& a, Tensor& b, Tensor& c);

        //squezze and unsquezze
        void unsquezze();
        void squezze();

        Tensor T();

        friend ostream& operator<<(ostream& os, const Tensor& obj);

        

};


#endif // TENSOR_HPP
#include<../include/Tensor.hpp> //Contains using namespace std; and #include <vector>

#include <iostream>


//--------------------Constructors and Destructors--------------------//

Tensor::Tensor() {
    // By default, we create a 1D tensor of size 1
    size = 1;
    dim.push_back(1);
    data.push_back(0.0);
}

Tensor::Tensor(vector<int> dim_) {
    // Create a tensor of the specified dimensions
    // Initialize all values to 0.0
    dim = dim_;

    int size_ = 1;
    for (int i = 0; i < dim.size(); i++) {
        size_ *= dim[i];
    }
    size = size_;

    for (int i = 0; i < size; i++) {
        data.push_back(0.0);
    }
}

Tensor::Tensor(vector<int> dim_, vector<double> data_) {
    // Create a tensor of the specified dimensions
    // Initialize all values to 0.0
    dim = dim_;

    int size_ = 1;
    for (int i = 0; i < dim.size(); i++) {
        size_ *= dim[i];
    }
    size = size_;

    //Check if the size of the data vector is equal to the size of the tensor, otherwise remove excess elements/add zeros
    if (data_.size() > size) {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "Error: Size of data vector does not match the size of the tensor" << endl;
        cout << "Size of data vector: " << data_.size() << endl;
        cout << "Size of tensor: " << size << endl;
        cout << "Removing excess elements from data vector" << endl;
        cout << "-----------------------" << endl;
        for (int i = size; i <= data_.size(); i++) {
            data_.pop_back();
        }
    }
    else if (data_.size() < size) {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "Error: Size of data vector does not match the size of the tensor" << endl;
        cout << "Size of data vector: " << data_.size() << endl;
        cout << "Size of tensor: " << size << endl;
        cout << "Adding zeros to data vector" << endl;
        cout << "-----------------------" << endl;
        for (int i = data_.size(); i < size; i++) {
            data_.push_back(0.0);
        }
    }
    else {
        // Do nothing
    }

    data = data_;
}


Tensor::~Tensor() {
    // Destructor
    // Empty destructor
    // No resources or memory to release (yet)
}

//--------------------Getters and Setters--------------------//

vector<int> Tensor::getDim() {
    // Return the dimensions of the tensor
    return dim;
}

int Tensor::getSize() {
    // Return the size of the tensor
    return size;
}

vector<double> Tensor::getData() {
    // Return the data of the tensor
    return data;
}

void Tensor::setDim(vector<int> dim_) {
    // Set the dimensions of the tensor
    dim = dim_;
}

void Tensor::setData(vector<double> data_) {
    // Set the data of the tensor
    // Check if the size of the data vector is equal to the size of the tensor, otherwise remove excess elements/add zeros
    if (data_.size() > size) {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "Error: Size of data vector does not match the size of the tensor" << endl;
        cout << "Size of data vector: " << data_.size() << endl;
        cout << "Size of tensor: " << size << endl;
        cout << "Removing excess elements from data vector" << endl;
        cout << "-----------------------" << endl;
        for (int i = size; i <= data_.size(); i++) {
            data_.pop_back();
        }
    }
    else if (data_.size() < size) {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "Error: Size of data vector does not match the size of the tensor" << endl;
        cout << "Size of data vector: " << data_.size() << endl;
        cout << "Size of tensor: " << size << endl;
        cout << "Adding zeros to data vector" << endl;
        cout << "-----------------------" << endl;
        for (int i = data_.size(); i < size; i++) {
            data_.push_back(0.0);
        }
    }
    else {
        // Do nothing
    }

    data = data_;
}


//--------------------Custom assesors--------------------//

vector<double> Tensor::operator[](int i) {
    if (i < 0 || i >= dim[0]) {
        cout << "-----------------------" << endl;
        cout << "Row index out of range" << endl;
        cout << "Row index: " << i << endl;
        cout << "Number of rows: " << dim[0] << endl;
        cout << "Returning first row" << endl;
        cout << "-----------------------" << endl;
        i = 0;
    }

    vector<double> row(dim[1]);
    for (int j = 0; j < dim[1]; j++) {
        row[j] = data[i * dim[1] + j];
    }
    return row;
    }


//--------------------Operators--------------------//

Tensor Tensor::operator+(Tensor t) {
    // Add two tensors together
    // Check if the dimensions of the two tensors are the same
    if (dim == t.dim) {
        // Create a new tensor to store the result
        Tensor result(dim);

        // Add the two tensors together
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + t.data[i];
        }

        return result;
    }
    else {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "Error: Dimensions of the two tensors do not match" << endl;
        cout << "Dimensions of first tensor: ";
        for (int i = 0; i < dim.size(); i++) {
            cout << dim[i] << " ";
        }
        cout << endl;
        cout << "Dimensions of second tensor: ";
        for (int i = 0; i < t.dim.size(); i++) {
            cout << t.dim[i] << " ";
        }
        cout << endl;
        cout << "Returning first tensor" << endl;
        cout << "-----------------------" << endl;
        return *this;
    }
}

Tensor Tensor::operator-(Tensor t) {
    // Subtract two tensors
    // Check if the dimensions of the two tensors are the same
    if (dim == t.dim) {
        // Create a new tensor to store the result
        Tensor result(dim);

        // Subtract the two tensors
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] - t.data[i];
        }

        return result;
    }
    else {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "Error: Dimensions of the two tensors do not match" << endl;
        cout << "Dimensions of first tensor: ";
        for (int i = 0; i < dim.size(); i++) {
            cout << dim[i] << " ";
        }
        cout << endl;
        cout << "Dimensions of second tensor: ";
        for (int i = 0; i < t.dim.size(); i++) {
            cout << t.dim[i] << " ";
        }
        cout << endl;
        cout << "Returning first tensor" << endl;
        cout << "-----------------------" << endl;
        return *this;
    }
}

Tensor Tensor::operator*(Tensor t){
    //multiply two tensors

    //check if the dimensions if the two tensors are compatible
    if (dim[dim.size()-1] == t.dim[0]) {
        //create a new tensor to store the result
        vector<int> dim_ = dim;
        dim_.pop_back();
        dim_.push_back(t.dim[t.dim.size()-1]);
        Tensor result(dim_);

        //multiply the two tensors
        for (int i = 0; i < dim[0]; i++) {
            for (int j = 0; j < t.dim[1]; j++) {
                for (int k = 0; k < dim[1]; k++) {
                    result.data[i*dim[1]+j] += data[i*dim[1]+k]*t.data[k*t.dim[1]+j];
                }
            }
        }

        return result;
    }
    else {
        //throw an error
        cout << "-----------------------" << endl;
        cout << "Error: Dimensions of the two tensors do not match" << endl;
        cout << "Dimensions of first tensor: ";
        for (int i = 0; i < dim.size(); i++) {
            cout << dim[i] << " ";
        }
        cout << endl;
        cout << "Dimensions of second tensor: ";
        for (int i = 0; i < t.dim.size(); i++) {
            cout << t.dim[i] << " ";
        }
        cout << endl;
        cout << "Returning first tensor" << endl;
        cout << "-----------------------" << endl;
        return *this;
    }
}





#include "../include/Tensor.hpp" //Contains using namespace std; and #include <vector>

#include <stdexcept> //Contains throw invalid_argument

#define GET_VARIABLE_NAME(Variable) (#Variable)


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
        cout << "\033[31mError:\033[0m Size of data vector does not match the size of the tensor" << endl;
        cout << "Size of data vector: " << data_.size() << endl;
        cout << "Size of tensor: " << size << endl;
        cout << "Removing excess elements from data vector" << endl;
        cout << "-----------------------" << endl;
        int ubound = data_.size();
        for (int i = size; i < ubound; i++) {
            data_.pop_back();
            //cout << size << endl;
            //cout << "Popping " << i << endl;
            //cout << data_.size() << endl;
        }
    }
    else if (data_.size() < size) {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "\033[31mError:\033[0m Size of data vector does not match the size of the tensor" << endl;
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
        cout << "\033[31mError:\033[0m Size of data vector does not match the size of the tensor" << endl;
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
        cout << "\033[31mError:\033[0m Size of data vector does not match the size of the tensor" << endl;
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

void Tensor::set(vector<int> indx, double data_) {
    // Set the value of the tensor at the specified index

    // Check if the index size is valid
    if (indx.size() != dim.size()) {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "\033[31mError:\033[0m Index does not match the dimensions of the tensor" << endl;
        cout << "Index: " << indx.size() << endl;
        cout << "Dimensions of tensor: " << dim.size() << endl;
        cout << "Assigning nothing" << endl;
        cout << "-----------------------" << endl;
        return;
    }

    // Check if the index is not out of bound
    for (int i = 0; i < indx.size(); i++) {
        if (indx[i] < 0 || indx[i] >= dim[i]) {
            // Throw an error
            cout << "-----------------------" << endl;
            cout << "\033[31mError:\033[0m Index " << i << " out of range" << endl;
            cout << "Index: " << indx[i] << endl;
            cout << "Dimension of tensor: " << dim[i] << endl;
            cout << "Assigning nothing" << endl;
            cout << "-----------------------" << endl;
            return;
        }
    }

    // Calculate the index of the element in the array
    int index = 0;
    for (int i = 0; i < indx.size(); i++) {
        int temp = 1;
        for (int j = i + 1; j < indx.size(); j++) {
            temp *= dim[j];
        }
        index += indx[i] * temp;
    }

    data[index] = data_;
}


//--------------------Custom assesors--------------------//

vector<double> Tensor::operator[](int i) {
    if (i < 0 || i >= dim[0]) {
        cout << "-----------------------" << endl;
        cout << "\033[31mError:\033[0m Row index out of range" << endl;
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

double Tensor::operator()(vector<int> indx) {
    // Return the value of the tensor at the specified index

    // Check if the index size is valid
    if (indx.size() != dim.size()) {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "\033[31mError:\033[0m Index does not match the dimensions of the tensor" << endl;
        cout << "Index: " << indx.size() << endl;
        cout << "Dimensions of tensor: " << dim.size() << endl;
        cout << "Returning first element" << endl;
        cout << "-----------------------" << endl;
        return data[0];
    }

    // Check if the index is not out of bound
    for (int i = 0; i < indx.size(); i++) {
        if (indx[i] < 0 || indx[i] >= dim[i]) {
            // Throw an error
            cout << "-----------------------" << endl;
            cout << "\033[31mError:\033[0m Index " << i << " out of range" << endl;
            cout << "Index: " << indx[i] << endl;
            cout << "Dimension of tensor: " << dim[i] << endl;
            cout << "Returning first element" << endl;
            cout << "-----------------------" << endl;
            return data[0];
        }
    }

    // Calculate the index of the element in the array
    int index = 0;
    for (int i = 0; i < indx.size(); i++) {
        int temp = 1;
        for (int j = i + 1; j < indx.size(); j++) {
            temp *= dim[j];
        }
        index += indx[i] * temp;
    }

    return data[index];
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
        cout << "\033[31mError:\033[0m Dimensions of the two tensors do not match" << endl;
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
        cout << "-----------------------" << endl;
        throw invalid_argument("Dimensions of the two tensors do not match (addition)");
        cout << "Returning first tensor" << endl;
        
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
        cout << "\033[31mError:\033[0m Dimensions of the two tensors do not match" << endl;
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
        cout << "-----------------------" << endl;

        throw invalid_argument("Dimensions of the two tensors do not match (substraction)");

        cout << "Returning first tensor" << endl;
        
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


        //const int blockSize = 13;

        // Blocked matrix multiplication
        /*for (int i = 0; i < dim[0]; i += blockSize) {
            for (int j = 0; j < t.dim[1]; j += blockSize) {
                for (int k = 0; k < dim[1]; k += blockSize) {
                    for (int ii = i; ii < min(i + blockSize, dim[0]); ++ii) {
                        for (int jj = j; jj < min(j + blockSize, t.dim[1]); ++jj) {
                            for (int kk = k; kk < min(k + blockSize, dim[1]); ++kk) {
                                result.data[ii * dim_[1] + jj] += data[ii * dim[1] + kk] * t.data[kk * t.dim[1] + jj];
                            }
                        }
                    }
                }
            }
        }*/

        for (int i = 0; i < dim[0]; i++) {
            for (int k = 0; k < dim[1]; k++) {
                for (int j = 0; j < t.dim[1]; j++) {
                    result.data[i*dim_[1]+j] += data[i*dim[1]+k] * t.data[k*t.dim[1]+j];
                    //cout << i*dim_[1]+j << " : " << result.data[i*dim_[1]+j] << endl;
                }
            }
        }

        return result;
    }
    else {
        //throw an error
        cout << "-----------------------" << endl;
        cout << "\033[31mError:\033[0m Dimensions of the two tensors do not match" << endl;
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
        cout << "-----------------------" << endl;
        throw invalid_argument("Dimensions of the two tensors do not match (multiplication)");
        cout << endl;
        cout << "Returning first tensor" << endl;
        cout << "-----------------------" << endl;
        return *this;
    }
}

Tensor Tensor::operator*(double d) {
    // Multiply a tensor by a scalar
    // Create a new tensor to store the result
    Tensor result(dim);

    // Multiply the tensor by the scalar
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * d;
    }

    return result;
}

Tensor Tensor::element_wise_mult(Tensor t) {
    // Multiply two tensors element-wise
    // Check if the dimensions of the two tensors are the same
    if (dim == t.dim) {
        // Create a new tensor to store the result
        Tensor result(dim);

        // Multiply the two tensors element-wise
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] * t.data[i];
        }

        return result;
    }
    else {
        // Throw an error
        cout << "-----------------------" << endl;
        cout << "\033[31mError:\033[0m Dimensions of the two tensors do not match" << endl;
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
        cout << "-----------------------" << endl;
        throw invalid_argument("Dimensions of the two tensors do not match (element-wise multiplication)");
        cout << "Returning first tensor" << endl;
        cout << "-----------------------" << endl;
        return *this;
    }
}

ostream& operator<<(ostream& os, const Tensor& obj) {
    // Overload the << operator to print the tensor
    // Print the dimensions of the tensor
    os << "Dimensions: ";
    for (int i = 0; i < obj.dim.size(); i++) {
        os << obj.dim[i] << " ";
    }
    os << endl;

    // Print the data of the tensor
    os << "Data: ";
    for (int i = 0; i < obj.size; i++) {
        os << obj.data[i] << " ";
    }
    os << endl;

    return os;
}

void Tensor::matmult(Tensor& a, Tensor& b, Tensor& c) {

    for (int i = 0; i < a.dim[0]; i++) {
        for (int j = 0; j < b.dim[1]; j++) {
            for (int k = 0; k < b.dim[0]; k++) {
            
                c.data[i*c.dim[1]+j] += a.data[i*a.dim[1]+k] * b.data[k*b.dim[1]+j];
                //cout << i*dim_[1]+j << " : " << result.data[i*dim_[1]+j] << endl;
            }
            }
        }

}

void Tensor::unsquezze() {
    // Unsqueeze the tensor
    // Add a new dimension to the tensor
    this->dim.push_back(1);
}

void Tensor::squezze() {
    // Squezze the tensor
    // Remove the last dimension of the tensor if it is equal to 1
    if(dim[dim.size() - 1] != 1){
        cout << "-----------------------" << endl;
        cout << "\033[31mError:\033[0m Last dimension of the tensor is not equal to 1" << endl;
        cout << "Last dimension: " << dim[dim.size() - 1] << endl;
        cout << "Returning tensor" << endl;
        cout << "-----------------------" << endl;
        return;
    }
    dim.pop_back();
    size /= dim[dim.size() - 1];
}

Tensor Tensor::T() {
    // Transpose the tensor
    vector<int> dim_ = dim;
    reverse(dim_.begin(), dim_.end());
    Tensor result(dim_, data);
    
    return result;
}
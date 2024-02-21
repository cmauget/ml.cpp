#include "../include/Loss.hpp"

#include <cmath>

double Loss::mean_squared_error(Tensor y_pred, Tensor y_true) {
    vector<double> pred = y_pred.getData();
    vector<double> true_ = y_true.getData();
    double loss = 0;
    for (int i = 0; i < pred.size(); i++) {
        loss += pow(pred[i] - true_[i], 2);
    }
    return loss / pred.size();
}

Tensor Loss::mean_squared_error_prime(Tensor y_pred, Tensor y_true) {
    return (y_pred - y_true)*(2.0/y_pred.getSize());
}

double Loss::cross_entropy(Tensor y_pred, Tensor y_true) {
   return -1.0;
}

Tensor Loss::cross_entropy_prime(Tensor y_pred, Tensor y_true) {
    return Tensor({1,1},{-1.0});
}
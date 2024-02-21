#ifndef LOSS_HPP
#define LOSS_HPP

#include "Tensor.hpp"

class Loss {

    public:

        static double mean_squared_error(Tensor y_pred, Tensor y_true);

        static Tensor mean_squared_error_prime(Tensor y_pred, Tensor y_true);

        static double cross_entropy(Tensor y_pred, Tensor y_true);

        static Tensor cross_entropy_prime(Tensor y_pred, Tensor y_true);

};

#endif // LOSS_HPP
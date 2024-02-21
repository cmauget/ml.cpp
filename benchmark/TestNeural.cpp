#include "../include/NeuralNetwork.hpp"
#include "../include/ActivationLayer.hpp"
#include "../include/Linear.hpp"
#include "../include/Activation.hpp"
#include "../include/Layer.hpp"

//compilation cmd: make neural
//run cmd: ./TestNeural.out

int main() {

    ActivationLayer layer = ActivationLayer("linear");
    Linear layer2 = Linear(10, 5);  

    Tensor input = Tensor({1,1}, {1.0});
    Tensor output = layer.forward(input);

    cout << "Output: " << output << endl;

    Tensor input2 = Tensor({10,1}, {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0});

    cout << "Input: " << input2 << endl;

    output = layer2.forward(input2);

    cout << "Output: " << output << endl;

    NeuralNetwork net = NeuralNetwork();

    net.addLayer(&layer);
    net.addLayer(&layer2);


    return 0;
}

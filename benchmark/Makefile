tensor:
	g++ -std=c++14 -O3 -o BenchmarkTensors.out BenchmarkTensors.cpp ../src/Tensor.cpp

neuron:
	g++ -std=c++14 -O3 -o TestNeuron.out TestNeuron.cpp ../src/Neuron.cpp ../src/Tensor.cpp

neural:
	g++ -std=c++14 -O3 -o TestNeural.out TestNeural.cpp ../src/NeuralNetwork.cpp ../src/Neuron.cpp ../src/Tensor.cpp ../src/Activation.cpp ../src/ActivationLayer.cpp ../src/Linear.cpp ../src/Loss.cpp 

clean:
	rm -f TestNeuron.out BenchmarkTensors.out TestNeural.out
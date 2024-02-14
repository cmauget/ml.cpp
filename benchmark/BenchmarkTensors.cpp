//Compute the time to perform a tensor operation using the Tensor class.
#include <iostream>
#include <chrono>
#include <fstream>
#include <stdlib.h>

#include "../include/Tensor.hpp"

using namespace std;

int SAMPLE_SIZE = 10;
int MAX_SIZE = 2000;



Tensor generate_Tensor(vector<int> dim) {
    //randomly generate data
    vector<double> data;
    for(int i = 0; i < (dim[0]*dim[1]); i++) {
        data.push_back(((double)rand() / RAND_MAX)*10);
        //cout << data[i] << endl;
    }

    Tensor t(dim, data);
    return t;
}

void writeToCSV(const vector<float>& vector, const string& fileName) {
    // Open the CSV file for writing
    ofstream outputFile(fileName);

    // Check if the file is opened successfully
    if (outputFile.is_open()) {
        // Iterate through the vector and write each value to the file
        outputFile << "Size, Time" << endl;
        for (int i = 0; i < vector.size(); i++) {
            outputFile << (i*5)+5 << ", "<< vector[i] << endl;
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

#include <stdlib.h>


int main() {

    vector<float> results;

    for(int i = 50; i < MAX_SIZE; i+=50){

        cout << "Benchmarking Tensor Multiplication for " << i << "x" << i << " Tensors" << endl;

        Tensor t1 = generate_Tensor({i, i});
        Tensor t2 = generate_Tensor({i, i});

        Tensor t3 = Tensor({i, i});

        auto start = chrono::high_resolution_clock::now();

        for(int k = 0; k < SAMPLE_SIZE; k++){
            t3 = t1 * t2;
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Time taken to execute benchmark: " << duration.count() << " milliseconds" << endl;
        cout << "Time taken to execute benchmark per sample: " << duration.count() / SAMPLE_SIZE << " milliseconds" << endl;
        results.push_back(duration.count() / (SAMPLE_SIZE));
    }

    const string csvFileName = "output.csv";
    writeToCSV(results, csvFileName);
}


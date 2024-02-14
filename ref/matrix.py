# This code help to compare the time difference between numpy implementation and the implementation of matrix n mlcpp
import numpy as np #type: ignore
import time
import csv

SAMPLE_SIZE = 1
MAX_SIZE = 2000

def write_to_csv(float_vector, file_name):

    with open(file_name, 'w') as output_file:
        output_file.write("Size, Time\n")
        for i, value in enumerate(float_vector):
            output_file.write(f"{(i * 5) + 5}, {value}\n")

    print(f"Vector successfully written to {file_name}")
def generate_matrix(dim1, dim2):
    #generate a random matrix
    return np.random.rand(dim1, dim2)

def matrix_multiply(matrix1, matrix2):
    result = [[0 for _ in range(len(matrix2[0]))] for _ in range(len(matrix1))]

    # Iterate through rows of matrix1
    for i in range(len(matrix1)):
        # Iterate through columns of matrix2
        for j in range(len(matrix2[0])):
            # Iterate through rows of matrix2
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

if __name__ == "__main__":

    results = []

    for i in range(50, MAX_SIZE, 50):

        print("Benchmarking for matrix size: ", i, "x", i)

        a = generate_matrix(i, i)
        b = generate_matrix(i, i)
        start = time.time_ns()
        for _ in range(SAMPLE_SIZE):
            c = np.matmul(a,b)
        end = time.time_ns()

        print("Time taken to execute benchmark: ", (end - start)// 1_000_000, "millisenconds")
        print("Time taken to execute benchmark per sample: ", ((end - start)/SAMPLE_SIZE)// 1_000_000, "millisenconds ")

        results.append(((end - start)/(SAMPLE_SIZE))// 1_000_000)

    csv_file_name = "output.csv"
    write_to_csv(results, csv_file_name)



    


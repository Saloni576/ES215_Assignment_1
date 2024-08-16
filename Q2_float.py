import numpy as np
import time

def multiply_matrices(A, B):
    N = A.shape[0]
    C = np.zeros((N, N), dtype=float)
    for i in range(N):
        for j in range(N):
            C[i, j] = 0
            for k in range(N):
                C[i, j] += A[i, k] * B[k, j]
    return C

def main():
    # Define matrix size
    N = 1024
    print(f"For N = {N}")

    total_start = time.time()

    A = np.ones((N, N), dtype=float)
    B = np.ones((N, N), dtype=float)

    multiply_start = time.time()
    C = multiply_matrices(A, B)
    multiply_end = time.time()

    total_end = time.time()

    multiply_duration = multiply_end - multiply_start
    total_duration = total_end - total_start

    # Calculate the proportion of the multiplication time relative to the total time
    proportion = (multiply_duration / total_duration) * 100

    print(f"Time taken by matrix multiplication: {multiply_duration:.9f} seconds")
    print(f"Total time taken by the program: {total_duration:.9f} seconds")
    print(f"Proportion of multiplication time: {proportion:.2f}%")

if __name__ == "__main__":
    main()

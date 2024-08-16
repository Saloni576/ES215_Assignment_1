import numpy as np

def multiply_matrices(A, B):
    N = A.shape[0]
    C = np.zeros((N, N), dtype=int)
    for i in range(N):
        for j in range(N):
            C[i, j] = 0
            for k in range(N):
                C[i, j] += A[i, k] * B[k, j]
    return C

def main():
    sizes = [64, 128, 256, 512, 1024]

    for N in sizes:
        print(f"For N = {N}")

        A = np.ones((N, N), dtype=int)
        B = np.ones((N, N), dtype=int)

        C = multiply_matrices(A, B)

        print(f"Multiplication done for size {N}")

if __name__ == "__main__":
    main()

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void multiplyMatrices(vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};

    for (int N : sizes) {
        cout << "For N = " << N << endl;

        vector<vector<double>> A(N, vector<double>(N, 1));
        vector<vector<double>> B(N, vector<double>(N, 1));
        vector<vector<double>> C(N, vector<double>(N, 0));

        multiplyMatrices(A, B, C, N);

        cout << "Multiplication done for size " << N << endl;
    }

    return 0;
}
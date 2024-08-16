#include <bits/stdc++.h>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void multiplyMatrices(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int N) {
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
    
    int N = 1024; // Define matrix size
    cout << "For N = " << N << endl;

    auto total_start = high_resolution_clock::now();

    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 1));
    vector<vector<int>> C(N, vector<int>(N, 0));

    auto multiply_start = high_resolution_clock::now();
    multiplyMatrices(A, B, C, N);
    auto multiply_end = high_resolution_clock::now();
    
    auto total_end = high_resolution_clock::now();

    auto multiply_duration = duration_cast<duration<double>>(multiply_end - multiply_start).count();
    auto total_duration = duration_cast<duration<double>>(total_end - total_start).count();

    // Calculate the proportion of the multiplication time relative to the total time
    double proportion = (multiply_duration / total_duration) * 100;

    cout << "Time taken by matrix multiplication: " << fixed << setprecision(9) << multiply_duration << " seconds" << endl;
    cout << "Total time taken by the program: " << fixed << setprecision(9) << total_duration << " seconds" << endl;
    cout << "Proportion of multiplication time: " << fixed << setprecision(2) << proportion << "%" << endl;

    return 0;
}
#include <bits/stdc++.h>
#include <time.h>
#include <ctime>
using namespace std;

// assuming 1 as first fibonacci number

// First 50 fibonacci numbers

// Using recursion

long long fibo_recursion(int n) {
    if (n <= 1) {
        return n;
    }
    return fibo_recursion(n-1) + fibo_recursion(n-2);
}

// using loop

long long fibo_loop(int n) {
    if (n <= 1) {
        return n;
    }
    long long a = 0, b = 1, ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}

vector<long long> rec_memo(51, -1);

long long fibo_rec_memo(int n) {
    if (rec_memo[n] != -1) return rec_memo[n];
    if (n <= 1) {
        rec_memo[n] = n;
        return n;
    }
    rec_memo[n] = fibo_rec_memo(n-1) + fibo_rec_memo(n-2);
    return rec_memo[n];
}

vector<long long> loop_memo(51, -1);

long long fibo_loop_memo(int n) {
    if (loop_memo[n] != -1) return loop_memo[n];
    loop_memo[0] = 0;
    loop_memo[1] = 1;
    for (int i = 2; i <= n; ++i) {
        loop_memo[i] = loop_memo[i - 1] + loop_memo[i - 2];
    }
    return loop_memo[n];
}

int main() {

    struct timespec start, end;
    double time_taken;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 1; i <= 50; ++i) {
        cout << fibo_recursion(i) << endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / pow(10, 9);
    cout << "Time taken by CPU for recursion: " << fixed << time_taken << setprecision(9) << " seconds" << endl;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 1; i <= 50; ++i) {
        cout << fibo_loop(i) << endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / pow(10, 9);
    cout << "Time taken by CPU for loop: " << fixed << time_taken << setprecision(9) << " seconds" << endl;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 50; ++i) {
        cout << fibo_rec_memo(i) << endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / pow(10, 9);
    cout << "Time taken by CPU for recursion with memoization: " << fixed << time_taken << setprecision(9) << " seconds" << endl;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 50; ++i) {
        cout << fibo_loop_memo(i) << endl;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / pow(10, 9);
    cout << "Time taken by CPU for loop with memoization: " << fixed << time_taken << setprecision(9) << " seconds" << endl;

}
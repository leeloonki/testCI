#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>

using namespace std;
using namespace std::chrono;

vector<vector<int>> multiply(const vector<vector<int>>& A, 
                              const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void test_multiply() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    auto C = multiply(A, B);
    
    assert(C[0][0] == 19 && C[0][1] == 22);
    assert(C[1][0] == 43 && C[1][1] == 50);
    cout << "✓ Test passed!" << endl;
}

void benchmark() {
    int n = 200;
    vector<vector<int>> A(n, vector<int>(n, 1));
    vector<vector<int>> B(n, vector<int>(n, 1));
    
    auto start = high_resolution_clock::now();
    auto C = multiply(A, B);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Matrix " << n << "x" << n << " multiplication took: " 
         << duration.count() << " ms" << endl;
}

int main() {
    cout << "Running tests..." << endl;
    test_multiply();
    
    cout << "\nRunning benchmark..." << endl;
    benchmark();
    
    return 0;
}
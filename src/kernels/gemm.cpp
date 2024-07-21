#include <chrono>
#include <iostream>

constexpr size_t N = 2048;

int main() {

    // float** A = new float[N*N];
    // float** B = new float[NN];
    // float** C = new float[N][N];

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            A[i][j] = i - j;
            B[j][i] = i - j;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            for (size_t k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << duration.count() << std::endl;



}

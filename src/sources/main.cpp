
#include <thread>
#include <iomanip>

#include "Matrix.h"

void multi_thread_matrix(int** A, int** B, int** C, int size, int start) {
    for (int i = start * size/2; i < (start + 1)*size/2; i++) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    std::cout << std::setfill('-') << std::setw(15);
    std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
}


int main(int argc, char* argv[])
{
    // create matrix
    Matrix matrix_A;
    Matrix matrix_B;
    Matrix matrix_C;

    srand(time(0));

    // fill matrix A and B using random values
    matrix_A.fill_matrix();
    matrix_B.fill_matrix();

    std::cout << "Start threads" << std::endl;

    auto start = std::chrono::steady_clock::now();

    std::thread first_thread(multi_thread_matrix, matrix_A.getMatrix(), matrix_B.getMatrix(), matrix_C.getMatrix(), SIZE, 0);
    std::thread second_thread(multi_thread_matrix, matrix_A.getMatrix(), matrix_B.getMatrix(), matrix_C.getMatrix(), SIZE, 1);

    first_thread.join();
    second_thread.join();

    auto end = std::chrono::steady_clock::now();

    std::cout << "Finish threads" << std::endl;

    if(SIZE <= 10){

        std::cout << "Matrix A:" << std::endl;
        matrix_A.print_matrix();
        std::cout << "Matrix B:" << std::endl;
        matrix_B.print_matrix();
        std::cout << "Matrix C:" << std::endl;
        matrix_C.print_matrix();
    }

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Total time: " << duration.count() << std::endl;

    return 0;
}



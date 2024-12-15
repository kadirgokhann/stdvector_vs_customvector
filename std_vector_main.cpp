#include <vector>
#include <iostream>
#include <chrono>

int main() {

    auto start = std::chrono::high_resolution_clock::now();
    ////////////////////////////////////////////////////////////////////////////
    std::vector<int> vec;
    vec.reserve(1000000000);

    for (int i = 0; i < 1000000000; i++) {
        vec.push_back(i * 1021 % 10) ;
    }

    int avg = 0;
    for (int i = 0; i < 1000000000; i++) {
        avg += vec[i];
    }
    avg /= 100000;
    printf("Average: %d\n", avg);

    ////////////////////////////////////////////////////////////////////////////
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds, which is " << duration.count() / 1000000.0 << " seconds" << std::endl;
    return 0;
}

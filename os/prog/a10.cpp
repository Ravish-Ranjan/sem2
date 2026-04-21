#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

void getPartSum(size_t from, size_t to,size_t& result) {
    result = 0;
    for (size_t i = from; i <= to; i++) {
        result += (i*i);
    }
}

int main(){
    size_t n = 1000000; // 1 million safe for size_t 
    int numOfThreads = 4;

    cout << "Calculating sum of squares from 1 to " << n << " using " << numOfThreads << " threads.\n" << endl;

    vector<thread> threads;
    vector<size_t> results(numOfThreads, 0);

    size_t chunkSize = n / numOfThreads;  // 1 million per thread

    auto startTime = chrono::high_resolution_clock::now();
    for (int i = 0; i < numOfThreads; i++) {
        size_t from = i * chunkSize + 1;
        size_t to = (i == numOfThreads - 1) ? n : (i + 1) * chunkSize;
        threads.emplace_back(getPartSum, from, to, ref(results[i]));
    }

    for (auto& t : threads) {
        t.join();
    }

    size_t totalSum = 0;
    for (size_t result : results) {
        totalSum += result;
    }
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Total sum (multithreaded): " << totalSum << endl;

    cout << "Time taken (multithreaded): " << duration.count() << " microseconds" << endl;

    totalSum = 0;

    startTime = chrono::high_resolution_clock::now();
    for(size_t i = 1; i <= n; i++) {
        totalSum += (i*i);
    }
    endTime = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Total sum (single-threaded): " << totalSum << endl;
    cout << "Time taken (single-threaded): " << duration.count() << " microseconds" << endl;

    return 0;
}
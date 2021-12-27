// This code is referenced from "modoocode.com"
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
    int sum = 0;
    for(auto itr=start; itr<end; ++itr) {
        sum += *itr;
    }
    *result = sum;

    // getting thread id
    thread::id this_id = std::this_thread::get_id();
    printf("Result of calculating thread %d from %d to %d : %d\n", this_id, *start, *(end-1), sum);
}

int main() {
    vector<int> data(100000);
    for(int i=0; i<100000; i++) {
        data[i] = i;
    }

    // vector that contains partial sums of each thread
    vector<int> partial_sums(4);

    vector<thread> workers;
    for(int i=0; i<4; i++) {
        workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
    }

    for(int i=0; i<4; i++) {
        workers[i].join();
    }

    int total=0;
    for(int i=0; i<4; i++) {
        total += partial_sums[i];
    }

    std::cout<<"Total sum = " << total << std::endl;
}



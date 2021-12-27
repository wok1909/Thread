// This code is referenced from "modoocode.com"
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(int& counter) {
    for(int i=0; i<10000; i++) {
        counter += 1;
    }
}

int main() {
    int counter = 0;

    vector<thread> workers;
    for(int i=0; i<4; i++) {
        // Need to wrap parameter with ref() to pass by reference
        workers.push_back(thread(worker, std::ref(counter)));
    }

    for(int i=0; i<4; i++) {
        workers[i].join();
    }

    std::cout<<"Total sum = " << counter << std::endl;
}



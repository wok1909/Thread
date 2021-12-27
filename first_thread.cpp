// This code is referenced from "modoocode.com"
 
#include <iostream>
#include <thread>       // Library for making threads
using std::thread;

void func1() {
    for(int i=0; i<10; i++) {
        std::cout<<"Thread 1 working!\n";
    }
}

void func2() {
    for(int i=0; i<10; i++) {
        std::cout<<"Thread 2 working!\n";
    }
}

void func3() {
    for(int i=0; i<10; i++) {
        std::cout<<"Thread 3 working!\n";
    }
}

int main() {
    thread t1(func1);   // making a thread that does func1()
    thread t2(func2);
    thread t3(func3);

    // t1.join();    // when join is here, program cannot end until the thread job is done and join to the main thread
    // t2.join();
    // t3.join();

    t1.detach();        // Detaching the thread from main thread, so main function doesn't need to wait until the end
    t2.detach();
    t3.detach();

    std::cout<< "main function end\n";
}
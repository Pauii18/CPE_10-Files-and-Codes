#include <iostream>
#include <thread>
#include <mutex>

// 1. Create a global variable of type integer
int global_counter = 0;
std::mutex mtx; // Mutex to ensure thread-safe addition (prevents race conditions)

// 2. Create an add function that takes an integer parameter
void add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    global_counter += value;
}

int main() {
    // 3. Use multi-threading techniques to create 3 threads and pass the add function
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    // 4. Display and join sequences as specified
    std::cout << "Initial check (Threads running): " << global_counter << std::endl;

    T1.join();
    std::cout << "After T1.join(): " << global_counter << std::endl;

    T2.join();
    std::cout << "After T2.join(): " << global_counter << std::endl;

    T3.join();
    std::cout << "After T3.join(): " << global_counter << std::endl;

    return 0;
}

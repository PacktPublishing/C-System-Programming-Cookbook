#include <iostream>
#include <utility>
#include <atomic>

struct MyArray { int z[50]; };
struct MyStr { int a, b; };

int main()
{
    std::atomic<MyArray> myArray;
    std::atomic<MyStr> myStr;
    std::cout << std::boolalpha
              << "std::atomic<myArray> is lock free? "
              << std::atomic_is_lock_free(&myArray) << std::endl
              << "std::atomic<myStr> is lock free? "
              << std::atomic_is_lock_free(&myStr) << std::endl;
}


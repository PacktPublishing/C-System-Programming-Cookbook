#include <sys/mman.h>
#include <iostream>
#include <vector>

template<typename T>
class mmap_allocator
{
public:

    using value_type = T;
    template<typename U> struct rebind {
        using alloc = mmap_allocator<U>;
    };

public:

    mmap_allocator() {};

    template <typename U>
    mmap_allocator(const mmap_allocator<U> &alloc) noexcept
    { 
	(void) alloc; 
    };

    T* allocate(std::size_t n)
    {
	std::cout << "allocating ... n = " << n << std::endl;
	auto* mapPtr = static_cast<T*> (mmap(0, sizeof(T) * n, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    	if (mapPtr != MAP_FAILED)
	    return static_cast<T*>(mapPtr);
        throw std::bad_alloc();
    };

    void deallocate(T* p, std::size_t n)
    {
	std::cout << "deallocating ... n = " << n << std::endl;
	munmap(p, sizeof(T) * n);
    };
};

int main ()
{
	std::vector<int, mmap_allocator<int>> mmap_vector = {1, 2, 3, 4, 5};

	for (auto i : mmap_vector)
		std::cout << i << std::endl;

	return 0;
}


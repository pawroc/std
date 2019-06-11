#pragma once

#include <memory>
#include <iostream>

namespace my
{
template<class T>
class allocator : public std::allocator<T>
{
public:
    using size_type = typename std::allocator<T>::size_type;
    using pointer = typename std::allocator<T>::pointer;

    template<class U>
    struct rebind
    {
        using other = allocator<U>;
    };


    pointer allocate(size_type size)
    {
#ifdef ALLOCATOR_LOG_ON
        std::cout << "custom allocator size: " << size << '\n';
#endif
        return reinterpret_cast<pointer>(operator new(size * sizeof(T)));
    }

    void deallocate(pointer ptr, size_type size)
    {
#ifdef ALLOCATOR_LOG_ON
        std::cout << "custom deallocation size: " << size << '\n';
#endif
        operator delete(ptr);
    }

};
} // namespace my
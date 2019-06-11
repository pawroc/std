// Comilation: g++ -std=c++17 -g -DALLOCATOR_LOG_ON main.cpp -I. && ./a.out
//             g++ -std=c++17 -g main.cpp -I. && ./a.out

#include <list>
#include <vector>
#include <new>
#include "allocator.hpp"

void allocateVector()
{
    std::vector<int, my::allocator<int>> v;
    v.emplace_back(1); v.emplace_back(1); v.emplace_back(1); v.emplace_back(1); v.emplace_back(1);
    v.emplace_back(1); v.emplace_back(1); v.emplace_back(1); v.emplace_back(1); v.emplace_back(1);
}

void allocateList()
{
    std::list<int, my::allocator<int>> l;
    l.emplace_back(1); l.emplace_back(1); l.emplace_back(1); l.emplace_back(1); l.emplace_back(10);
    l.emplace_back(1); l.emplace_back(1); l.emplace_back(1); l.emplace_back(1); l.emplace_back(10);
}

int main()
{
    allocateList();
    return 0;
}
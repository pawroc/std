// Compile: g++ main.cpp -I. -ggdb3 -std=c++1z
// Valgrind: valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./a.out

#include "list.hpp"
#include <cassert>
#include <iostream>

template<class Iterator>
void double_each_element(Iterator begin, Iterator end) 
{
    for (auto it = begin; it != end; ++it) {
        *it *= 2;
    } 
}

template <class Iterator>
void print(Iterator begin, Iterator end)
{
    std::cout << '[';
    for (auto it = begin; begin != end; ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << "]\n";
}

void testClear()
{
    my::std::List<int> list;
    list.emplace_back(1);
    list.emplace_back(2);

    assert(not list.empty());

    list.clear();

    assert(list.empty());
}

void testIterators()
{
    my::std::List<int> list;
    list.emplace_back(1);
    list.emplace_back(2);
    list.emplace_back(3);

    assert(*(list.begin()) == 1);
    assert(*(list.end()) == 3);

    *(list.begin()) = 10;
    assert(*(list.begin()) == 10);

    assert(list.begin() == list.cbegin());
}

void testDeleteNode()
{
    my::std::List<int> list;
    list.emplace_back(1);
    list.emplace_back(2);
    list.emplace_back(3);

    list.deleteNode();

    assert(*(list.begin()) == 2);
    assert(*(list.end()) == 3);
}

void testComparisons()
{
    my::std::List<int> list;
    list.emplace_back(1);
    list.emplace_back(2);

    auto it1 = list.begin();
    auto it2 = list.end();
    assert(not (it1 == it2));
    assert(it1 == it1);
    assert(not (it1 != it1));
    assert(it1 != it2);
}

void testIncrementations()
{
    my::std::List<int> list;
    list.emplace_back(1);
    list.emplace_back(2);
    list.emplace_back(3);
    print(list.cbegin(), list.cend());

    // auto it = list.begin();
    // assert(*(++it) == 2);
    // assert(*(it++) == 2);

    // double_each_element(list.begin(), list.end());

    // print(list.begin(), list.end());

    // assert(*list.begin() == 2);
    // assert(list.begin() + 1 == 4);
    // assert(*list.end() == 6);
}

int main()
{
    testClear();
    testIterators();
    testDeleteNode();
    testComparisons();
    testIncrementations();
    return 0;
}
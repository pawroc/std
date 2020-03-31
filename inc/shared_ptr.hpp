# pragma once

#include <iostream>

namespace my::std
{
template<class T>
class shared_ptr
{
public:
    shared_ptr() = default;

    explicit shared_ptr(T* ptr)
    {
        if (not pointee)
        {
            // ::std::cout << "+++ creating new shared_ptr\n";
            refCount = new unsigned int(1);
            pointee = ptr;
        }
        else
        {
            // ::std::cout << "+++ increasing refCount\n";
            ++(*refCount);
        }
    }

    shared_ptr(const shared_ptr<T>& other)
    {
        // ::std::cout << "+++ copying from other shared_ptr -> increasing refCount\n";
        pointee = other.pointee;
        refCount = other.refCount;

        ++(*refCount);
    }

    shared_ptr(shared_ptr<T>&& other)
    {
        // ::std::cout << "=== moving from other shared_ptr\n";
        move(::std::move(other));
    }

    shared_ptr<T>& operator=(const shared_ptr<T>& other)
    {
        if (&other == this) return *this;

        // ::std::cout << "=== copy assigning from other shared_ptr\n";
        pointee = other.pointee;
        refCount = other.refCount;
        ++(*refCount);

        return *this;
    }

    shared_ptr<T>& operator=(shared_ptr<T>&& other)
    {
        if (&other == this) return *this;

        // ::std::cout << "=== move assigning from other shared_ptr\n";
        if (pointee)
        {
            // ::std::cout << "--- decrementing current refCount\n";
            decrement();
        }
        move(::std::move(other));

        return *this;
    }

    ~shared_ptr()
    {
        // ::std::cout << "<< deleting shared_ptr\n";
        decrement();
    }

    unsigned int ref_count() const
    {
        if (refCount) return *refCount;
        return 0;
    }

private:
    void decrement()
    {
        if (pointee)
        {
            if (*refCount == 1)
            {
                // ::std::cout << "--- deleting pointee\n";
                delete pointee;
                delete refCount;

                pointee = nullptr;
                refCount = nullptr;
            }
            else
            {
                --(*refCount);
            }
        }
    }

    void move(shared_ptr<T>&& other)
    {
        pointee = other.pointee;
        refCount = other.refCount;

        other.pointee = nullptr;
        other.refCount = nullptr;
    }

private:
    T* pointee{nullptr};
    unsigned int* refCount{nullptr};
};
} // namespace my::std
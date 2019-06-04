#pragma once

#include <type_traits>

namespace my::std
{
template <class T, bool Const>
class iterator
{
private:
    using reference = ::std::conditional_t<Const, const typename T::value_type&, typename T::value_type&>;
    using node_pointer = ::std::conditional_t<Const, const T*, T*>;

    friend class iterator<T, !Const>;

public:
    explicit iterator(T* ptr) : node{ptr}
    {
    }

    reference operator* ()
    {
        return node->data;
    }

    reference operator-> ()
    {
        return node->data;
    }

    template <bool U>
    bool operator== (const iterator<T, U>& it) const
    {
        return node == it.node;
    }

    template <bool U>
    bool operator!= (const iterator<T, U>& it) const
    {
        return node != it.node;
    }

    auto& operator++ ()
    {
        node = node->nextNode;
        return *this;
    }

    auto operator++ (int)
    {
        auto result = *this;
        ++*this;
        return result;
    }

    operator iterator<T, true>() const
    {
        return iterator<T, true>{node};
    }

private:
    node_pointer node;
};

template <class T>
class List
{
private:
    struct Node
    {
        using value_type = T;

        T data{};
        Node* nextNode{nullptr};
    };

    using iterator = my::std::iterator<Node, false>;
    using const_iterator = my::std::iterator<Node, true>;

public:
    using value_type = T;

    ~List()
    {
        clear();
    }

    void emplace_back(T val)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = val;
            tail = head;
        }
        else if (tail == head)
        {
            tail = new Node;
            tail->data = val;
            head->nextNode = tail;
        }
        else
        {
            tail->nextNode = new Node;
            tail = tail->nextNode;
            tail->data = val;
        }
    }

    iterator begin() const
    {
        return iterator{head};
    }

    iterator end() const
    {
        return iterator{tail};
    }

    const_iterator cbegin() const
    {
        return const_iterator{head};
    }

    const_iterator cend() const
    {
        return const_iterator{tail};
    }

    void deleteNode()
    {
        Node* nextNode = head->nextNode;
        delete head;
        head = nextNode; 
    }

    void clear()
    {
        while (head != nullptr)
        {
            deleteNode();
        }
        head = nullptr;
        tail = nullptr;
    }

    bool empty()
    {
        return head == nullptr and tail == nullptr;
    }

private:
    Node* head{nullptr};
    Node* tail{nullptr};
};
} // namespace my::std
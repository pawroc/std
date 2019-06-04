#pragma once

namespace my::std
{
template <class T>
class iterator
{
public:
    using reference = typename T::value_type&;
    using node_pointer = T*;

    explicit iterator(T* ptr) : nodePtr{ptr}
    {
    }

    reference operator* ()
    {
        return nodePtr->data;
    }

    reference operator-> ()
    {
        return nodePtr->data;
    }

    bool operator== (const iterator<T>& it) const
    {
        return nodePtr == it.nodePtr;
    }

    bool operator!= (const iterator<T>& it) const
    {
        return nodePtr != it.nodePtr;
    }

    auto& operator++ ()
    {
        nodePtr = nodePtr->nextNode;
        return *this;
    }

    auto operator++ (int)
    {
        auto result = *this;
        ++*this;
        return result;
    }

private:
    node_pointer nodePtr;
};

template <class T>
class const_iterator
{
p
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

    iterator<Node> begin()
    {
        return iterator{head};
    }

    iterator<Node> end()
    {
        return iterator{tail};
    }

    // const T* const cbegin() const
    // {
    //     return head->data;
    // }

    // const T* const cend() const
    // {
    //     return tail->data;
    // }

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
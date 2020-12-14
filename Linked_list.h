#pragma once
#include <iterator>
// time complexity O(n) 

template<typename T>
class Linked_List
{
    using value_type = T;
    using size_type = size_t;
    using reference = value_type&;
    using const_reference = const reference;

    struct Node
    {
        Node(value_type arg) : data(arg), nextPtr(nullptr) {}
        value_type data;
        Node* nextPtr;
    };

    using NodePtr = Node*;
    //using iterator = LegacyBidirectionalIterator;
    //using const_iterator = const LegacyBidirectionalIterator;
    //using reverse_iterator = std::reverse_iterator<iterator>;
    //using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
    Linked_List();
    explicit Linked_List(size_type n);
    Linked_List(const Linked_List& other);
    Linked_List(Linked_List&& other);
    ~Linked_List();

    Linked_List& operator=(const Linked_List&);
    Linked_List& operator=(Linked_List&& other) noexcept;

    reference front();
    const_reference front() const;

    reference back();
    const_reference back() const;

    // iterators;

    bool empty() const;
    size_type size() const;

    void clear() noexcept;

    void insert(size_t pos, const_reference value);
    //iterator insert(interator pos, const_reference value);
    //iterator insert(std::initializer_list<value_type>);
    
    //template< class... Args >
    //iterator emplace(const_iterator pos, Args&&... args);

    //iterator erase(iterator pos);
    //iterator erase(const_iterator first, const_iterator last);

    void push_back(value_type&&);
    void push_back(const value_type&);
    void pop_back();
    void push_front(const value_type&);
    void pop_front();

    void resize(size_type n);
    void swap(Linked_List&);

private:

    NodePtr m_HeadPtr;
    NodePtr m_TailPtr;
    size_type m_Size;
};


#include "Linked_List_impl.h"

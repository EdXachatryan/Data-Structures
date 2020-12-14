#ifndef LINKED_LIST
#define LINKED_LIST

#include "Linked_list.h"
#include <type_traits>
#include <iostream>


template<typename T>
Linked_List<T>::Linked_List() :m_HeadPtr(nullptr), m_Size(0)
{
}


template<typename T>
Linked_List<T>::Linked_List(size_type nSize)
{
    try
    {
        if (!std::is_default_constructible<T>::value)
            throw std::exception("Type isn't default constructible");
             
        m_HeadPtr = new Node(T());
        NodePtr tempCurrent = m_HeadPtr->nextPtr;

        for (size_t i = 0; i < nSize; i++)
        {
            tempCurrent = new Node(T());
            tempCurrent = tempCurrent->nextPtr;
        }
        this->m_Size = nSize;
    }
    catch (const std::exception& excp)
    {
        std::cout << excp.what() << std::endl;
    }
}

template<typename T>
inline Linked_List<T>::Linked_List(const Linked_List& other)
{
    if (!other.m_Size)
        return;

    int nSizeOther = other.size();
    int nDifferece = m_Size - nSizeOther;

    bool isMore = true;
    if (nDifferece <= 0)
    {
        std::abs(nDifferece);
        isMore = false;
    }
    NodePtr thisTemp = m_HeadPtr;
    NodePtr otherTemp = other.m_HeadPtr;
    // be careful. you dasn't have two pointers pointing to the same thing.
    if (isMore)
    {
        for (size_t i = 0; i < nSizeOther; ++i)
        {
            thisTemp->data = otherTemp->data;
            thisTemp = thisTemp->ptrNext;
            otherTemp->otherTemp->ptrNext;
        }

        for (size_t i = 0; i < nDifferece; ++i)
        {
            NodePtr deleter = thisTemp->ptrNext;
            delete thisTemp;
        }
    }
    else
    {
        for (size_t i = 0; i < m_Size; ++i)
        {
            thisTemp->data = otherTemp->data;
            thisTemp = thisTemp->ptrNext;
            otherTemp->otherTemp->ptrNext;
        }
        for (size_t i = 0; i < nDifferece; ++i)
        {
            thisTemp->ptrNext = new Node(otherTemp->data);
            otherTemp->otherTemp->ptrNext;
        }
    }

    m_Size = otherTemp->m_Size;
}

// qani vor static tiruti objecta => vor destructor@ partadir petq e sahmanvac lini , aylapes unresolved external symbol klini
template<typename T>
Linked_List<T>::~Linked_List()
{
    // clear();
}
// member functions implementetion

template<typename T>
typename Linked_List<T>::reference Linked_List<T>::front()
{
    return static_cast<T>(const_cast<T&>(front()));
    
    //or

    //if (!m_HeadPtr)
    //    throw std::exception("Empty Linked_list");
    //return *m_HeadPtr;
}

template<typename T>
typename Linked_List<T>::const_reference Linked_List<T>::front() const
{
    if (!m_HeadPtr)
        throw std::exception("Empty Linked_list");
    return *m_HeadPtr;
}
template<typename T>
typename Linked_List<T>::reference Linked_List<T>::back()
{
    return *m_TailPtr;
}

template<typename T>
typename Linked_List<T>::const_reference Linked_List<T>::back() const
{
    return *m_TailPtr;
}

template<typename T>
inline bool Linked_List<T>::empty() const
{
    if (m_HeadPtr == nullptr)
        return false;
    return true;
}

template<typename T>
inline typename Linked_List<T>::size_type Linked_List<T>::size() const
{
    return m_Size;
}


#endif // !LINKED_LIST

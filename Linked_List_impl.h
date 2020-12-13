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
    if (!m_HeadPtr)
        throw std::exception("Empty Linked_list");
    return *m_HeadPtr;
}




#endif // !LINKED_LIST

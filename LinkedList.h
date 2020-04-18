#pragma once

#include "ListNode.h"
// #include "IndexOutOfBoundException.h"

template <class T>
class LinkedList
{
    public:
        ~LinkedList(){this->empty();}
        void add(const T& element);
        void addAt(unsigned int index, const T& element);
        void updateAt(unsigned int index, const T& element);
        const T& get(const unsigned int index);
        const unsigned int size();
        void removeAt(const unsigned int index);
        void empty();
    
    private:
        ListNode<T>* headerNode = nullptr;
    
};


template <class T>
void LinkedList<T>::add(const T& element)
{
    if(this->headerNode == nullptr)
    {
        this->headerNode = new ListNode<T>(element);
    }
    else
    {
        this->headerNode->add(element);
    }
}


template <class T>
void LinkedList<T>::addAt(unsigned int index, const T& element)
{
    if(index == 0 && this->headerNode == nullptr)
    {
        this->add(element);
    }
    else if(this->headerNode != nullptr)
    {
        this->headerNode->add(0, index, element);
    }
    else
    {
        IndexOutOfBoundException ex(index, 0);
        throw ex;
    }
    
}


template <class T>
void LinkedList<T>::updateAt(unsigned int index, const T& element)
{
    if(this->headerNode != nullptr)
    {
        this->headerNode->update(0, index, element);
    }
    else
    {
        IndexOutOfBoundException ex(index, 0);
        throw ex;
    }
    
}


template <class T>
const T& LinkedList<T>::get(const unsigned int index)
{
    if(this->headerNode != nullptr)
    {
        this->headerNode->get(0, index);
    }
    else
    {
        IndexOutOfBoundException ex(index, 0);
        throw ex;
    }
}


template <class T>
const unsigned int LinkedList<T>::size()
{
    if(this->headerNode == nullptr)
    {
        return 0;
    }
    else
    {
        return this->headerNode->count(0) + 1;
    }
}


template <class T>
void LinkedList<T>::removeAt(const unsigned int index)
{
    if(this->headerNode != nullptr)
    {
        this->headerNode->removeAt(0, index);
    }
    else
    {
        IndexOutOfBoundException ex(index, 0);
        throw ex;
    }
}


template <class T>
void LinkedList<T>:: empty()
{
   if(this->headerNode != nullptr)
    {
        this->headerNode->removeAll();
        delete this->headerNode;
        this->headerNode = nullptr;
    }
    
}
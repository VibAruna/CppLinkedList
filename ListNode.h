#pragma once

#include "IndexOutOfBoundException.h"

template <class T>
class ListNode
{
    public:
        ListNode(const T& element);
        ListNode(const ListNode& node);
        void add(const T& element);
        void add(unsigned int count, const unsigned int index, const T& element);
        const T& get(unsigned int count, const unsigned int index);
        const unsigned int count(unsigned int current_count);
        void update(unsigned int count, const unsigned int index, const T& element);
        void removeAt(unsigned int count, const unsigned int index);
        void removeAll();
    
    private:
        T element;
        ListNode<T>* nextNode = nullptr;
    
};


template <class T>
ListNode<T>::ListNode(const T& element)
{
    this->element = element;
}


template <class T>
ListNode<T>::ListNode(const ListNode& node)
{
    this->element = node.element;
    this->nextNode = node.nextNode;
}

template <class T>
void ListNode<T>::add(const T& element)
{
    if(this->nextNode == nullptr)
    {
        this->nextNode = new ListNode<T>(element);
    }
    else
    {
        this->nextNode->add(element);
    }
}


template <class T>
void ListNode<T>::add(unsigned int count, const unsigned int index, const T& element)
{
    if(count == index)
    {
        ListNode<T>* newNode = new ListNode<T>(*this);
        this->nextNode = newNode;
        this->element = element;
    }
    else if(count == index-1 && this->nextNode == nullptr)
    {
        this->nextNode = new ListNode<T>(element);        
    }
    else if(count < index && this->nextNode != nullptr)
    {
        this->nextNode->add(++count, index, element);
    }
    else
    {
        IndexOutOfBoundException ex(index, count);
        throw ex;
    }
    
}


template <class T>
const T& ListNode<T>::get(unsigned int count, const unsigned int index)
{
    if(count == index)
    {
        return this->element;
    }
    else if(this->nextNode != nullptr)
    {
        return this->nextNode->get(++count, index);
    }
    else
    {
        IndexOutOfBoundException ex(index, count);
        throw ex;
    }
}

template <class T>
const unsigned int ListNode<T>::count(unsigned int current_count)
{
    if(this->nextNode == nullptr)
    {
        return current_count;
    }
    else
    {
        return this->nextNode->count(++current_count);
    }
}

template <class T>
void ListNode<T>::update(unsigned int count, const unsigned int index, const T& element)
{
    if(count == index)
    {
        this->element = element;
    }
    else if(count < index && this->nextNode != nullptr)
    {
        this->nextNode->update(++count, index, element);
    }
    else
    {
        IndexOutOfBoundException ex(index, count);
        throw ex;
    }
}

template <class T>
void ListNode<T>:: removeAt(unsigned int count, const unsigned int index)
{
    if(count == index-1 && this->nextNode != nullptr)
    {
        ListNode* newNextNode = this->nextNode->nextNode;
        delete nextNode;
        nextNode = newNextNode;
    }
    else if(count < index-1 && this->nextNode != nullptr)
    {
        this->nextNode->removeAt(++count, index);
    }
    else
    {
        IndexOutOfBoundException ex(index, count);
        throw ex;
    }
}


template <class T>
void ListNode<T>::removeAll()
{
    if(this->nextNode != nullptr)
    {
        this->nextNode->removeAll();
        delete this->nextNode;
        this->nextNode = nullptr;
    }
}

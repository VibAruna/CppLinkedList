#pragma once

#include "IndexOutOfBoundException.h"
#include <iostream>

template <class T>
class LinkedList
{
    public:
        /******************************************************************************************************
        * Func  : ~LinkedList()
        * Desc  : Destructor of the object. Clear all the elements in the list.
        * Param : None
        * Ret   : None
        ******************************************************************************************************/
        ~LinkedList(){this->empty();}


        /******************************************************************************************************
        * Func  : add
        * Desc  : Adds an element to the end of the list. 
        * Param : element - constant reference to an element to be added.
        * Ret   : None
        ******************************************************************************************************/
        void add(const T& element);


        /******************************************************************************************************
        * Func  : add
        * Desc  : Adds an element to the specified index of the list. Shifts any subsequent elements to the right
        * Param : index     - index to add the element
        *         element   - constant reference to an element to be added
        * Ret   : None
        ******************************************************************************************************/
        void addAt(unsigned int index, const T& element);


        /******************************************************************************************************
        * Func  : updateAt
        * Desc  : Updates the specified index with the new element.
        * Param : index     - index to update
        *         element   - new element for the specified index
        * Ret   : None
        ******************************************************************************************************/
        void updateAt(unsigned int index, const T& element);


        /******************************************************************************************************
        * Func  : get
        * Desc  : Returns a reference to the element in the specified index.
        * Param : index - index of the element to return
        * Ret   : A reference to the element in the index
        ******************************************************************************************************/
        T& get(const unsigned int index);


        /******************************************************************************************************
        * Func  : size
        * Desc  : Returns the number of elements in this list.
        * Param : None
        * Ret   : The number of elements in this list
        ******************************************************************************************************/
        const unsigned int size();


        /******************************************************************************************************
        * Func  : removeAt
        * Desc  : Removes the element at the specified position. Shifts any subsequent elements to the left
        * Param : index - the index of the element to be removed
        * Ret   : None
        ******************************************************************************************************/
        void removeAt(const unsigned int index);


        /******************************************************************************************************
        * Func  : empty
        * Desc  : Removes all the elements in the list.
        * Param : None
        * Ret   : None
        ******************************************************************************************************/
        void empty();


        /******************************************************************************************************
        * Func  : operator=
        * Desc  : Operator overloading of =. Points this list object to the header node of the rhs object.
        * Param : rhs - right hand side LinkedList object
        * Ret   : None
        ******************************************************************************************************/
        void operator=(const LinkedList& rhs);


        /******************************************************************************************************
        * Func  : operator[]
        * Desc  : Operator overloading of []. Returns a reference to the element in the specified index.
        * Param : index - index of the element to return
        * Ret   : A reference to the element in the index
        ******************************************************************************************************/
        T& operator[](const unsigned int index);
    
    private:
        struct ListNode
        {
            //Structure to store data.
            T element;
            ListNode* nextNode = nullptr;
        };
        ListNode* headerNode = nullptr;  //Points to the header node


        /******************************************************************************************************
        * Func  : getElementPtr
        * Desc  : Search for the pointer to the list node in the specified index.
        * Param : index - index of the element search
        *         ptr   - pointer to a ListNode pointer variable. Pointer of the specified index is assigned to
        *                 the pointer variable pointed by this. 
        * Ret   : None
        ******************************************************************************************************/
        void getElementPtr(const unsigned int index, ListNode** ptr);


        /******************************************************************************************************
        * Func  : getLastElementPtr
        * Desc  : Search for the pointer to the last list node.
        * Param : ptr   - pointer to a ListNode pointer variable. Pointer of the last node is assigned to the
        *                 pointer variable pointed by this. 
        * Ret   : None
        ******************************************************************************************************/
        void getLastElementPtr(ListNode** ptr);
    
};


//------------------------------------function definitions-----------------------------------------------------

template <class T>
void LinkedList<T>::add(const T& element)
{
    if(this->headerNode == nullptr)
    {
        this->headerNode = new ListNode{element};
    }
    else
    {
        ListNode* lastNode = this->headerNode;
        while(lastNode->nextNode != nullptr)
        {
            lastNode = lastNode->nextNode;
        }
        lastNode->nextNode = new ListNode{element};
    }
}


template <class T>
void LinkedList<T>::addAt(unsigned int index, const T& element)
{
    ListNode* element_ptr;
    if(index == 0)
    {
        if(headerNode == nullptr)
        {   
            this->add(element);
            return;
        }
        else {element_ptr = headerNode;}
    }
    else
    {
        this->getElementPtr(index-1, &element_ptr);
        if(element_ptr -> nextNode == nullptr) 
        {
            this->add(element);
            return;
        }
        else {element_ptr = element_ptr -> nextNode;}
    }

    ListNode* cpy_node = new ListNode{element_ptr->element, element_ptr->nextNode};
    element_ptr->element = element;
    element_ptr->nextNode = cpy_node;    
}


template <class T>
void LinkedList<T>::updateAt(unsigned int index, const T& element)
{
    ListNode* element_ptr;
    this->getElementPtr(index, &element_ptr);
    element_ptr->element = element;    
}


template <class T>
T& LinkedList<T>::get(const unsigned int index)
{    
    ListNode* element_ptr;
    this->getElementPtr(index, &element_ptr);
    return element_ptr->element;
    
}   


template <class T>
void LinkedList<T>::getElementPtr(const unsigned int index, ListNode** ptr)
{
    if(this->headerNode == nullptr)
    {
        this->empty();
        IndexOutOfBoundException ex(index, 0);
        throw ex;
    }
    else
    {
        ListNode* node = this->headerNode;
        for(unsigned int i = 0; i < index; i++)
        {
            node = node->nextNode;
            if(node == nullptr)
            {
                this->empty();
                IndexOutOfBoundException ex(index, i+1);
                throw ex;
            }
            
        }
        *ptr = node;
    }
}


template <class T>
void LinkedList<T>:: getLastElementPtr(ListNode** ptr)
{
    if(this->headerNode == nullptr)
    {
        *ptr = nullptr;
    }
    else
    {
        ListNode* last_node = this->headerNode;
        while(last_node->nextNode != nullptr)
        {
            last_node = last_node->nextNode;
        }
        *ptr = last_node;        
    }
}

template <class T>
const unsigned int LinkedList<T>::size()
{
    unsigned int length = 0;
    ListNode* next = this->headerNode;
    while(next != nullptr)
    {
        length++;
        next = next->nextNode;
    }
    return length;
}


template <class T>
void LinkedList<T>::removeAt(const unsigned int index)
{
    if(index > 0)
    {
        ListNode* element_ptr;
        this->getElementPtr(index-1, &element_ptr);
        if(element_ptr->nextNode != nullptr)
        {
            ListNode* next_element = element_ptr->nextNode->nextNode;
            delete element_ptr->nextNode;
            element_ptr->nextNode = next_element;
        }
        else
        {
            this->empty();
            IndexOutOfBoundException ex(index, index);
            throw ex;
        }
        
    }
    else
    {
        ListNode* next_element = this->headerNode->nextNode;
        delete this->headerNode;
        this->headerNode = next_element;
    }
    

    
}


template <class T>
void LinkedList<T>:: empty()
{
   if(this->headerNode != nullptr)
    {
        ListNode* parent = this->headerNode;
        ListNode* child;
        do
        {
            child = parent->nextNode;
            delete parent;
            parent = child;
        }
        while(child != nullptr);
        
    }
    
}


template <class T>
void LinkedList<T>::operator=(const LinkedList& rhs)
{
    this->headerNode = rhs.headerNode;
}


template <class T>
T& LinkedList<T>::operator[](const unsigned int index)
{   
    return this->get(index);
}
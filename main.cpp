/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "LinkedList.h"
#include <iostream>

int main()
{
    // printf("Hello World");
    LinkedList<int> list;
    for(int i = 0; i < 10; i++)
    {
        // list.addAt(i,i);
        list.add(i);
    }
    
    list.addAt(2,3);
    list.updateAt(6,3);
    list.removeAt(7);
    // // list.empty();
    for(int i = 0; i < list.size(); i++)
    {
        std::cout << list.get(i) << std::endl;
    }
    
    return 0;
}
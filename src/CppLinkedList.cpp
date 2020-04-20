//============================================================================
// Name        : CppLinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Unit Testing for LinkedList
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include "LinkedList.h"
using namespace std;

TEST(LinkedListTest, canAddAndGetMultipleElement)
{
	LinkedList<int> list;
	for(int i = 0; i < 5; i++)
	{
		list.add(i);
	}

	for(int i = 0; i < 5; i++)
	{
		ASSERT_EQ(i, list.get(i));
	}
}

TEST(LinkedListTest, canAddToAGivenIndex)
{
	LinkedList<int> list;
	list.addAt(0,7);
	list.addAt(0,5);
	list.addAt(1,6);
	ASSERT_EQ(5, list.get(0));
	ASSERT_EQ(6, list.get(1));
	ASSERT_EQ(7, list.get(2));
}

TEST(LinkedListTest, AddingToNonExistingIndexThrowsException)
{
	LinkedList<int> list;
	ASSERT_THROW(list.addAt(5,7), IndexOutOfBoundException);
}

TEST(LinkedListTest, AccessingNonExistingIndexThrowsException)
{
	LinkedList<int> list;
	ASSERT_THROW(list.get(5), IndexOutOfBoundException);
}

TEST(LinkedListTest, canUpdateExistingElement)
{
	LinkedList<int> list;
	list.add(5);
	list.add(6);
	list.updateAt(0, 2);
	list.updateAt(1, 3);
	ASSERT_EQ(2, list.get(0));
	ASSERT_EQ(3, list.get(1));
}

TEST(LinkedListTest, UpdatingNonExistingIndexThrowsException)
{
	LinkedList<int> list;
	ASSERT_THROW(list.updateAt(5,7), IndexOutOfBoundException);
}

TEST(LinkedListTest, canGetSize)
{
	LinkedList<int> list;
	list.add(2);
	list.add(3);
	list.add(4);
	ASSERT_EQ((unsigned int)3, list.size());
}

TEST(LinkedListTest, canRemoveElementInSpecifiedIndex)
{
	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.removeAt(1);
	ASSERT_EQ(3, list.get(1));
}

TEST(LinkedListTest, removingNonExistingIndexThrowsException)
{
	LinkedList<int> list;
	ASSERT_THROW(list.removeAt(1), IndexOutOfBoundException);
}


TEST(LinkedListTest, canRemoveAllElements)
{
	LinkedList<int> list;
	list.add(2);
	list.add(3);
	list.add(4);
	list.empty();
	ASSERT_EQ((unsigned int)0, list.size());
}

TEST(LinkedListTest, canUseEqualOperator)
{
	LinkedList<int> list;
	for(int i = 0; i < 5; i++)
	{
		list.add(i);
	}

	LinkedList<int> list2 = list;
	for(int i = 0; i < 5; i++)
	{
		ASSERT_EQ(i, list2.get(i));
	}
}

TEST(LinkedListTest, canUseArrayIndexOperator)
{
	LinkedList<int> list;
	list.add(5);
	ASSERT_EQ(5, list[0]);
	list[0] = 6;
	ASSERT_EQ(6, list[0]);
}

//Implementation of a Doubly-linked list.
#include <iostream>

using namespace std;

template<class ItemType>
struct node
{
	ItemType info;
	node<ItemType>* next;
	node<ItemType>* prev;
};

template<class ItemType>
class DblLnkLst
{
private:
	node<ItemType> * ListData;
	int length;
	node<ItemType> * currentPos;
public:
	DblLnkLst();
	~DblLnkLst();
	void makeEmpty();
	bool isFull();
	int getLength();

	bool findItem(ItemType item );
	void putItem(ItemType item);
	void deleteItem(ItemType item);
	void resetList();
	ItemType getNextItem();
	void printList();
};

template<class ItemType>
DblLnkLst<ItemType>::DblLnkLst()
//Class constructor Initializes attributes
{
	length = 0;
	ListData = new node<ItemType>;
}

template<class ItemType>
DblLnkLst<ItemType>::~DblLnkLst()
{
	node<ItemType>* tempPtr;
	while (ListData != NULL)
	{
		tempPtr = ListData;
		ListData = ListData->next;
		delete tempPtr;
	}
}

template<class ItemType>
bool DblLnkLst<ItemType>::isFull()
//Returns true if there is no room for another node
// else returns false
{
	node<ItemType> * location;
	try
	{
		location = new node<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}

}

template<class ItemType>
int DblLnkLst<ItemType>::getLength()
// Number of items in the list is returned. 
{
	return length;
}

template<class ItemType>
void DblLnkLst<ItemType>::makeEmpty()
{
	node<ItemType>* tempPtr;
	while (ListData != NULL)
	{
		tempPtr = ListData;
		ListData = ListData->next;
		delete tempPtr;
	}
	length = 0;
}

template<class ItemType>
void DblLnkLst<ItemType>::putItem(ItemType item)
//Item added to the list and length incremented
{
	node<ItemType> * location; //Declare a pointer to a node
	//cout << "Check 1. " << item << endl;
	location = new node<ItemType>;//Get a new node
	location->info = item;//Store the item in the node
	//cout << "Check 2. " << item << endl;
	ListData->prev = location; // next fieldof the new node
	//cout << "Check 3. " << item << endl;
	location->next = ListData;//Store address of first node in the
	//cout << "Check 4. " << item << endl;
	ListData = location; //Store address of new node into the ListData
	//cout << "Check 5. " << location->info << endl;
	length++;
}

template<class ItemType>
bool DblLnkLst<ItemType>::findItem(ItemType item)
//You go through the list and if found return a copy otherwise item is returned.
{
	bool moreToSearch;
	node<ItemType> * location;
	location = ListData;
	bool found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->info)
		{
			found = true;
			item = location->info;
			break;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	return found;
}
template<class ItemType>
void DblLnkLst<ItemType>::deleteItem(ItemType item)
//An element in the list that has a key that matches item 
// is found and delete
{
	node<ItemType> * location;
	node<ItemType> * tempLocation;

	location = ListData;

	//Locate the node to be deleted
	if (item == location->info)
	{
		tempLocation = location;
		ListData = ListData->next;
	}
	else
	{
		while (item != (location->next->info))
			location = location->next;
		tempLocation = location->next;
		location->next->next->prev = location;
		location->next = (location->next)->next;
		
	}
	delete tempLocation;
	length--;

}

template<class ItemType>
void DblLnkLst<ItemType>::resetList()
{
	currentPos = NULL;
}

template<class ItemType>
ItemType DblLnkLst<ItemType>::getNextItem()
//A copy of the next item in the list is returned. 
//When the end of the list is reached currentPos is reset to begin
{
	if (currentPos == NULL)
		currentPos = ListData;
	else
		currentPos = currentPos->next;
	return currentPos->info;
}

template<class ItemType>
void DblLnkLst<ItemType>::printList()
//Prints info of each item in the same order as in the list
{
	int length;
	ItemType item;
	resetList();
	length = getLength();

	for (int i = 0; i < length; i++)
	{
		item = getNextItem();
		cout << item << " ";
	}
	cout << endl;

}










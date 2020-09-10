# DoublyLinkedList-StackArray
The implementation of a doubly linked list and two stacks as one array

1. Implementation of a doubly link list class called DblLnkLst and make sure that it has all the functions that a regular link list has such as:
  i)	Constructor
  ii)	Destructor
  iii)	FindItem // finds a given item in the list. Returns true if found. 
  iv)	PutItem // Inserts an item into a DblLinkList object
  v)	DeleteItem // Deletes an item from an already existing DblLinkList object
  vi)	PrintItem //Prints the info of all items in the list. 
  The struct Node which the list comprises of is given below. 
  Template<class ItemType>
  struct Node
  {
         ItemType info;
         Node<ItemType>* next;
         Node<ItemType>* prev;
  }


2. Two stacks of positive integers are needed, one containing elements with values less than or equal to 100 and the other containing elements with values larger than 100. The total number of elements in the small-value stack and the large-value stack combined is not more than 20 at any time, but we cannot predict how many are in each stack. (All of the elements could be in the small-value stack, they could be evenly divided, both stacks could be empty, and so on.) 
This is implemented using an array of size 41, where the maximum number of elements is set to 20. The array is divided into two parts, 
One for less than or equal to 100, one for values greater than 100. The 2 array-stacks have separate push, and pop, and print. 
But for simplicity, the print functions are public for individual stacks as well.

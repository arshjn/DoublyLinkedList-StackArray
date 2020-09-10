/*
Two stacks of positive integers are needed, one containing elements with values less than or equal to 100 and the other containing elements with values larger than 100. 
The total number of elements in the small-value stack and the large-value stack combined is not more than 20 at any time, but we cannot predict how many are in each stack. 
(All of the elements could be in the small-value stack, they could be evenly divided, both stacks could be empty, and so on.)
Both stacks are implemented in ONE array.
*/

#include <iostream>

using namespace std;

class doubleStack
{
	int* a;
	int nOfElements;
	int n1,n2;
	void push1(int);
	void push2(int);
	bool isFull();
public:
	doubleStack();
	~doubleStack();
	void push(int);
	int pop1();
	int pop2();
	void print1() const;
	void print2() const;
	void print() const;
};

doubleStack::doubleStack()
{
	a = new int[40]; 
	a[20] = -1;
	nOfElements = 0;
	n1 = 0;
	n2 = 21;
}

doubleStack::~doubleStack()
{
	delete a;
}

bool doubleStack::isFull()
{
	if (nOfElements >= 20)
		return true;
	return false;
}

void doubleStack::push(int x)
{
	if (isFull())
	{
		cout << "Error! Too many elements!\n";
		return;
	}
	nOfElements++;
	if (x > 100)
		push2(x);
	else
		push1(x);
}

void doubleStack::push1(int x)
{
	a[n1] = x;
	n1++;
}
void doubleStack::push2(int x)
{
	a[n2] = x;
	n2++;
}
int doubleStack::pop1()
{
	n1--;
	return a[n1+1];
}

int doubleStack::pop2()
{
	n2--;
	return a[n2 + 1];
}

void doubleStack::print1() const
{
	cout << "Stack 1: ";
	for (int i = 0; i < n1; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void doubleStack::print2() const
{
	cout << "Stack 2: ";
	for (int i = 21; i < n2; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void doubleStack::print() const
{
	print1();
	print2();
}
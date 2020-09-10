#include "DblLnkLst.h"
#include "StArray.h"

int main()
{

//Sample Values

	DblLnkLst <int> DblLst;
	DblLst.putItem(22); 
	DblLst.putItem(11); 
	DblLst.putItem(7);
	DblLst.putItem(33); 
	DblLst.putItem(15);

	DblLst.printList(); 
	DblLst.deleteItem(7);
	
	DblLst.printList(); 
	DblLst.putItem(99); 
	
	DblLst.printList(); 
	DblLst.deleteItem(99);
	DblLst.printList();

	doubleStack S1;
	S1.push(3);
	S1.push(103);
	S1.push(56);
	S1.push(230);
	S1.print();

	S1.push(4);
	S1.push(170);
	S1.push(97);
	S1.push(101);
	S1.push(100);
	S1.print();

	S1.pop1();
	S1.print();
	S1.push(99);
	S1.push(84);
	S1.print();
	S1.pop2();
	S1.print();
	S1.push(135);
	S1.print();

	return 0;
}
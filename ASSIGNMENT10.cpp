/*Simulation of pizza parlor: Pizza parlor accepting maximum M orders. Orders are served on a first come first served basis. Order once 
placed cannot be canceled. Write C++ program to simulate the system using simple queue or circular queue*/
#include<iostream>
using namespace std;
class QUE{
public:
#define max 50
int Queue[max];
int Front=-1;
int Rear =-1;
bool isEmpty()
{
	if(Rear==-1)
		return 1;
	else
		return 0;
}
bool isFull()
{
	if(Rear == max-1)
		return 1;
	else
		return 0;
}
bool Add(int o_no)
{
	if(Rear==-1)
 	{
 		Front=Rear=0;
 		Queue[Rear]=o_no;
 		return true;
	 }
	 else{
	 int pos=(Rear+1)%max;
	if(isFull())
	{
		cout <<"Palour is full"<<endl;
		return false;
	}
	else
		{
		 	Rear=pos;
		 	Queue[Rear]=o_no;
		 	return true;
		 }
	}
   }
void Delete()
{
	if(isEmpty())
		cout<<"Palour is empty.No order"<<endl;
	else
	 {
	 	cout<<"\n Order No. "<<Queue[Front]<<" is served.\n";
	 	if(Front==Rear) //only one order
	 	{
	 		Front=Rear=-1;
		 }
		 else
		 {
		 	Front=(Front+1)%max;
		 }
	 }
}
void display()
 {
 	int i=0;
 	if(Rear==-1)
 	{
 		cout<<"\nPalour is Empty.No orders.\n";
 		return;
	 }
	 else
	 {
	 	cout<<"Order placed are.:";
	 	for(i=Front;i!=Rear;i=((i+1)%max))
	 	{
	 		cout<<Queue[i]<<"  ";
		 }
		 cout<<Queue[Rear]<<endl;
	 }
 }
};

int main()
 {
 	QUE q;
 	int ch,o_no=0;
 	do{
	cout<<"Enter your choice"<<endl;
	cout<<"1.Place the order"<<endl;
	cout<<"2.Serve the order"<<endl;
	cout<<"3.Display the order"<<endl;
	cout<<"4.Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
	{
	o_no++;
	/*if(q.Add(o_no))
	{*/
		q.Add(o_no);
		cout<<"Your order is placed.Order number is : "<<o_no<<endl;
		q.display();
	/*}
	
	else
	{
		o_no--;
	}*/
	
	break;
	}
	case 2:
	{
	q.Delete();
	break;
	}
	case 3:
	{
	q.display();
	break;
	}
	case 4:
	{
	break;
	}
	default:
	{
	cout<<"Enter the correct choice"<<endl;
	}
	}
	}while(ch!=4);
	
	
return 0;
}

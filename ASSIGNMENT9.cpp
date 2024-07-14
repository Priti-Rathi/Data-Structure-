/*
Assignment 9:
Problem statement:String operations: A palindrome is a string of characters that's identical when read in forward and backward direction. Typically, punctuation, capitalization, and spaces are ignored. For example, "1.Poor Dan is in a droop!!" is a palindrome, as can be seen by examining the characters "poordanisinadroop" and observing that they are identical when read forward and backward directions. One way to check for a palindrome is to reverse the characters in the string and compare them with the original-in a palindrome, the sequence will be identical.
Write C++ program with functions using Standard Template Library (STL) stack-
1. To print original string followed by reversed string using stack
2 . To check whether given string is palindrome or not
*/
#include<iostream>
#include<cstring>
using namespace std;

class Stack
{
	public:
		string stack[20];
		int top;
		int maxsize;
	public:
		Stack()
		{
			top=-1;
			maxsize=20;
		}
		string gettop();
		string pop();
		void push(string value);
		int isEmpty();
		int isfull();
};

int Stack :: isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int Stack :: isfull()
{
	if(top==(maxsize-1))
		return 1;
	else
		return 0;
}

void Stack :: push(string value)
{
	if(!isfull())
	{
		top++;
		stack[top]=value;
	}
	else
	{
		cout<<"stack is full"<<endl;
	}
}

string Stack :: pop()
{
	string ch;
	if(!isEmpty())
	{
		ch=stack[top];
		top--;
	}
	else
	{
		cout<<"Stack is empty"<<endl;
	}
	return ch;
}

string Stack :: gettop()
{
	string ch;
	if(!isEmpty())
	{
		ch=stack[top];
	}
	else
	{
		cout<<"Stack is empty"<<endl;
	}		
	return ch;		
}			
			
int main()
{
	Stack s;
	int choice,ch;
	string str1,str2;
	do
	{
		cout << "Menu:"<<endl;
		cout << "1. Enter string" <<endl;
		cout << "2. Reverse string" <<endl;
		cout << "3. check palindrome" <<endl;
		cout << "4. Exit" <<endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the string";
				cin>>str1;
				s.push(str1);
				break;
			case 2:
				while(!s.isEmpty())
				{
					str2+=s.pop();
				}
				cout << "Rversed string:" << str2 <<endl;
				break;
			case 3:
				if(str1==str2)
				cout<<"String is palindrome";
				else
				cout<<"String is not a palindrome";
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "Invalid choice. Please try again." << endl; 
		}
		cout<<"\ndo you want to continue:(1 for yes,0 for no)?"<<endl;
		cin>>ch;
	}
	while(ch==1);
	return 0;
}

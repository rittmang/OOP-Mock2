#define MAX 10
#include <iostream>
using namespace std;

template<class T>
class Stack
{
	T arr[MAX];
	int top;

	public:
	T item;
	Stack()
	{
		top=-1;
		for(int i=0;i<MAX;i++)
		{
			arr[i]=NULL;
		}
	}
	void push(T data)
	{
		if(top==MAX-1)
		{
			cout<<"STACK OVERFLOW"<<endl;
		}

		else
		{
			arr[++top]=data;
		}
	}
	T pop()
	{
		if(top==-1)
		{
			cout<<"EMPTY STACK. CANNOT POP.\n\n\n\n";
			return NULL;
		}
		else
		{
			T data=arr[top];
			arr[top--]=NULL;
			cout<<"Element popped=";
			return data;
		}
	}
	void display()
	{
		if(top==-1){cout<<"EMPTY STACK\n\n\n\n";return;}
		for(int i=top;i>=0;i--)
		{
			cout<<"\n"<<arr[i]<<endl;
		}
	}
};
int main()
{	int choice;
	Stack<int> s;
	do{
	cout<<"\n------\nSTACK OPERATIONS"<<"1. Push(Enter)  2.Pop (Remove) 3.Display(current status) 4.Exit"<<endl;

	cin>>choice;

	switch(choice)
	{
		case 1: cout<<"\nEnter element to enter:\n";
						cin>>s.item;
						s.push(s.item);
						break;

		case 2:
						cout<<s.pop()<<endl;
						break;

		case 3: cout<<"\nDisplaying current status:\n";
						s.display();
						break;

		case 4: return 0;
	}
	}while(choice!=0);
	return 0;
}

/*

Name: Ritom Gupta
Class: S.Y. B.Tech
Division: D
Batch: D4
Roll: 203460
Sub: OOP
*/
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

class Item
{
	public:
	int item_code;
	string item_name;
	int quantity;
	float cost;


	void accept();
	void display();
	void show();
	void accept_between();

	const bool operator < (const Item&);



};

void Item::accept()
{
	cout<<"Inputting item details:\n";
	cout<<"Enter item code, item name, quantity, cost\n";
	cin>>item_code;
	cin.ignore();
	getline(cin,item_name);

	cin>>quantity;
	cin>>cost;
}

void Item::display()
{
	cout<<"---------------"<<endl;
	cout<<"Item Code:"<<item_code<<"\nItem Name:"<<item_name<<"\nQuantity:"<<quantity<<"\nCost:"<<cost<<endl;
	cout<<"---------------"<<endl;
}

Item I;
list<Item> l;
list<Item>::iterator it;

void Item::accept_between()
{
	cout<<"Enter position to insert item:"<<endl;
	int pos;
	cin>>pos;

	it=l.begin();
	for(int i=0;i<pos;i++)
	{
		it++;
	}
	I.accept();
	l.insert(it,I);
}

void Item::show()
{
	for(it=l.begin();it!=l.end();it++)
		it->display();
}

const bool Item::operator < (const Item &I)
{
	return item_code < I.item_code;
}


int main()
{
	int choice;

	do{

		cout<<"1. Add to Front  2. Add to Back  3. Add in between 4. Display List 5. Sort Items"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: I.accept();
				      l.push_front(I);
				      break;

			case 2: I.accept();
				      l.push_back(I);
				      break;

			case 3: I.accept_between();
				      break;

      case 4: I.show();
              break;

			case 5:l.sort();
				     I.show();
				     break;
		}
	}while(choice!=0);



	return 0;
}

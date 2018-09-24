#include <iostream>
#include <fstream>
using namespace std;

class Item
{
	private:
	int item_code;
	string item_name;
	int quantity;
	float cost;

	public:
	void input_item();
	void show_item();
	void create_item();
	void add_item();
	void display_item();
	void search_item();


};

void Item::input_item()
{
	cout<<"Inputting item details:\n";
	cout<<"Enter item code, item name, quantity, cost\n";
	cin>>item_code;
	cin.ignore();
	getline(cin,item_name);

	cin>>quantity;
	cin>>cost;
}

void Item::show_item()
{

	cout<<"Item Code:"<<item_code<<"\nItem Name:"<<item_name<<"\nQuantity:"<<quantity<<"\nCost:"<<cost<<endl;
}

void Item::create_item()
{

	Item i;
	fstream file;
	file.open("data.dat",ios::out | ios::binary);


	char ch;

	do
	{
		i.input_item();
		file.write((char *)&i, sizeof(i));
		cout<<"More? Yes='Y' No='N'";
		cin>>ch;

	}while(ch=='Y' || ch=='y');

	file.close();
}
void Item::add_item()
{

	Item i;
	fstream file;
	file.open("data.dat",ios::app | ios::binary);
	char ch;

	do
	{
		i.input_item();
		file.write((char *)&i, sizeof(i));
		cout<<"More? Yes='Y' No='N'";
		cin>>ch;

	}while(ch=='Y' || ch=='y');

	file.close();
}

void Item::display_item()
{

	Item i;
	fstream file;
	file.open("data.dat",ios::in|ios::binary);
	if(!file){cout<<"File failed";}
	else{

	while(file.read((char *)&i, sizeof(i)))
		{
			i.show_item();
		}}
	file.close();
}

void Item::search_item()
{
	Item i;
	int num;
	cout<<"Enter code to search:";
	cin>>num;
	fstream file;
	file.open("data.dat",ios::in | ios::binary);
	int found=0;
	while(file.read((char *)&i, sizeof(i)))
	{
		if(num==i.item_code)
		{	i.show_item();
			found=1;
			break;
		}

	}
	if(found==0)cout<<"Item not found....";
	file.close();
}


int main()
{
	Item i1;
	int choice;

	do
	{
	cout<<"0. Exit\t1. Create Items\t2. Add items\t3. Display items\t4. Search items\n";

	cin>>choice;
	switch(choice)
	{
	   case 1: {cout<<"Creating item...\n";
	   	    i1.create_item();
	   	    break;
	   	   }

	  case 2:{cout<<"Adding item...\n";
	   	    i1.add_item();
	   	    break;
	   	   }

	  case 3:{cout<<"Displaying item...\n";
	   	    i1.display_item();
	   	    break;
	   	   }
	  case 4:{cout<<"Searching item...\n";
	   	    i1.search_item();
	   	    break;
	   	   }
	}
	cout<<"-----------------------------------\n\n";
	}while(choice!=0);

	return 0;
}

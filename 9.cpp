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
	void update_item();


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
  cout<<"_____________________________________________"<<endl;
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

void Item::update_item()
{
	Item i;
	int num;
	cout<<"Enter object number to update:";
	cin>>num;
	fstream inoutfile;
  inoutfile.open("data.dat",ios::in|ios::out|ios::binary);
	int location=(num-1)*sizeof(i);

  if(inoutfile.eof())inoutfile.clear();

  inoutfile.seekp(location);
  
  i.input_item();

  inoutfile.write((char *)&i,sizeof(i))<<flush;

	inoutfile.close();
}


int main()
{
	Item i1;
	int choice;

	do
	{
	cout<<"0. Exit\t1. Create Items\t2. Add items\t3. Display items\t4. Update items\n";

	cin>>choice;
	switch(choice)
	{
	   case 1: {cout<<"Creating item...\n\n";
	   	    i1.create_item();
	   	    break;
	   	   }

	  case 2:{cout<<"Adding item...\n\n";
	   	    i1.add_item();
	   	    break;
	   	   }

	  case 3:{cout<<"Displaying item...\n\n";
	   	    i1.display_item();
	   	    break;
	   	   }
	  case 4:{cout<<"Update item...\n\n";
	   	    i1.update_item();
	   	    break;
	   	   }
	}
	cout<<"-------XXX------XXX------XXX----------\n\n";
	}while(choice!=0);

	return 0;
}

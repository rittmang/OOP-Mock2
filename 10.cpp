#include <iostream>
#include <fstream>
using namespace std;

class Item
{
	private:
	int item_code;
	char item_name[100];
	int quantity;
	float cost;

	public:
		Item()
		{
			item_code=0;//item_name"";
			quantity=0;cost=0.0;
		}
	void input_item();
	void show_item();
	void create_item();
	void add_item();
	void display_item();
	void delete_item();


};

void Item::input_item()
{
	cout<<"Inputting item details:\n";
	cout<<"Enter item code, item name, quantity, cost\n";
	cin>>item_code;
	cin.ignore();
	//getline(cin,item_name);
    cin>>item_name;
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

void Item::delete_item()
{
fstream inoutfilet;
	inoutfilet.open("temp.dat",ios::out|ios::binary);
	cout<<"In delete()";
	fstream inoutfile;

	Item i;
	int num;
	cout<<"Enter Item number to delete(starts on 1):"<<endl;
	cin>>num;


	inoutfile.open("data.dat",ios::in|ios::binary);


	int counter=1;


	while(inoutfile.read((char *)&i, sizeof(i)))
	{		cout<<"Writing in while to inoutfilet before target\n";
		if(counter!=num)
			{
				inoutfilet.write((char *)&i,sizeof(i))<<flush;
        counter++;
			}
		else{
		   counter++;}
	}

	inoutfile.close();
	remove("data.dat");
	inoutfilet.close();
  rename("temp.dat", "data.dat");

	inoutfile.close();
	inoutfilet.close();

}


int main()
{

	int choice;

	do
	{
	cout<<"0. Exit\t1. Create Items\t2. Add items\t3. Display items\t4. Delete items\n";
	Item i1;
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
	  case 4:{cout<<"Delete item...\n\n";
	   	    i1.delete_item();
	   	    break;
	   	   }
	}
	cout<<"-------XXX------XXX------XXX----------\n\n";
	}while(choice!=0);

	return 0;
}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
	private:
	int Student_code;
	string Student_name;
	int division;


	public:
	void input_Student();
	void show_Student();
	void create_Student();
	void add_Student();
	void display_Student();
	void search_Student();


};

void Student::input_Student()
{
	cout<<"Inputting Student details:\n";
	cout<<"Enter Student code, Student name, division,\n";
	cin>>Student_code;
	cin.ignore();
	getline(cin,Student_name);

	cin>>division;

}

void Student::show_Student()
{
  cout<<"_____________________________________________"<<endl;
	cout<<"Student Code:"<<Student_code<<"\nStudent Name:"<<Student_name<<"\ndivision:"<<division<<endl;
}

void Student::create_Student()
{

	Student i;
	fstream file;
	file.open("data.dat",ios::out | ios::binary);


	char ch;

	do
	{
		i.input_Student();
		file.write((char *)&i, sizeof(i));
		cout<<"More? Yes='Y' No='N'";
		cin>>ch;

	}while(ch=='Y' || ch=='y');

	file.close();
}
void Student::add_Student()
{

	Student i;
	fstream file;
	file.open("data.dat",ios::app | ios::binary);
	char ch;

	do
	{
		i.input_Student();
		file.write((char *)&i, sizeof(i));
		cout<<"More? Yes='Y' No='N'";
		cin>>ch;

	}while(ch=='Y' || ch=='y');

	file.close();
}

void Student::display_Student()
{

	Student i;
	fstream file;
	file.open("data.dat",ios::in|ios::binary);
	if(!file){cout<<"File failed";}
	else{

	while(file.read((char *)&i, sizeof(i)))
		{
			i.show_Student();
		}}
	file.close();
}

void Student::search_Student()
{
	Student i;
	int num;
	cout<<"Enter code to search:";
	cin>>num;
	fstream file;
	file.open("data.dat",ios::in | ios::binary);
  int found=0;
	while(file.read((char *)&i, sizeof(i)))
	{
		if(num==i.Student_code)
		{	i.show_Student();
      found=1;
			break;
		}
	}
  if(found==0)cout<<"Student not found";

	file.close();
}


int main()
{
	Student i1;
	int choice;

	do
	{
	cout<<"0. Exit\t1. Create Students\t2. Add Student\t3. Display Students\t4. Search Students\n";

	cin>>choice;
	switch(choice)
	{
	   case 1: {cout<<"Creating Student...\n";
	   	    i1.create_Student();
	   	    break;
	   	   }

	  case 2:{cout<<"Adding Student...\n";
	   	    i1.add_Student();
	   	    break;
	   	   }

	  case 3:{cout<<"Displaying Student...\n";
	   	    i1.display_Student();
	   	    break;
	   	   }
	  case 4:{cout<<"Searching Student...\n";
	   	    i1.search_Student();
	   	    break;
	   	   }
	}
	cout<<"-------XXX------XXX------XXX----------\n\n";
	}while(choice!=0);
  //remove("data.dat");
	return 0;
}

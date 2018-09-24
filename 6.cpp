#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

class Student
{
	public:
	int roll_no;
	string stud_name;
	int division;



	void accept();
	void display();
	void show();
	void accept_between();


	const bool operator == (const Student&);
	void search(int);


};

void Student::accept()
{
	cout<<"Inputting Student details:\n";
	cout<<"Enter Student code, Student name, division, cost\n";
	cin>>roll_no;
	cin.ignore();
	getline(cin,stud_name);

	cin>>division;

}

void Student::display()
{
	cout<<"---------------"<<endl;
	cout<<"Student Code:"<<roll_no<<"\nStudent Name:"<<stud_name<<"\ndivision:"<<division<<endl;
	cout<<"---------------"<<endl;
}

Student I;
list<Student> l;
list<Student>::iterator it;

void Student::accept_between()
{
	cout<<"Enter position to insert Student:"<<endl;
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

void Student::show()
{
	for(it=l.begin();it!=l.end();it++)
		it->display();
}
void Student::search(int num)
{
	I.roll_no=num;
	it=(find(l.begin(),l.end(),I));
	if(it!=l.end())
	{
		cout<<"Student exists"<<endl;
	}
	else
		cout<<"Student does not exist"<<endl;
}

const bool Student::operator == (const Student &I)
{
	return roll_no == I.roll_no;
}

int main()
{
	int choice;

	do{

		cout<<"1. Add to Front  2. Add to Back  3. Add in between  4.Display List  5. Search Student"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: I.accept();
				      l.push_front(I);
				      I.show();
				      break;

			case 2: I.accept();
				      l.push_back(I);
				      I.show();
				      break;

			case 3: I.accept_between();
				      I.show();
				      break;

			case 4: I.show();
				      break;

			case 5: cout<<"Enter Student code to search:";
				      int code;
				      cin>>code;
				      I.search(code);
				      break;
		}
	}while(choice!=0);
	return 0;
}

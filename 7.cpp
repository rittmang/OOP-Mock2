#include <iostream>
#include <string>
using namespace std;

class EmployeeE
{
	private:
	string name,city;
	int age;

	long id;
	double income;

	public:
	EmployeeE()
	{
		name=city="";
		int age=0;

		long id=0;
		double income=0.0;
	}
	EmployeeE(long idd,string n,string c,int a,double i)
	{

		name=n;
		city=c;
		age=a;
		id=idd;
		income=i;
	}

	void display()//display function
	{
		cout<<"\nID="<<id;
		cout<<"\nName="<<name;
		cout<<"\nAge="<<age;
		cout<<"\nIncome="<<income;
		cout<<"\nCity="<<city;

	}

};
int main()
{
	string n,c;int a;long id;double i;

	try{
		cout<<"Input Employee Id:";
		cin>>id;
		cin.ignore();
		cout<<"Input Name:";
		getline(cin,n);

		cout<<"Input Age:";
		cin>>a;
		if(a<20 || a>30)throw(a);//check age

		cout<<"Input Income:";
		cin>>i;
		if(i<25000 || i>50000)throw(i);//check income


		cout<<"Input City:";
		cin>>c;
		if(c!="pune" && c!="mumbai")throw(c);//check city


		EmployeeE e(id,n,c,a,i);
		e.display();
	}
	catch(int r)
	{
		cout<<"Age to be between 20 and 30 inclusive\n";
	}
	catch(double r)
	{
		cout<<"Income to be between 25000 and 50000\n";
	}
	catch(string r)
	{
		cout<<"City to be pune,mumbai\n";
	}


}//end of main()

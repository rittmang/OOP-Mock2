#include <iostream>
#include <string>
using namespace std;

class User
{
	private:
	string email,name,password;

	public:
	User()
	{
		email=name=password="";
	}
	User(string em,string n,string p)
	{
    email=em;
    name=n;
    password=p;
	}

	void display()//display function
	{
    cout<<"----------------------------";
		cout<<"\nName="<<name;
		cout<<"\nEmail="<<email;
		cout<<"\nPassword="<<password<<endl;
    cout<<"----------------------------"<<endl;
	}

};
bool EndsWith(const string& a, const string& b) {
    if (b.size() > a.size()) return false;
    return equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
}
int main()
{
	string e,n,p;

	try{

		cout<<"Input Name:";
		getline(cin,n);

    cout<<"Input email:";
		getline(cin,e);
    if(!EndsWith(e,"@mitwpu.com"))
    {
      cout<<"Email should end with '@mitwpu.com'";
      throw(e);
    }//check email

		cout<<"Input password: (same for all users)";
		getline(cin,p);
		if(p!="password")
    {
      cout<<"Password to be ****word"<<endl;
      throw(p);
    }//check income


		User u(e,n,p);
		u.display();
	}

	catch(string r)
	{
		cout<<"Exception occurred.\n";
	}


}//end of main()

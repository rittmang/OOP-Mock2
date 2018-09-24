#include<iostream>
using namespace std;

template<class T>

class MathCalc
{
  T a,b;
public:
  MathCalc()
  {
    a=0;b=0;
  }
  MathCalc(T x,T y)
  {
    a=x;
    b=y;
  }
  T add()
  {
    return a+b;
  }
  T sub()
  {
    return a-b;
  }
  T mul()
  {
    return a*b;
  }
  float divi()
  {
    return a/(float)b;
  }

};
int main()
{

  int x,y;
  cout<<"Enter 2 numbers:"<<endl;
  cin>>x>>y;
  MathCalc <int> m(x,y);
  cout<<"Addition="<<m.add()<<endl;
  cout<<"Subtraction="<<m.sub()<<endl;
  cout<<"Multiplication="<<m.mul()<<endl;
  cout<<"Division="<<m.divi()<<endl;
  return 0;
}

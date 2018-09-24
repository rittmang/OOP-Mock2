#include<iostream>
using namespace std;

template<class T>

class MaxMin
{
public:
  T x,y;
  T max()
  {
    return x>y?x:y;
  }
  T min()
  {
    return x<y?x:y;
  }
};
int main()
{
  MaxMin<int> m;
  cout<<"Enter 2 numbers:\n";

  cin>>m.x>>m.y;
  cout<<"Maximum of "<<m.x<<" and "<<m.y<<" is="<<m.max()<<endl;
  cout<<"Minimum of "<<m.x<<" and "<<m.y<<" is="<<m.min()<<endl;
  return 0;
}

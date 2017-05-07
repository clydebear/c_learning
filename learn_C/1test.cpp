#include <bits/stdc++.h>

using namespace std;
class base
{
protected:
  int a;
};

class derived:public base
{
  void fun1(derived &d){cout<<d.a<<endl;}//正确
  //void derived::fun2(base &b){cout<<b.a};//错误
};


int main(int argc, char const *argv[])
{

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int *p(new int (42));  //p指向动态内存

  auto q=p;  //p和q指向相同的内存

  delete p; //p和q均变为无效

  q=nullptr;  //指出p不再绑定到任何对象
  int a = 10;
  q = &a;
  cout<<*p<<endl;
  return 0;
}

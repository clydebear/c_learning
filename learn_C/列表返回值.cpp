//g++ -std=c++11 列表返回值.cpp
#include <bits/stdc++.h>
using namespace std;
std::vector<int> ret_vec()
{
  return {0,1,2};//这里要大括号
}
int main(int argc, char const *argv[]) {
  std::vector<int> v;
  v = ret_vec();
  vector<int>::iterator it;
  for(it = v.begin();it!=v.end();it++)
    cout<<*it<<endl;
  return 0;
}

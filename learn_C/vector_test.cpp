#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  //1初始化
  vector<int> vec1(10,1);//10个1
  vector<int> vec2{1,2,3,4,5,6,7,8,9,0};//相当于vec2={1,2,3,4,5,6,7,8,9,0}
  vector<vector<int> > vecvec1{vec1,vec2};
  vector<string> vecstr = {"a","b","c"};
  //区别一下
  vector<int> vec3(10,1);//构造初始化，10个1
  vector<int> vec4{10,1};//列表初始化，两个元素：10,1
  vector<string> vecstr2{10,"hi"};//当不能用列表初始化时，才考虑用构造初始化。10个hi

  //2push_back(元素),empty(),size();
  vector<int> vecint1;
  if(vecint1.empty())
  {
    cout<<"vecint1 is empty now～"<<endl;
  }
  for (size_t i = 0; i < 10; i++)
  {
    vecint1.push_back(i);
  }
  vecint1[2] = vecint1[3];//元素拷贝替换
  vecint1 = {0,9,8,7,6,5,4,3,2,1,2,2,2};//用列表替换所有的不管原来什么内容的操作
  if(!vecint1.empty())
  {
    cout<<"size of vecint1="<<vecint1.size()<<endl;//size_type   vector<int>::size_type 正确的类型书写方式
  }
  for(auto &i:vecint1)
  {
    i*=i;
  }

  for(auto i : vecint1)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  //3不能用下标去添加元素
  //4vector<T>::iterator  it
  vector<int> vecint2(vecint1);
  vector<int>::iterator it1;//可读写，，定义迭代器是什么类型的迭代器
  const vector<int> vecint3(vecint2); //容器3里面的元素是不可以改的
  vector<int>::const_iterator it2;//可读不可写
  auto num = vecint2.end() - vecint2.begin();
  cout<<"num = "<<num<<endl;
  sort(vecint2.begin(),vecint2.end());//排序
  for(it1 = vecint2.begin();it1!=vecint2.end();it1++)//迭代器的使用
  {
    cout<<*it1<<" ";
  }
  cout<<endl;

  for(it2 = vecint3.begin();it2!=vecint3.end();it2++)
  {
    cout<<*it2<<" ";
  }
  cout<<endl;
  return 0;
}

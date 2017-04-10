#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int useShuZu(int * arr)
{

  return 0;
}
void fun(int *P)
{
    cout<<"在函数中"<<sizeof(P)<<endl;
}
int main(int argc, char const *argv[])
{
  //1定义和初始化：维度必须是常量表达式，不允许拷贝和赋值，不存在引用 的数组
  constexpr unsigned int size1 = 19;//g++ -std=c++11 数组.cpp
  string bad1[size1] = {};//如果size1不是常量表达式就不能用于数组大小的声明
  char shuzu1[] ="123456789";
  string temp1 = shuzu1;
  cout<<sizeof(shuzu1)<<" "<<strlen(shuzu1)<<" "<<temp1.length()<<endl;//10 9 9
  /*错误做法
  int size2;
  cin>>size2;
  string bad2[size2];*/
  char * str = (char *)temp1.c_str();
  long * a ;
  cout<<str<<" :"<<strlen(str)<<sizeof(str)<<"  a ="<<sizeof(a)<<endl;//9 8 8(指针)


   int A[10];
   int* B=new int[10];
   cout<<"数组名"<<sizeof(A)<<endl;
   cout<<"指针"<<sizeof(B)<<endl;
   fun(A);
   /*输出
   数组名40
   指针8
   在函数中8
   */
  //多维数组
  int ia[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
  int (&row)[4] = ia[1];//把row绑定到ia第二个4元素数组上
  cout<<row[3]<<endl;
  for(int &i : row)
  {
    i++;
  }
  for(int i : row)
  {
    cout<<i<< " ";
  }
  return 0;
}

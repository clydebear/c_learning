#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  //1static_cast任何明确的类型转换，只要不包含底层const都可以使用static_cast。
  int j=14;
  int i = 4;
  double result = static_cast<double>(j)/i;//(double)
  cout<<result<<endl;
  //2const_cast只能改变运算对象的底层const,即只能改变常量属性，不能改变类型属性
  const char *pc;
  pc = "aaaa";
  char *p =const_cast<char*>(pc);//(char*)
  //p = "bbbb";
  cout<<p<<endl;
  return 0;
}

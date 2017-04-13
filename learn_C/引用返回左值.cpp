#include <bits/stdc++.h>
using namespace std;
char &get_val(string &str,string::size_type ix)
{
  return str[ix];
}
const string &get_longger_str(const string &str,const string &str1)//cconst 返回值就不能更改
{
  return str.size()>str1.size()?str:str1;
}
int main(int argc, char const *argv[]) {
  string s("a value");
  cout<<s<<endl;
  get_val(s,0) = 'A';
  cout<<s<<endl;
  cout<<get_longger_str("3aaa","4aaaa")<<endl;//这么用不管是调用函数还是返回结果都没有去拷贝而花费内存
  return 0;
}

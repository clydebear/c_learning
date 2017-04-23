//1初始化
//2输入输出
//3  empty和size
//4string相加
//5处理每个字符，基于范围的for
//6访问string单个字符两个方法：下标和迭代器（九）
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  //1初始化
  string s1 = "init1 space";//拷贝初始化length()=5,,string对象是一个‘容器’不用担心越界
  string s2("init2 space");//直接初始化。。。。这两种初始化可以加空格
  string s3(10,'c');//直接初始化
  //cin>>s1;//输入时string对象会自动忽略空格符等。当遇到空格符等停止
  //cin>>s2>>s3;
  cout<<s1<<" "<<s2<<" "<<s3<<endl;
  //2输入输出
  /*while(cin>>s1)//反复读取逐个输出
  {
    cout<<s1<<" ";
  }*/

  //3  empty和size
  /*string line;
  while(getline(cin,line))//读入一行，能读入空格，不包含换行符
  {
    if(!line.empty())//判断是否空
    {
      cout<<"line="<<line<<endl;
      string::size_type len = line.size();//与机器无关的类型，可以存放任何string对象的大小无符号整形
      cout<<"line的size="<<len<<"  line的length="<<line.length()<<"line的sizeof= " <<sizeof(line)<<endl;
    }
    int n=-1;
    if(line.size()<n)//这个结果会一直真，因为n会转换成一个较大的无符号值，所以如果用到size函数，尽量避免和int进行比较
    {
      cout<<"<-1"<<endl;
    }
  }*/

  //4string相加
  /*string ss = "hello";
  string ss2 = ",world~";
  string ss3 = ss+ss2+"!";//ss3="hello"+" world"+ss2;//是错误的，要确保两边都至少有一个string 类型,且不能把字面值直接相加。
  cout<<ss3<<endl;*/

  /*处理每个字符，基于范围的for
  string sss1;
  getline(cin,sss1);
  int space1 = 0;
  for(auto &c:sss1)  //g++ -std=c++11 -o test test.cpp
  {
     if('a'<=c&&c<='z')
     {
       c=c-32;
     }
     if(c == ' ')
     {
       space1++;
     }
  }
  cout<<sss1<<"space1="<<space1<<endl;*/

  //6访问string单个字符两个方法：下标和迭代器（九）
  string ssss1;
  getline(cin,ssss1);
  for(decltype(ssss1.size()) index =0;
      index!=ssss1.size();index++)//ssss1.size()返回的是size_type
  {
    if(index == 0&&(ssss1[index]>=97&&ssss1[index]<=122)&&ssss1[index]!=' ')
    {
      ssss1[index] = ssss1[index]-32;
    }
    if(ssss1[index] == ' ')//单词首字母大写
    {
      index++;
      if(ssss1[index]>=97&&ssss1[index]<=122)
      {
        ssss1[index] = ssss1[index] - 32;
      }
    }
  }
  cout<<ssss1;
  return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;
string::size_type countStr(string s,const string str)
{
  int count = 0;
  string::size_type pos = s.find(str);
  while(pos!=-1)
  {
    count++;
    pos = pos +str.size();
    pos = s.find(str,pos);
  }
  return count;
}
int main() {
  string s = "clydejiang is my English name";
  const char *cp = "i am clydejiang from fujian province!haha";
  string ss;
  string::size_type len_cp = sizeof(cp);//指针的sizeof~~
  ss.assign(cp,len_cp-4);//cp的前8-4个!!
  ss.erase();
  ss.assign(cp);
  cout<<"ss="<<ss<<endl;
  cout<<"s="<<s<<endl;
  cout<<"compare"<<ss.compare(s)<<endl;;
  const char *in1 = "hahai hahaamhaha 20 years old.";
  ss.insert(ss.size(),in1+4);//+4去haha
  ss.append(s);
  cout<<ss<<endl;
  //i am clydejiang from fujian province!hahai hahaamhaha 20 years old.clydejiang is my English name
  cout<<"num of clyde = "<<countStr(ss, "clyde")<<endl;
  string::size_type pos = ss.find("clyde");
  while(pos!=-1)
  {
    ss.replace(pos,5,"ShuXiong");//clyde改为shuxiong
    pos = ss.find("clyde");
  }
  string::size_type pos1 = ss.find("jiang");
  while(pos1!=-1)
  {
    ss[pos1] = toupper(ss[pos1]);//jiang 变Jiang
    pos1 = ss.find("jiang");
  }
  string::size_type pos3 = ss.find("haha");
  while(pos3!=-1)
  {
    ss.erase(pos3,4);//去haha
    pos3 = ss.find("haha");
  }
  cout<<ss<<endl;
  return 0;
}
ss=i am clydejiang from fujian province!haha
s=clydejiang is my English name
compare6
i am clydejiang from fujian province!hahai hahaamhaha 20 years old.clydejiang is my English name
num of clyde = 2
i am ShuXiongJiang from fujian province!i am 20 years old.ShuXiongJiang is my English name
*/

## string
### 标准库类型string
\#include <string>  
using std::string;  
### 定义和初始化string对象
string s1；  //默认初始化，s1是一个空字符串  
string s2=s1；  //s2是s1的副本  
string s3=“hiya”；  //s3是该字符串字面值的副本  
string s4(10,'c');   //s4的内容是cccccccccc

string s5=”hiya“；　　//拷贝初始化  
string s6（”hiya“）；　　//直接初始化  
string s7（10，‘c'）；　　//直接初始化，s7的内容是cccccccccc
### string对象上的操作

|string 的操作| 说明 |
|---|---|
|os<<s　　|将s写到输出流os当中，返回os|  
|is>>s　　|从is中读取字符赋给s，字符串以空白分割|  
|getline（is，s） |从is这读取一行赋给，返回is|  
|s.empty（）　　|s为空返回true，否则返回false|  
|s.size（） 　|返回s中字符的个数|  
|s[n]　　　　|返回s这第n个字符的引用，位置n从0开始|
|s1+s2　　　|返回s1和s2连接后的结果|
|s1=s2　　　|用s2的副本代替s1中原来的字符
|s1！=s2　　|等性判断对字母的大小写敏感
|<,<=,>,>=　|利用字符在字典中的顺序进行比较，且对字母的大小写敏感

### 使用getline读取一整行
有时候我们希望能在最终**得到的字符串中保留输入时的空白**，这时应该使用getline函数代替原来的>>运算符
<font color=#0099ff>注意：触发getline函数返回的那个换行符实际上被丢弃掉了，得到的string对象中并不包含该换行符。</font>  
### 处理string对象中的字符

|cctype头文件中的函数|
|:-----------------------------|
|isalnum(c)　　　　　　　　当c是字母或数字时为真|  
|isalpha(c)　　　　　　　　 当c是字母时为真|
|iscntrl(c)　　　　　　　　　当c是控制字符时为真|
|isdigit(c)　　　　　　　　　当c是数字时为真|
|isgraph(c)　　　　　　　　当c不是空格但可打印时为真|
|islower(c)　　　　　　　　 当c是小写字母时为真
|isprint(c)　　　　　　　　　当c是可打印字符时为真（即c是空格或c具有可视形式）
|ispunch(c)　　　　　　　　当c是标点符号时为真(即c不是控制字符、数字、字符，可打印空白中的一种）|
|isspace(c)　　　　　　　　 当c是空白时为真（即c是空格、横向制表符、纵向制表符、回车符、换行符、进纸符中的一种）
|isupper(c)　　　　　　　　 当c是大写字母时为真
|isxdigit(c)　　　　　　　　  当c是十六进制数字时为真
|tolower(c)　　　　　　　　 如果c是大写字母，输出对应的小写字母：否则原样输出c
|toupper(c)　　　　　　　　 如果c是小写字母，输出对应的大写字母：否则原样输出c
|string s(cp,n) 　　　 　s是cp指向的数组中的第n个字符的拷贝，此数组至少应该包含n个字符
|string s(s2,pos2)　　   s是string s2从下标pos2开始的字符的拷贝。若pos2>s2.size(),构造函数的行为未定义
|string s(s2,pos2,len2)    s是string s2从下标pos2开始len2个字符的拷贝。若pos2>s2.size()，构造函数的行为未定义。不管len2的值是多少，构造函数至多拷贝s2.size()-pos2个字符|


```c
const char *cp="Hello World!";   //以空字符结束的数组
char noNull[]={'H','i'};            //不是以空字符结束
string s1(cp);                //拷贝cp中的字符直到遇到空字符
string s2(noNull,2);       //从noNull拷贝两个字符
string s3(noNull);    //未定义：noNull不是以空字符结束
string s4(cp+6,5);  //从cp[6]开始拷贝5个字符
string s5(s1,6,5);  //从s1[6]开始拷贝5个字符
string s6(s1,6);   //从s1[6]开始直到s1的末尾
string s7(s1,6,20); //正确，只拷贝到s1的末尾
string s8(s1,16);   //抛出一个out_of_range异常
```
>  <font color=#0099ff >通常当我们从一个const char*创建string时，指针指向的数组必须以空字符结尾</font>  
>

### substr操作
|子字符串的操作|
|:---:|
  |s.substr(pos,n)　　返回一个string，包含s中从pos开始的n个字符的拷贝。pos的默认值为0。n的默认的s.size()-pos，即拷贝从pos开始的所以字符|

substr操作返回一个string，它是原始string的一部分或全部的拷贝。可以传递给substr一个可选的<font color=#0099ff>开始位置和计数值：</font>  
string s("hello world");   
string s2=s.substr(0,5);  //s2=hello
string s3=s.substr(6);   //s3=world
string s4=s.substr(6,11);  //s4=world
string s5=s.substr(12);   //抛出一个out_of_range异常

### 改变string的其他方法
s.insert(s.size(),5,'!'); //在s末尾插入5个感叹号

s.erase(s.size()-5,5);  //从s删除最后5个字符

const char \*cp="Stately,plump Buck";

s.assign(cp,7);  //s="Stately"

s.insert(s.size(),cp+7); //s=="Stately,plump Buck"

string s="some string",s2="some other string";

s.insert(0,s2);  //在s中位置0之前插入s2的拷贝

//在s[0]之前插入s2中开始的s2.size()个字符

s.insert(0,s2,0,s2.size());

|修改string的操作|
|:---|
|s.insert(pos,args)　　　　在pos之前插入args指定的字符，pos可以是一个下标或者一个迭代器。接受下标的版本返回一个指向s的引用；接受迭代器的版本返回指向第一个插入字符的迭代器|
|s.erase(pos,len)　　　　  删除从位置pos开始的len个字符。如果len被省略，则删除从pos开始直至s末尾的所有字符。返回一个指向s的引用|
|s.assign(args)　　　　　  将s中的字符替换为args指定的字符。返回一个指向s的引用|
|s.append(args)　　　　　将args追加到s。返回以指向s的引用|
|s.replace(range,args)     删除s中范围range内的字符，替换为args指定的字符。range或者是一个下标和一个长度，或者是一对指向s的迭代器，返回一个指向s的引用|
|args可以是下列形式之一：
|append和assign可以使用所有形式：str不能与s相同，迭代器b和e不能指向s
|str 　　　　　　　　　　　字符串str
|str,pos,len　　　　　　　str中从pos开始最多len个字符
|cp,len　　　　　　　　　 从cp指向的字符数组的前（最多）len个字符
|cp　　　　　　　　　　　cp指向的以空字符串结尾的字符数组
|n,c　　　　　　　　　　  n个字符c
|b,e　　　　　　　　　　 迭代器b和e指定的范围内的字符
|初始化列表　　　　　　　花括号包围，以逗号分隔的字符列表
|replace和insert所允许的args形式依赖于range和pos是如何指定的
|replace　　  　　  replace　　　　insert　　　　   insert　　　　　args可以是
|(pos,len,args) 　 (b,e,args)　　　(pos,args)　 　　(iter,args)
|是　　　　　　　是　　　　　　　是　　　　　否　　　　　　str
|是　　　　　　　否　　　　　　　是　　　　　否　　　　　str,pos,len
|是　　　　　　　是　　　　　　　是　　　　　否　　　　　cp,len
|是　　　　　　　是　　　　　　　否　　　　　否　　　　　cp
|是　　　　　　　是　　　　　　　是　　　　　是　　　　　n,c
|否　　　　　　　是　　　　　　　否　　　　　是　　　　　b2,e2
|否　　　　　　　是　　　　　　　否　　　　　是　　　　　初始化列表

assign和append函数无须指定要替换string中哪个部分：assign总是替换string中的所有内容，append总是将新字符追加到string末尾。

replace函数提供了两种指定删除元素范围的方式。可以通过一个位置和一个长度来指定范围，也可以通过一个迭代器范围来指定。insert函数允许我们用两种方式指定插入点：用一个下标或一个迭代器。在两种情况下，新元素都会插入到给定下标（或迭代器）之前的位置。  

可以用好几种方式指定要添加到string中的字符。新字符可以来自于另一个string，来自于一个字符指针（指向的字符数组），来自于一个花括号包围的字符列表，或者一个字符和一个计数值。当字符来自于一个string或一个字符指针时，我们可以传递一个额外的参数来控制是拷贝部分还是全部字符。

并不是每个函数都支持所有形式的参数。例如，insert就不支持下标和初始化列表的参数。类似的，如果我们希望用迭代器指定插入点，就不能用字符指针指定新字符的来源
### string搜索操作
string类提供了6个不同的搜索函数，每个函数都有4个重载版本。  
下表描述了这些搜索成员函数及其参数。每个搜索操作都返回一个string::size_type值，表示匹配发生位置的下标。如果搜索失败，返回一个名为string::npos的static成员。标准库将npos定义为一个const string::size_type类型，并初始化为值-1。由于npos是一个unsigned类型，此初始化值意味着npos等于任何string最大的可能大小。

find函数完成最简单的搜索。它查找参数指定的字符串，若找到，则返回第一个匹配位置的下标，否则返回npos：
string name("AnnaBelle");

auto pos1=name.find("Anna");  //pos1==0

这段程序返回0，即子字符串"Anna"在"AnnaBelle"中第一次出现的下标
搜索（以及其他string操作）是大小写敏感的。当在string中查找子字符串时，要注意大小写。

一个更复杂的问题是查找与给定字符串中任何一个字符匹配的位置。例如，下面代码定位name中的第一个数字：

string numbers("0123456789"),name("r2d2");

//返回1，即，name中第一个数字的下标

auto pos=name.find_first_of(numbers);

如果是要搜索第一个不在参数中的字符，我们应该调用find_first_not_of，例如，为了搜索一个string中第一个非数字字符，可以这样做：

string dept("03714p3");

//返回5，字符'p'的下标

auto pos=dept.find_first_not_of(numbers);  

|string 搜索操作|
|:---|
|搜索操作返回指定字符出现的下标，如果未找到则返回npos
|s.find(args)　　　　　　　　　　查找s中args第一次出现的位置
|s.rfind(args)　　　　　　　　　 查找s中args最后一次出现的位置
|s.find_first_of(args)　 　　　　在s中查找args中任何一个字符第一次出现的位置
|s.find_last_of(args)    　　　　在s中查找args中任何一个字符最后一次出现的位置
|s.find_first_not_of(args)　　  在s中查找第一个不存在args 中的字符
|s.find_last_not_of(args)　　　在s中查找最后一个不在args中的字符
|args必须是以下形式之一
|c,pos 　　　　　　　　　　　　从s中位置pos开始查找字符c，pos默认为0
|s2,pos　　　　　　　　　　　 从s中位置pos开始查找字符串s2，pos默认为0
|cp,pos　　　　　　　　　　　 从s中位置pos开始查找指针cp指向的空字符结尾的C风格字符串，pos默认为0
|cp,pos,n　　　　　　　　　　 从s中位置pos开始查找指针cp指向的数组的前n个字符。pos和n无默认值
### 例子
```c
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
  const char \*in1 = "hahai hahaamhaha 20 years old.";
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
/*i am clydejiang from fujian province!hahai hahaamhaha 20 years old.clydejiang is my English name
num of clyde = 2
i am ShuXiongJiang from fujian province!i am 20 years old.ShuXiongJiang is my English name*/

```
### compare函数
|s.compare的几种参数形式|
|---|
|s2　　　　　　　　　　　比较s和s2
|pos1,n1,s2　　　　　　 将s中从pos1开始的n1个字符与s2进行比较
|pos1,,n1,s2,pos2,n2    将s中从pos1开始的n1个字符与s2中从pos2开始的n2个字符进行比较
|cp　　　　　　　　　　　比较s与cp指向的以空字符结尾的字符数组
|pos1,n1,cp　　　　　　 将s中从pos1开始的n1个字符和cp指向的以空字符结尾的字符数组进行比较
|pos1,n1,cp,n2　　　　  将s中从pos开始的n1个字符与指针cp指向的地址开始的n2个字符进行比较
e.g
```c
string s = "clydejiang is my English name";
const char *cp = "i";
cout<<"compare="<<ss.compare(s)<<endl;//compare=6.i比c大6
```
### 数值转换 c++11
字符串中常常包含表示数值的字符。例如，我们用两个字符的string表示数值15——字符'1'后跟字符'5'。一般情况，一个数的字符表示不同于其数值。

新标准引入了多个函数，可以实现数值数据与标准库string之间的转换。

int i=42;

string s=to_string(i);  //将整数i转换为字符表示形式

double d=stod(d);     //将字符串s转换为浮点数

此例中我们调用to_string将42转换为对应的string形式，然后调用stod将此string转换为浮点值。

要转换为数值的string中第一非空白符必须是数值中可能出现的字符：

string s2="pi=3.14";

//转换s中以数字开始的第一个子串，结果d=3.14

d=stod(s2.substr(s2.find_first_of("+-.0123456789)));

在这个stod调用中，我们调用了find_first_of来获得s中第一个可能是数值的一部分的字符的位置。我们将s中从此位置开始的子串传递给stod。stod函数读取此参数，处理其中的字符，直至遇到不可能是数值的一部分的字符。然后它就将找到这个数值的字符串表示形式转换为对应的双精度浮点值。

|string和数值之间的转换|
|---|
|to_string(val)　　　　　　　　　　一组重载函数，返回数值val的string表示。val可以是任何算术类型。对每个浮点类型和int或更大的整型，都有相应版本的to_string。
|stoi(s,p,b)　　　　　　　　　　　　返回s的起始子串（表示整数内容）的数值。返回值类型是int。b表示转换所用的基数，默认值是10.p是size_t指针，用来保存s中第一个非数值字符的下标，p默认是0，即，函数不保存下标
|stol(s,p,b)　　　　　　　　　　　　long
|stoul(s,p,b)　　　　　　　　　　   unsigned long
|stoll(s,p,b) 　　　　　　　　　　  long long、
|stoull(s,p,b)　　　　　　　　　　  unsigned long long
|stof(s,p) 　　　　　　　　　　　　返回s的起始子串（表示浮点数内容）的数值，返回值类型分别是float参数p的作用与整数转换中相同
|stod(s,p)　　　　　　　　　　  double
|stold(s,p)　　　　　　　　　　  long double

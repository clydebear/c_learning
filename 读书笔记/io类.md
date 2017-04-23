## IO类
### 头文件  
- iostream :定义了读写流的基本类型  
istream wistream从流读数据  
ostream wostream从流写数据  
iostream wiostream读写流
- fstream : 定义了读写命名文件的类型  
ifstream wifstream从文件读取数据  
ofstream wofstream 向文件写入数据  
fstream wfstream 读写文件
- sstream : 定义了读写内存string对象的类型  
istringstream wistringstream 从string读取数据  
ostringstream wostringstream 向string写入数据  
stringstream wstringstream读写string  

### IO对象无拷贝和赋值
ofstream out1 ,out2;
out1 = out2;//错误无拷贝无赋值  
### 条件状态  
IO库中定义了iostate类型，表示流的状态。其中badbit流已经崩溃，failbit表示操作失败，eofbit表示流到达了文件结束，googbit表示流没有错误。定义了四个函数返回流的状态。bad(),fail(),eof(),good()，good默认为0。

如果遇到系统级错误，不可读写后，流的badbit置位。如果读取到一个错误的字符failbit置位，如果文件结束eofbit，failbit都会置位。如果badbit，eofbit，failbit中有一个置位的话检测流的条件会返回0。
### 输出缓冲区
每个输出流都管理一个输出缓冲区，来保护程度读写数据。将多个输出操作合并成一个。

将缓冲区刷新：程序结束，缓冲区满，关联输入和输出中需要输入时，endl = 刷新+换行，flush=刷新，ends=空格+刷新。

  unibuf操作符，之后的输出都立即刷新，直到nounibuf。
### 文件输入输出
ifstream fcin;//定义一个文件输入流  
ifstream fcin(s);//打开文件s  
ifstream fcin(s,mod);//以mod文件模式打开s  
fcin.open(s);//fcin流打开文件s  
fcin.close();//fcin关闭文件fstream  

**函数：open（）**  
```c
void open ( const char * filename,  
            ios_base::openmode mode = ios_base::in | ios_base::out );  

void open(const wchar_t * _Filename,  
        ios_base::openmode mode= ios_base::in | ios_base::out,  
        int prot = ios_base::_Openprot);
```
参数：  
filename   操作文件名  
mode        打开文件的方式  
prot         打开文件的属性    //基本很少用到  
文件模式：  
in以读的方式打开  
out以写的方式打开(仅设out会清空文件)  
app每次写操作都写到文件末尾  
ate打开文件后直接到文件末尾  
trunc截断文件
binary以二进制的方式打开  
ifstream默认以in模式打开，ofstream以out打开，fstream以in和out打开。  
例子：  
```c
ifstream fi;
fi.open("./readfile.md",ios::app);//显示打开
string str;
fi>>str;//读的文件写到字符串中
cout<<str<<endl;
fi.close();
ofstream fo;
fo.open("./readfile.md",ios::app);
fo<<"fofofofo"<<endl;
fo.close();
fstream in;
in.open("readfile.md");
char buffer[256];
while (!in.eof() )
   {
       in.getline (buffer,100);
       cout << buffer << endl;
   }
```

### string流

例子：  
```c
#include <bits/stdc++.h>
using namespace std;
struct PersonInfo{
  string name;
  vector<string> phones;
};
int main() {
  string line,numbers;
  std::vector<PersonInfo> people;
  int i =0;
  while(getline(cin,line))
  {
    PersonInfo info;
    istringstream record(line);
    record>>info.name;
    while(record>>numbers)
    {
      info.phones.push_back(numbers);
    }
    people.push_back(info);
    i++;
    if (i==3) {
      /* code */
      break;
    }
  }
  vector<PersonInfo>::iterator it;
  for(it = people.begin();it!=people.end();it++)
  {
    cout<<(*it).name<<"  ";
    std::vector<string>::iterator itnum;
    for (itnum = (*it).phones.begin();itnum!=(*it).phones.end();itnum++ ) {
      cout<<(*itnum)<<" ";
    }
    cout<<endl;
  }

}
/*clyde 18080808 121024801842
wad 12312
adsaj 124124 124124d
clyde  18080808 121024801842
wad  12312
adsaj  124124 124124d*/

```

1.decltype(f()) sun=x;//sun的类型是函数f的返回类型

2.用到c++11标准，需要这样执行：：g++ **-std=c++11** stringtest.cpp

3.ASCII   48=‘0’  57=‘9’  65=‘A’  90 = 'Z'  97='a'  122='z'

4.#include<cctype>  包含很多对字符的操作：大写，是否空格等

5.size_t与机器有关的类型  size_type 与机器无关的类型

6.c++要用到c风格的字符串在cstring头文件中，包含后就可以使用一些操作函数。
const char * str = string1.c_str();
strlen(char * shuzu)  到'\0'之前结束

7.int * IP[4];//整形指针的数组
  int (* p)[4] = ia;//指向含有4个整数的数组

8.&位与 -- && 逻辑与
  |位或 -- || 逻辑或
  ～反  --  ！逻辑非

9.cout<<10<42 ;//先把10写到cout里，再count与42比较. 编译不通过

10.{}表示一个块，一个块就是一个作用域
  {
    int a=100;
  }
  int b=a;//这里使用a是未定义的

11.switch中的case标签，必须是常量表达式。
```c
int a =10;
int b=10;
switch('a')
{
  case 'a':
    cout<<b<<endl;
    break;
  default:
    cout<<"default"<<endl;
    break;
}
```

12.使用指针形参
```c++
void resetvalue1(int* ip)
{
  * ip = 0;//实参的值被改变了
}
void resetvalue2(int &i)
{
  i = 0;//改变了i所引用对象的值
}
void resetvalue3(const int &i)
{
  cout<<i<<endl;//无法改变了i所引用对象的值
}
int main()
{
  ...
  int a = 10;
  resetvalue1(&a);//
  resetvalue2(a);//在c++中尽量使用引用类型的形参替代指针
  resetvalue3(a);//当函数无需修改形参的值时，最好将其声明为常量引用
  ...
}
```


13.const 与指针
- 指向常量的指针：const int * ip = & i;
- const 指针：int * const ip = & i;
- 顶层const 表示指针本身是个常量
- 底层const 表示指针所指的对象是一个常量
- 重载时，形参用const int a和 int a 区别

14.尽量使用常量引用
```c
void reset1(const int &i)
{
  cout<<i<<endl;
}
int main()
{
  ...
  reset1(42);//这里就可以将常量，甚至字面值传入函数
  ...
}
eg.2
void reset2(string &str)//前提是不修改str下，用常量引用可以接受更多参数
{
  ...
}
int main()
{
  ...
  reset2("hello world");//这个传递是错误的，而把reset2的参数用const 修饰就可以解决这个问题，前提是不需要修改参数
  ...
}
```

15.vector 可以直接作为形参，也可以被引用。当不知道形参数量时，可以用vector替代.void testvetcor(std::vector<int> &v)

16.重载和形参：顶层const不算重载，底层const（指针和引用（强调指向））辨别了是否指向常量可以算作重载

17.assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行   没有#define NDEBUG

18.函数匹配国曾：候选函数->可行函数->最佳匹配
```c
void f();
void f(int);
void f(int,int);
void f(double,doble = 3.14)
f(5.6);//调用的是f(double,doble = 3.14)
```

19.编译器先变异成员再变异成员函数，所以无需在意成员出现的次序。

20.class 和struct定义类唯一的区别是：默认的访问权限
struct：定义在第一个访问说明符之前的成员是public的
class:定义在第一个访问说明符之前的成员的private的

21.友元：当非类成员对类成员没有访问权限的时候可以通过友元实现访问：在类的内部声明：**friend** 返回类型  函数名(参数列表);
> 虽然友元破坏的封装性，c++语言设计上是合理，给设计者提供了很大的弹性，2当B允许A访问，而不允许C。。D访问时就可用到，3举例Manager要访问item的私有成员就有用

22.注意构造函数初始化和赋值初始化的区别。一些const和引用是必须通过初始化而不能赋值的。直接初始化效率更高。
> 成员的初始化顺序和成员在类中出现的顺序有关，而与初始化列表的先后顺序无关。

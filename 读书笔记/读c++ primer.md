gcc4.8以后的版本都是支持c++11新特性的，只是需要在编译的时候设置-std的参数  

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
成员函数有this指针，而友元函数没有this指针  
友元函数是不能被继承的，就像父亲的朋友未必是儿子的朋友
> 虽然友元破坏的封装性，c++语言设计上是合理，给设计者提供了很大的弹性，2当B允许A访问，而不允许C。。D访问时就可用到，3举例Manager要访问item的私有成员就有用

22.注意构造函数初始化和赋值初始化的区别。一些const和引用是必须通过初始化而不能赋值的。直接初始化效率更高。  
构造函数不能被声明为const;创建一个类的const对象时，构造的过程是可以向其写值的，只有构造函数完成才能取得const属性
> 成员的初始化顺序和成员在类中出现的顺序有关，而与初始化列表的先后顺序无关。

23.关于构造函数：
对象是由“底层向上”开始构造的，当建立一个对象时，首先调用基类的构造函数
default 构造函数：默认构造函数 类名();
capy 构造函数：拷贝构造函数  类名(const 类名 & 对象名);
copy assignment操作符 ：赋值操作符   类名& = operator=(const 类名 & 对象名)
- 构造函数  
    1.构造函数不能有返回值  
    2.缺省构造函数时，系统将自动调用该缺省构造函数初始化对象，缺省构造函数会将所有数据成员都初始化为零或空  
    3.创建一个对象时，系统自动调用构造函数  
- 析构函数  
析构函数没有参数，也没有返回值。不能重载，也就是说，一个类中只可能定义一个析构函数

Widget();  
Widget(const Widget& rhs);  
Widget& operator=(Widget& rhs);  
Widget w1;//default 构造函数  
Widget w2(w1);//copy 构造函数（以值传递pass-by-value）  
w1 = w2;//copy assignment操作  
Widget w3 = w2;//copy构造函数！！原因是w3是新定义的，要先初始化，不能直接赋值了。

24.const对象只能访问const成员函数  
> 一个对象调用其成员函数时，它隐含的一个形参this指针  
 例如，我们定义了一个函数CTest::func1();实际上在编译器中该函数的定义就是CTest::func1(CTest* const this)，该this指针所指向的内容可以改变，但是该this指针不可以被改变。当我们用CTest的一个对象test1调用func1函数时即test1.func1()时，编译器就会将它解释为func1(&test1)，所以我们在func1中使用this指针就可以改变对象test1的成员变量了.  
 但是，当我们的对象是const对象时，即const CTest func1;这时候表示什么意思呢，func1的内容是不可以改边的，当我们把&func1作为一个参数传到形参this时，矛盾出现了：func1是一个常量，其成员不可以被改变；this指针的成员变量是可以改变的。如果我能正确的将func1 的地址传给this，那么tfunc1这个常量的值不是可以在this中被改变了吗，所以，编译器是不允许这种情况出现的，就提示错误了。故，const对象不能访问非const成员函数。  
 同理，当我们的成员函数是const成员函数时，例：CTest::func1() const,在编译器解释时会将该函数解释为CTest::func1(const CTest * const this),this指针及其所指向的内容都不可以被修改，前面提到的矛盾也就不存在了，所以const对象可以访问const成员变量   

 25.合成的构造函数只适合于非常简单的类  
 原因：  
 1）只有当类没有声明任何构造函数时，编译器才会自动合成默认构造函数  
 2）合成构造函数可能执行错误的操作  
 3）有时，编译器不能为某些类合成默认的构造函数，例如当一个类包含一个其他类类型的成员，且这个类没有默认的构造函数，那么编译器将无法初始化这个成员： Base()=default;  
 注意：在实际中，如果定义了其他构造函数，那么最好也提供一个默认构造函数
 ```c
 class Nodefault
 {
 public:
      Nodefault(const int &a){cout<<"Nodefault()"<<endl;}
      //Nodefault(const Base &d){cout<<"Nodefault"<<endl;}
      ~Nodefault(){cout<<"~Nodefault()"<<endl;}
 };
 struct A
 {
   Nodefault men;
 };

 int main(int argc, char* argv[])
 {
   A a;//错误的，不能合成默认的构造函数
   return 0;
 }
 ```
26.explicit声明的构造函数  
背景：因为通过实参的调用的构造函数：其参数类型会向类类型隐式转换  
隐式的类类型转换，其参数只能有一个，且为一步转换
```c
class aa
{
public:
  aa()=default;
  aa(const std::string &s):str(s){}
  std::string str;  
  aa &combine(aa &);
}
```
那么当执行  
string str1 = "111";
aa aa1;
aa1.combine(str1);//这里就隐式地将str转换为了aa  
注意：类类型转换只会自动执行一步类型转  
aa1.combine("111");//是错误的：“111”转成string,string再转成aa历经两步，另外类类型转换不是总有效的  
为了抑制类类型隐式转换，可以在构造函数前加上**explicit**参数修饰声明  
e.g::explicit aa(const std::string &s):str(s){}  
  aa1.combine(str1);//错误的，string的构造函数是explicit的  
**注意** ：当用explicit关键字声明构造函数时，它将只能以初始化的方式使用。  

27.1）类的静态成员  访问方式：类名**::** 静态成员  
static只在类的内部声明，类的外部就不能重复static关键字  
静态成员只与类本身有关而与类对象无关  
静态成员值改变，所以对象该成员的值都改变  
静态成员还可以作为默认实参，因为类外定义有初值了啊
e.g：银行的利率  
```c
class aa
{
public:
  static int aaa ;
  //若要类内初始化则声明为const constexpr：static const int aaa = 10;

};
int aa::aaa = 10;//理解：静态成员独立与对象需要定义，且在类外无需在用static声明
int main(int argc, char* argv[])
{

  aa a1;
  a1.aaa = 11;//需要定义后才能使用
  aa b1;
  cout<<a1.aaa<<endl;//11
  cout<<b1.aaa<<endl;//也是11
  return 0;
}
```
2）类的静态成员函数  
不与任何对象绑定  
不包含this指针，也不能使用this指针    


28.不完全类型  
只是**声明**了但未定义
```c
class aa
{
  ...
  aa a1;//错误,a1是不完全类型（只声明未定义）
  static aa a2;//正确，静态成员可以是不完全类型，（理解：因为类外需再定义）
  aa * a3;//正确，指针允许不完全类型，（理解，因为类外需要再开辟空间，在定义）
};

```
29.容器  
初始化：C c(b,e);c初始化为迭代器b与e之间的元素拷贝，但不包括e。  
note:当一个容器初始化为另外一个容器的拷贝时，两个容器类型，元素类型必须相同。或者可以用C c(b,e)去初始化  
容器swap(容器1，容器2);这个函数只是交换了两个容器内部数据结构，元素本身并未交换。(快)这个函数用于array和string要当心

30.函数的入栈顺序从右向左入栈的，计算顺序也是从右往左计算的，不过都是计算完以后在进行的压栈操作

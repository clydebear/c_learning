# 让自己习惯c++
## 01视c++为一个语言联邦
c++ 是多重范型变成语言，是支持过程，面向对象形式，函数形式，泛型形式，元编程形式的语言....
### C
- 区块
- 语句
- 预处理
- 内置数据类型
- 数组
- 指针
- 没有模板、异常、重载

### Obeject-Oriented C++
- classes(构造和析构)
- 封装
- 继承
- 多态
- virtual函数（动态绑定）

### Template C++
- 泛型编程

### STL
 template程序库
- 容器
- 迭代器
- 算法
- 函数对象
- 。。。

## 02尽量以const,enum,inline替换#define
(用编译器替换预处理)
> 对于单纯常量，最好以const对象或enum替换#define  
> 对于形似函数的宏，最好改用inline 函数替换#define   

原因：  
1. #define不能用来定义专属常量  
2. 不能够封装，定义在头文件内，编译过程都有效的。除非被#undef  
3. const码量可能更少  
4. #define记号未入记号表，编译器看不到
5. 获取const的初值是合法的，获取#define和enum的地址是不合法的  

## 03尽可能使用const
* **const出现在星号左边表示被指之物是常量；  
 如果出现在星号右边，表示指针自身是常量  
 如果出现在星号两边，表示被指之物和指针两者都是常量**
* **迭代器中的const**  
 ```c
 std::vector<int> v;
 for(int i = 0;i<10;i++)
 {
   v.push_back(i);
 }
 const std::vector<int>::iterator iter = v.begin();//iter的作用就像T * const(自身是常量)
 *iter = 10;//正确，改变iter所指物
 //++iter;    //错误！iter是const
 std::vector<int>::const_iterator cIter = v.begin();//cIter的作用像个const T *(被指之物是常量)
 //*cIter = 10;//错误*cIter是const
 ++cIter;//正确，改变cIter

 ```  

* **const作为函数返回值类型**  
**e.g**:  
const Rational operator*(const Rational& lhs,const Rational& rhs);//防止(a*b) = c;或者if(a*b = c)  
* **const成员函数**  
 1. 程序容易理解（哪些可以改，哪些不可以）
 2. 使利用pass-by-reference-to-const技术实现操作const对象成为可能(高效的原因？)
 3. const 成员函数不能给其他成员赋值,一定要赋值就要加上mutable关键字
 ```c
 void changconst() const
 {
    length = 20;
 }
  mutable int length =10;
 ```
 4. const和non_const成员函数有实质等价的实现时，令non_const版本调用const版本可避免代码重复

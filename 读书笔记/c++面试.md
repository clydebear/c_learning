http://blog.csdn.net/charles_r_chiu/article/details/47858885  
http://blog.csdn.net/charles_r_chiu/article/details/48227281  

 关于C++ const 的全面总结  
 http://blog.csdn.net/Eric_Jo/article/details/4138548  
1. 深拷贝与浅拷贝区别  
浅拷贝，即在定义一个类A，使用类似A obj;  A obj1(obj);或者A obj1 = obj; 时候，由于没有自定义拷贝构造函数，C++编译器自动会产生一个默认的拷贝构造函数。这个默认的拷贝构造函数采用的是“位拷贝”（浅拷贝），而非“值拷贝”（深拷贝）的方式，如果类中含有指针变量，默认的拷贝构造函数必定出错。
用一句简单的话来说就是浅拷贝，只是对指针的拷贝，拷贝后两个指针指向同一个内存空间，深拷贝不但对指针进行拷贝，而且对指针指向的内容进行拷贝，经深拷贝后的指针是指向两个不同地址的指针
2. 什么是虚函数？什么是纯虚函数？  
虚函数声明如下： virtual ReturnType   FunctionName(Parameter)；引入虚函数是为了动态绑定。   
纯虚函数声明如下：virtual ReturnType FunctionName()= 0；引入纯虚函数是为了派生接口。
3. 基类为什么需要虚析构函数？  
标准规定：当derived class经由一个base class指针被删除而该base class的析构函数为non-virtual时，将发生未定义行为。通常将发生资源泄漏。   
析构函数是以构造函数的逆序层层回调的.  
解决方法即为：为多态基类声明一个virtual 析构函数。
4. 在模板中，如何声明嵌套从属类型(即模板嵌套类型)？  
就需要再C::iterator之前加上typename，告诉编译器C::iterator是一个类型。  
5. auto_ptr能作为vector的元素吗？为什么？  
当复制一个auto_ptr时，它所指向的对象的所有权被交到复制的auto_ptr上面，而它自身将被设置为null。复制一个auto_ptr意味着改变它的值  
6. 如何初始化const和static数据成员？
通常在类外初始化static数据成员，但是 static const 的整型(bool，char，int，long)可以再类声明中初始化，
static const的其他类型也必须在类外初始化(包括整型的数组  
7. 如何确保对象在抛出异常时也能被删除？什么是RAII？  
的思想是RAII：设计一个class，令他的构造函数和析构函数分别获取和释放资源。即对象在构造是申请资源，销毁时释放资源  
有两个方法：  
1、利用“函数的局部对象无论函数以何种方式(包括因异常)结束都会被析构”这一特性，将“一定要释放的资源”放进局部对象的析构函数；   
2、使用智能指针。
8. 为什么需要private继承？  
1、public：只继承基类的接口。当继承是接口的一部分时，就选用public继承。  
2、private：只继承基类的实现。当继承是实现细节时，就选用private继承。  
3、protected：当继承是面向派生类而不是面向用户接口中的一部分时，就选用protected继承。  
9. 如果在构造函数和析构函数中抛出异常会发生什么？什么是栈展开？  
(1)、构造函数抛异常：不会发生资源泄漏。假设在operator new()时抛出异常，那么将会因异常而结束此次调用，内存分配失败，不可能存在内存泄露。假设在别处(operator new() )执行之后抛出异常，此时析构函数调用，已构造的对象将得以正确释放，且自动调用operator delete()释放内存   
析构函数抛异常：   
可以抛出异常，但该异常必须留在析构函数；若析构函数因异常退出，情况会很糟糕(all kinds of bad things are likely to happen)   
a、可能使得已分配的对象未能正常析构，造成内存泄露；   
b、例如在对像数组的析构时，如果对象的析构函数抛出异常，释放代码将引发未定义行为。考虑一个对象数组的中间部分在析构时抛出异常，它无法传播，因为传播的话将使得后续部分不能正常释放；它也无法吸收，因为这违反了”异常中立“原则(异常中立，就是指任何底层的异常都会抛出到上层，也就相当于是异常透明的)。   
(2)、抛出异常时，将暂停当前函数的执行，开始查找匹配的catch子句。首先检查throw本身是否在try块内部如果是，检查与该try相关的catch子句，看是否可以处理该异常。如果不能处理，就退出当前函数，并且释放当前函数的内存并销毁局部对象，继续到上层的调用函数中查找，直到找到一个可以处理该异常的catch。  
栈展开（stack unwinding）是指，如果在一个函数内部抛出异常，而此异常并未在该函数内部被捕捉，就将导致该函数的运行在抛出异常处结束，所有已经分配在栈上的局部变量都要被释放  
10. 如何在const成员函数中赋值  
使用mutable去掉const的成员函数的const性质  
const_cast和mutable的比较  
const_cast:  
1) 强制去掉对象的const属性。  
2) 缺点：对const对象，调用包含const_cast的const成员函数，属于未定义行为。  
mutable:  
1) 使用场景：对可能要发生变化的成员前，加上存储描述符mutable。  
2) 实质：对加了mutable的成员，无视所有const声明。
为什么要有这种去除常量标志的需求？  
答：两个概念：物理常量性和逻辑常量性  
物理常量性：实际上就是常量。  
逻辑常量性：对用户而言是常量，但在用户不能访问的细节上不是常量。
11. 两种常用的实现隐式类类型转换的方式是什么？如何避免隐式类型转换？  
(1)、  
a、使用单参数的构造函数或N个参数中有N-1个是默认参数的构造函数  
b、使用operator what_you_want_to_convert_type() const  
```c
class A
      {
      public:
              operator char*() const
              {
                  return data;//当从其他类型转换到char*时自动调用
              }
      private:
              char* data;
      };
```
在单参数的构造函数或N个参数中有N-1个是默认参数的构造函数声明之前加上explicit。  
12. STL中的vector：增减元素对迭代器的影响  
这个问题主要是针对连续内存容器和非连续内存容器。  
a、对于连续内存容器，如vector、deque等，增减元素均会使得当前之后的所有迭代器失效。因此，以删除元素为例：由于erase()总是指向被删除元素的下一个元素的有效迭代器，因此，可以利用该连续内存容器的成员erase()函数的返回值。常见的编程写法为：
```c
for(auto iter = myvec.begin(); iter != myvec.end())  //另外注意这里用 "!=" 而非 "<"
    {
        if(delete iter)
            iter = myvec.erase(iter);
        else ++iter;
    }
```
还有两种极端的情况是：
(1)、vector插入元素时位置过于靠前，导致需要后移的元素太多，因此vector增加元素建议使用push_back而非insert；  
(2)、当增加元素后整个vector的大小超过了预设，这时会导致vector重新分分配内存，效率极低。因此习惯的编程方法为：在声明了一个vector后，立即调用reserve函数，令vector可以动态扩容。通常vector是按照之前大小的2倍来增长的。  
b、对于非连续内存容器，如set、map等。增减元素只会使得当前迭代器无效。仍以删除元素为例，由于删除元素后，erase()返回的迭代器将是无效的迭代器。因此，需要在调用erase()之前，就使得迭代器指向删除元素的下一个元素。常见的编程写法为：  
```c
for(auto iter = myset.begin(); iter != myset.end())  //另外注意这里用 "!=" 而非 "<"
    {
        if(delete iter)
            myset.erase(iter++);  //使用一个后置自增就OK了
        else ++iter;
    }
```
13. New和malloc的区别
http://blog.csdn.net/zjc156m/article/details/16819357  
new可分为operator new(new 操作)、new operator(new 操作符)和placement new(定位 new)。其中operator new执行和malloc相同的任务，即分配内存，但对构造函数一无所知；而 new operator则调用operator new，分配内存后再调用对象构造函数进行对象的构造。   
其中operator new是可以重载的。placement new，就是operator new的一个重载版本，允许你在一个已经分配好的内存中构造一个新的对象。而网上对new说法，大多针对operator new而言，因此说new是带有类型的(以为调用了类的构造函数)，不过如果直接就说new是带有类型的话，明显是不合适的，比如原生的operator new。可以参考我的一个程序，这个程序是用代理模式实现一个自定义二维数组，在第二个维度拷贝构造的时候， 拷贝构造需要深拷贝(当然第一个维度也需要)，执行深拷贝时代码大致如下：

```c
class Array2D    //二维数组模板
    {
    private:
            size_t length2,length1; //数组各个维的大小
            Array1D<T>* data;
    }
    void* raw  =::operator new[](length2*sizeof(Array1D<T>));
    data = static_cast<Array1D<T>*>(raw);
```

可见执行operator new的时候申请的原生内存是可以不带有类型的。
1) malloc()分配指定字节数的未经初始化的内存空间，返回的是void指针；new操作符为一个指定类型的对象分配空能，并调用其构造函数初始化，返回的是该对象的指针。  
2) malloc()必须要做初始化，以及将void指针转换成合适类型的指针。同时要考虑到分配的内存大小正好是你所需要的大小。当new操作符使用”(value)” notation，即可得到值为value的初始化。如果考虑上初始化的开销，malloc()和new没有性能上的差别.  

14.C++如何避免内存泄漏  
这其实可以看做是一个编程风格的问题。  
a、使用RAII(Resource Acquisition Is Initialization,资源获取即初始化)技法，以构造函数获取资源(内存),析构函数释放。  
b、相比于使用原生指针，更建议使用智能指针，尤其是C++11标准化后的智能指针。  
c、注意delete和delete[]的使用方法。  
d、这是很复杂的一种情况，是关于类的copy constructor的。首先先介绍一些概念。  
同default constructor一样，标准保证，如果类作者没有为class声明一个copy constructor，那么编译器会在需要的时候产生出来(这也是一个常考点：问道”如果类作者未定义出default/copy constructor，编译器会自动产生一个吗？”答案是否定的)  
不过请注意！！这里编译器即使产生出来，也是为满足它的需求，而非类作者的需求！！  
而什么时候是编译器”需要”的时候呢？是在当这个class 【不表现出】bitwise copy semantics(位逐次拷贝，即浅拷贝)的时候。  
在4中情况下class【不表现出】bitwise copy semantics
(1)、当class内含一个member object且该member object声明了一个copy constructor(无论该copy ctor是类作者自己生明的还是编译器合成的)；  
(2)、当class继承自一个base class且该base class有一个copy constructor(无论该copy ctor是类作者自己生明的还是编译器合成的)；  
(3)、当class声明了virtual function；  
(4)、当class派生自一个继承链，且该链中存在virtual base class时。  
言归正传，如果class中仅仅是一些普通资源，那么default memberwise copy是完全够用的；然而，挡在该class中存在了一块动态分配的内存，并且在之后执行了bitwise copy semantics后，将会有一个按位拷贝的对象和原来class中的某个成员指向同一块heap空间，当执行它们的析构函数后，该内存将被释放两次，这是未定义的行为。因此，在必要的时候需要使用user-defined explicit copy constructor，来避免内存泄露.

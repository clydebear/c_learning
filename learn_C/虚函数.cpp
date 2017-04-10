
/*虚函数
非类的成员函数不能定义为虚函数，类的成员函数中静态成员函数和构造函数也不能定义为虚函数，但可以将析构函数定义为虚函数
优秀的程序员常常把基类的析构函数定义为虚函数。因为，将基类的析构函数定义为虚函数后，
当利用delete删除一个指向派生类定义的对象指针时，系统会调用相应的类的析构函数。
而不将析构函数定义为虚函数时，只调用基类的析构函数。
只需要在声明函数的类体中使用关键字“virtual”将函数声明为虚函数，而定义函数时不需要使用关键字“virtual”。
当将基类中的某一成员函数声明为虚函数后，派生类中的同名函数（函数名相同、参数列表完全一致、返回值类型相关）自动成为虚函数。
  函数重载的调用根据参数的个数、序列来确定，而虚函数依据对象确定
*/
#include<iostream>
#include <stdlib.h>
using namespace std;
class A{//虚函数示例代码2
    public:
      A(){};
        virtual void fun(){cout<<"A::fun"<<endl;}//虚函数实现多态:有virtual 指向B
        virtual void fun2(){cout<<"A::fun2"<<endl;}
        ~A(){};
};
class B : public A{
    public:
        void fun(){cout<<"B::fun"<<endl;}
        void fun2(){cout<<"B::fun2"<<endl;}
};//end//虚函数示例代码2
int main()
{
    void(A::*fun)();//定义一个函数指针
    A *p=new B;
    fun=&A::fun;
    (p->*fun)();
    fun=&A::fun2;
    (p->*fun)();
    delete p;
    system("pause");
    return 0;
}

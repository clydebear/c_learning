
#include <bits/stdc++.h>

using namespace std;
class Base
{
public:
     Base(){cout<<"Base()"<<endl;}
     ~Base(){cout<<"~Base()"<<endl;}
private:
    string str1;
    string str2;
};
class Derived:public Base
{
public:
    Derived(){cout<<"Derived()"<<endl;}
    ~Derived(){cout<<"~Derived()"<<endl;}
    bool retTrue() const
    {
        return true;
    }
    int getvalue()
    {
      return 2;
    }
private:
    string str1;
    string str2;
};
bool validateDerived(const Derived &d)
{
    //d.getvalue();错误的const对象只能调用const成员函数！！
    return d.retTrue();
}

int main(int argc, char* argv[])
{
    const Derived d;
    d.retTrue();
    validateDerived(d);
    cout<<"after func"<<endl;
    //system("pause");
    return 0;
}
/*
Base()
Derived()
~Derived()//pass-by-value这里调用了拷贝构造函数，而拷贝构造函数在类中没有定义声明
~Base()//这里调用了拷贝构造函数，而拷贝构造函数在类中没有定义声明
after func
~Derived()
~Base()
*/

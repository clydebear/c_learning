
#include <bits/stdc++.h>

using namespace std;
class Base
{
public:
     Base(){cout<<"Base()"<<endl;}
     Base(const Base &d){cout<<"拷贝Base"<<endl;}
     ~Base(){cout<<"~Base()"<<endl;}
private:
    string str1;
    string str2;
};
class Derived:public Base
{
public:
    Derived(){cout<<"Derived()"<<endl;}
    Derived(Derived & b){cout<<"拷贝Derived"<<endl;}
    ~Derived(){cout<<"~Derived()"<<endl;}
    bool retTrue()
    {
        return true;
    }
private:
    string str1;
    string str2;
};
bool validateDerived(Derived d)
{
    return d.retTrue();
}

int main(int argc, char* argv[])
{
    Derived d;
    cout<<"after d"<<endl;
    validateDerived(d);
    cout<<"after func"<<endl;
    //system("pause");
    return 0;
}
/*
Base()
Derived()
after d
Base()//这里调用的不是拷贝构造函数!!
拷贝Derived
~Derived()
~Base()
after func
~Derived()
~Base()
*/

#include <iostream>
using namespace std;
//析构函数的调用顺序与构造函数是相反的
class A {
public:
    A() {
        cout << "A()" << endl;
    }
    virtual ~A() {
        cout << "~A()" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "B()" << endl;
    }
    ~B() {
        cout << "~B()" << endl;
    }
};

class C : public B {
public:
    C() {
        cout << "C()" << endl;
    }
    ~C() {
        cout << "~C()" << endl;
    }
};

class D : public C {
public:
    D() {
        cout << "D()" << endl;
    }
    ~D() {
        cout << "~D()" << endl;
    }
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    return 0;
}
/*
A()
A()
B()
A()
B()
C()
A()

B()
C()
D()
~D()
~C()
~B()
~A()
~C()
~B()
~A()
~B()
~A()
~A()
*/

## 1.static_cast

最常用的类型转换符，在正常状况下的类型转换，如把int转换为float，如：int i；float f； f=（float）i；或者f=static_cast<float>(i);

## 2.const_cast
用于取出const属性，把const类型的指针变为非const类型的指针，如：const int * fun(int x,int y){}　　
   int * ptr=const_cast<int * >(fun(2.3))

## 3.dynamic_cast

该操作符用于运行时检查该转换是否类型安全，但只在多态类型时合法，即该类至少具有一个虚拟方法。dynamic_cast与static_cast具有相同的基本语法，dynamic_cast主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换。在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全。如：
```
class C
{
　　//…C没有虚拟函数
}；
class T{
　　//…
}
int main()
{
　　dynamic_cast<T*> (new C);//错误
}
此时如改为以下则是合法的：
class C

{
public:
　　virtual void m() {};// C现在是 多态
}
```


## 4.reinterpret_cast

interpret是解释的意思，reinterpret即为重新解释，此标识符的意思即为数据的二进制形式重新解释，但是不改变其值。  
如：int i; char *ptr="hello freind!";  
 i=reinterpret_cast<int>(ptr);  
 这个转换方式很少使用。

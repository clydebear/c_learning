#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
namespace aa
{
  int a =100;
}
namespace bb
{
  int a = 100;
}
int main()
{
    using namespace aa;
    //using namespace bb;
    int b=a;
    cout<<b<<endl;
    return 0;
}

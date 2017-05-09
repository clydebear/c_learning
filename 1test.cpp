#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

/*

default_random_engine e;
for(size_t i =0;i<2;i++)
{
  cout<<e()<<" ";
}
*/
int main(int argc, char const *argv[])
{
    static uniform_real_distribution<double> u(0,1);
    static default_random_engine e(time(0));
    cout<<e.min()<<" "<<e.max()<<endl;
    for(size_t i =0;i<20;i++)
    {
      cout<<fixed<<setprecision(2)<<u(e)<<" ";
    }
    cout<<endl;
    sleep(1);
    default_random_engine e1(time(0));
    for(size_t i =0;i<20;i++)
    {
      cout<<u(e1)<<" ";
    }
    return 0;
}

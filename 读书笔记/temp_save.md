```c
#include <bits/stdc++.h>
using namespace std;
int tX[51];
int tY[51];
int ads1(int a)
{
  if(a<0)
     return -a;
  return a;
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
      cin>>tX[i];
    }
    for(int i = 0;i<n;i++)
    {
      cin>>tY[i];
    }
    int gx,gy;
    cin>>gx>>gy;
    int walkTime,taxiTime;
    cin>>walkTime>>taxiTime;
    if(walkTime<taxiTime)
    {
         cout<<(ads1(gx)+ads1(gy))*walkTime<<endl;
         return 0;
    }
    int walkcost = (ads1(tX[0])+ads1(tY[0]))*walkTime;
    int taxicost = (ads1(gx-tX[0])+ads1(gy-tY[0]))*taxiTime;
    int temp1 = walkcost+taxicost;
    int x=tX[0],y=tY[0];
    for(int j = 0;j<n;j++)
    {
         int temp = (ads1(tX[j])+ads1(tY[j]))*walkTime+(ads1(gx-tX[j])+ads1(gy-tY[j]))*taxiTime;
         //int temp2 = ads1(gx-tX[j])+ads1(gy-tY[j]);
         if(temp1>temp)
         {
              temp1 = temp;
              x = tX[j];
              y = tY[j];
         }

    }
    cout<<temp1<<endl;
    return 0;
}

```


在幼儿园有n个小朋友排列为一个队伍，从左到右一个挨着一个编号为(0~n-1)。其中有一些是男生，有一些是女生，男生用'B'表示，女生用'G'表示。小朋友们都很顽皮，当一个男生挨着的是女生的时候就会发生矛盾。作为幼儿园的老师，你需要让男生挨着女生或者女生挨着男生的情况最少。你只能在原队形上进行调整，每次调整只能让相邻的两个小朋友交换位置，现在需要尽快完成队伍调整，你需要计算出最少需要调整多少次可以让上述情况最少。例如：
GGBBG -> GGBGB -> GGGBB
这样就使之前的两处男女相邻变为一处相邻，需要调整队形2次
输入描述:
输入数据包括一个长度为n且只包含G和B的字符串.n不超过50.


输出描述:
输出一个整数，表示最少需要的调整队伍的次数

输入例子:
GGBBG

输出例子:
2


```c
#include <bits/stdc++.h>

using namespace std;
void sol1(int &endgirl,string str)
{
  int len = str.length();
  int boynum = 0,girlnum = 0;
  for(int j = 0;j<len;j++)
  {
    if(str[j] == 'B')
    {
      boynum++;
    }
    if(str[j] == 'G')
    {
      girlnum++;
    }
  }
  //ENDGILR
  for(int k = 1;k<=girlnum;k++)
  {
    if(str[len-k] !='G')
    {
      for(int l = boynum-1;l>-1;l--)
      {
        if(str[l] == 'G')
        {
          endgirl = endgirl + len-k - l;
          char temp = str[l];
          str[l] = str[len-k];
          str[len-k] = temp;
          break;
        }
      }
    }
  }

}
void sol2(int &endboy,string str)
{
  int len = str.length();
  int boynum = 0,girlnum = 0;
  for(int j = 0;j<len;j++)
  {
    if(str[j] == 'B')
    {
      boynum++;
    }
    if(str[j] == 'G')
    {
      girlnum++;
    }
  }
  //ENDboy
  for(int k = 1;k<=boynum;k++)
  {
    if(str[len-k] !='B')
    {
      for(int l = girlnum-1;l>-1;l--)
      {
        if(str[l] == 'B')
        {
          endboy = endboy + len-k - l;
          char temp = str[l];
          str[l] = str[len-k];
          str[len-k] = temp;
          break;
        }
      }
    }
  }
}
int main()
{
    string str;
    cin>>str;
    int endgirl = 0;
    int endboy = 0;
    sol1(endgirl,str);
    sol2(endboy,str);
    if(endgirl>endboy)
        cout<<endboy<<endl;
    else
        cout<<endgirl<<endl;
    return 0;
}

```

```c
#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int maxsize = 51;
    int n;
    int sequence[maxsize];
    cin>>n;
    int tag = 0;
    for(int i=0;i<n;i++)
    {
      cin>>sequence[i];
    }
    int seqbak[maxsize] = {};
    for(int j = n-1;j>-1;j--)
        for(int l = 0;l<n;l++)
        {
          if(seqbak[l] == sequence[j])
          {
            break;
          }
          else if(l == n-1)
          {
            seqbak[tag] = sequence[j];
            tag++;
          }
        }
    for(int p=tag-1;p>0;p--)
    {
      cout<<seqbak[p]<<" ";
    }
    cout<<seqbak[0]<<endl;
    return 0;
}

```

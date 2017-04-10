#include <bits/stdc++.h>
using namespace std;
int dp[210000];
int n,arr[51];
int main()
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }//求出背包的总大小
    /*
    f[i][V] = max(f[i-1][V-v[i]]+v[i], f[i-1][V] )
    f[i][V]表示用前i个物体装容量为V的背包能够装下的最大值，
    f[i-1][V-v[i]]+v[i]表示第i个物体装进背包的情况，f[i-1][V]表示第i件物品不装进背包的情况。

    f[0][i]=0, f[j][0];
    for(int i=1; i<n; ++i)
    {
      for(j=1;j<SUM/2;++j)
      {
        f[i][j]=f[i-1][j];
        if(v[i]<=j && f[i-1][j-v[i]]+v[i] > f[i][j]);
        f[i][j]=f[i-1][j-v[i]]+v[i];
      }
    }
    最终差值就是SUM-2*f[n-1][SUM/2];

    for i=[weight[0],total]
        tab[n-1][i] = weight[0];    //    n为物品数量
    for i=[1,n)
        for j=[weight[i],total]
            tab[n-i-1][j] = max(tab[n-i][j-weight[i]]+value[i],tab[n-i][j])

    //完全背包：物品i有无数个
    for i=[0,n)
      for(j=weight[i]; j<=total; j++)
        tab[j] = max(tab[j-weight[i]]+value[i],tab[j])

    //多重背包：物品为有限个
    for i=[0,n)
       //将count数组清零
       for(j=weight[i]; j<=total; j++)
          if count[j-weight[i]]<amout[i]
              tab[j] = max(tab[j-weight[i]]+value[i],tab[j]);
              if    tab[j]=tab[j-weight[i]]+value[i]    //    决定放入i是较优解
                    count[i] = count[j-weight[i]] + 1
         else    if    tab[j]=0        //    防止装第1个物品和装其他物品的情况
             tab[j] = tab[j-1],count[j] = count[j-1]
        else    count[j] = count[j-1]
    print tab[0][total]
    */
    for(int i = 0 ; i < n ; i ++)
        for(int j = sum/2 ; j >= arr[i] ; --j)
        {
          dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);//dp[j]表示在容量为j的情况可存放的重量
        }

    printf("%d\n",(sum-dp[sum/2]));
    return 0;
}

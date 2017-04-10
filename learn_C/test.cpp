#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int maxsize = 51;
    int n,k;
    int mag_ring[maxsize];
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
      cin>>mag_ring[i];
    }
    int temp = mag_ring[0];
    while(k--)
    {
      for(int j = 0;j<n;j++)
      {
        if(j == n-1)
        {
          mag_ring[j] = mag_ring[j]+temp;
          if(mag_ring[j]>100)
             mag_ring[j] = mag_ring[j]%100;
        }
        else
        {
          if(j == 0)
            temp = mag_ring[0];
          mag_ring[j] = mag_ring[j]+mag_ring[j+1];
          if(mag_ring[j]>100)
             mag_ring[j] = mag_ring[j]%100;
        }
      }
    }
    for(int i=0;i<n-1;i++)
    {
      cout<<mag_ring[i]<<" ";
    }
    cout<<mag_ring[n-1]<<endl;
    return 0;
}

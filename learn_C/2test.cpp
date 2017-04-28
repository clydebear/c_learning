#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
{
    double final = 1;
    double moneynow = 0;
    vector<double> money;
    for(int i=0;i<n;i++)
    {
      for(int j =0;j<n;j++)
      {
        for(int k=0;k<m;k++)
        {
            moneynow=
        }
      }
    }
}
/******************************结束写代码******************************/


int main()
{
    int n = 0;
    int m = 0;
    double p = 0;
    cin >> n >> m >> p;

    vector<vector<double>> prices;
    for(int i = 0; i < m; ++i) {
        prices.push_back(vector<double>());
        for(int j = 0; j < n; ++j) {
            double x = 0;
            cin >> x;
            prices.back().push_back(x);
        }
    }

    double final = StockGod(n, m, p, prices);
    printf("%.1f\n", final);

    return 0;
}

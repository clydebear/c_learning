#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> vec={0,2,1,3,4,5,6,7,8,9};
  //从尾元素到首元素的反向迭代器
  for(auto r_iter=vec.crbegin();r_iter!=vec.crend();++r_iter)
    cout<<*r_iter<<" ";  //打印9，8，7，6，5，4，3，2，1，0
  sort(vec.begin(),vec.end()); 
  cout<<endl;
  for(auto r_iter=vec.crbegin();r_iter!=vec.crend();++r_iter)
    cout<<*r_iter<<" ";  //打印9，8，7，6，5，4，3，2，1，0
  cout<<endl;
}

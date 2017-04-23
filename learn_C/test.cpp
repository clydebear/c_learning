#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  cout<<sizeof(a)<<" ";
  cout<<sizeof(*a)<<" "<<*a<<endl;
  int val = 1;
  int *result = find(begin(a),end(a),val);
  if(result!=end(a))
    cout<<*result<<endl;
  else
    cout<<"not find"<<endl;
  return 0;
}

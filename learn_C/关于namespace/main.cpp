#include <iostream>
#include "./notmain1.h"
namespace myname
{
  int clyde =0;
}

namespace yourname
{
  int clyde =2;
}

using namespace ourname;
using namespace std;
int main()
{
  cout<<clyde<<endl;
  return 0;
}

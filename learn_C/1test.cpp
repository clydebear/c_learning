#include <bits/stdc++.h>

using namespace std;

class StrBlobPtr {
public:
    std::string& operator*() const {
        auto p = check(curr, "dreference past end");
        return (*p)[curr];
    }

    std::string* operator->()const {
        return & this->operator*();
    }
    //
};


int main(int argc, char const *argv[])
{

  return 0;
}

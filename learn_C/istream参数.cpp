#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::cin;
using std::string;
class X {
public:
    string s;
    X(std::istream &is=cin) {
        is>>s;
    };
    void print() {
        cout<<s<<endl;
    }
};
int main() {
  X x(cin);
  char aa[256];
  cin.getline(aa,256);
  char bb[256];

  cout<<aa<<endl;
  cout<<x.s<<endl;
  x.print();

  string ss;
  getline(cin,ss,'#');//#为分隔符，结束符
}

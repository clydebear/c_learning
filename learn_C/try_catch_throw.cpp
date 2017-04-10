#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  int j;
  int i;
  while(cin>>j>>i)
  {
    try//操作
    {
      if(i==0)
      {
         throw runtime_error("0");//抛出异常
      }
      else if(i == 1)
      {
        //throw runtime_error("1");
        throw logic_error("除1都不会算");
      }
      else
        cout<<"j/i="<<j/i<<"  j%i="<<j%i<<endl;
    }
    catch(runtime_error err)//捕获异常
    {
      string temp =err.what();
      if(temp == "1")
      {
        cout<<"只是1而已"<<endl;
        cout<<"go on~"<<endl;
      }
      else if(temp == "0")
      {
        cout<<err.what()
            <<"\nTry again?Enter y or n"<<endl;
        char k;
        cin>>k;
        if(!cin|| k== 'n')
        {
          break;
        }
        cout<<"go on~"<<endl;
      }

    }
    catch(logic_error err1)
    {
      cout<<err1.what()
        <<"\nTry again?Enter y or n"<<endl;
      char k;
      cin>>k;
      if(!cin|| k== 'n')
      {
        break;
      }
      cout<<"go on~"<<endl;
    }

  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
//建立map
map<string,string> buildmap(ifstream &map_file)
{
  map<string,string> trans_map;
  string key;
  string value;
  while(map_file>>key&&getline(map_file,value))
  {
    if(value.size()>1)
      trans_map[key] = value.substr(1);//跳过空格
    else
      throw runtime_error("no rule for "+key);
  }
  return trans_map;
}
//生产转换文本
const string &transform(const string &s,const map<string,string> &m)
{
  auto map_it = m.find(s);
  if (map_it!=m.end())
  {
    return map_it->second;
  }
  else
    return s;
}

void word_transform(ifstream &map_file,ifstream &input)
{
  auto trans_map = buildmap(map_file);
  string text;
  while(getline(input,text))
  {
    istringstream stream(text);
    string word;
    bool firstword = true;
    while(stream>>word)
    {
      if(firstword)
        firstword = false;
      else
        cout<<" ";
      cout<<transform(word, trans_map);
    }
    cout<<endl;
  }
}
int main(int argc, char const *argv[]) {
  ifstream fcin1("./inputfile.in");
  ifstream fcin2("./input2.in");
  word_transform(fcin1, fcin2);
  return 0;
}

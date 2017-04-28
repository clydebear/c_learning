#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <sstream>
                                                    //不要在头文件里包含太多头文件，一般包含在cpp中
using namespace std;
class QueryResult;                                  //先声明后使用。要返回内容多，最简单的方法是定义一个类
class TextQuery
{
public:
    using line_no = vector<string>::size_type;      //类型成员，必须先定义后使用
    TextQuery(ifstream &);                          //构造函数，传入要查询的文本
    QueryResult query(const string&)const;          //查询函数，传入要查询的单词，返回查询结果
    ~TextQuery();
private:
    shared_ptr<vector<string>> file;                //输入文件
    map<string, shared_ptr<set<line_no>>> wm;       //单词到行号集合的映射

};

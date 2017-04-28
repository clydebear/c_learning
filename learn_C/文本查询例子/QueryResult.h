#pragma once
#include "TextQuery.h"
class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);
public:
    QueryResult(string s,shared_ptr<set<TextQuery::line_no>> p,shared_ptr<vector<string>> f):
        sought(s),lines(p),file(f){}
private:
    string sought;                                  //查询的单词
    shared_ptr<set<TextQuery::line_no>> lines;      //包含的行数
    shared_ptr<vector<string>> file;                //输入文件
};

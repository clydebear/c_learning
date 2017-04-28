#include "TextQuery.h"

#include "QueryResult.h"

TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
    std::cout<<"构造函数"<<endl;
    string text;
    while (getline(is,text))                    //从文本中读取一行
    {
        file->push_back(text);                  //每行作为一个元素存入vector
        int n = file->size() - 1;               //行号，下标
        istringstream line(text);
        string word;
        while (line>>word)                      //从每行中读取单个单词
        {
            auto &lines = wm[word];             //map的下标运算符，如果关键字不存在，则创建一个新元素。
                                                //其value为空指针
                                                //lines是引用，改变它也会改变智能指针
            if (!lines)
            {
                lines.reset(new set<line_no>);  //第一次遇到word为空指针，因此让他指向新的set
            }
            lines->insert(n);                   //将行号插入set，如果重复则不执行任何操作
        }
    }
}


TextQuery::~TextQuery()
{
}


QueryResult TextQuery::query(const string &sought)const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc==wm.end())
    {
        return QueryResult(sought, nodata, file);           //如果没找到，返回空set
    }
    else
    {
        return QueryResult(sought, loc->second, file);      //返回指向set的指针
    }
}

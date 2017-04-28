#pragma once
#include <bits/stdc++.h>
/*
查询指定单词在文本中出现的次数，以及出现行的内容
方法：
1）确定任务
读取文件，必须记住单词出现的每一行。因此程序需要逐行读取输入文件，并每行要分解单独单词
输出时，要提取有关的行号
行号升序，无重复
能打印
实现方案：确定存、提单词等
vecotr<string>  存整个文档，每个元素为一行
使用istringstream分解每行
set<int>保存出现的行号。有序容器
使用map存，每个单词与其对应set关联起来

数据结构：
TextQUery类：
{
  vector
  map
  输入文件构造函数
  查询操作
}
QueryResult
{
  保存查询结果
  print
}
类之间要共享数据，用shared_ptr反映两个类之间的数据共享
*/
#include "QueryResult.h"
#include "TextQuery.h"
int main()
{
    void runQuery(ifstream &file);
    ifstream file("text.txt");
    runQuery(file);
    return 0;

}


ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() <<" times"<< endl;
    for (auto num:*qr.lines)
    {
        os << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}

void runQuery(ifstream &file)
{
    TextQuery tq(file);
    while (true)
    {
        cout << "enter word to look for,or q to quit"<<endl;
        string s;
        if (!(cin>>s)||s=="q")
        {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }

}

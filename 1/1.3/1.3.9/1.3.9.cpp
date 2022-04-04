#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

const unordered_set<char> operators
{
    '+',
    '-',
    '*',
    '/'
};

void fullExpression(string& str)
{
    stack<string> exp;
    stack<string> operatorHelp;
    for(char c : str)
    {
        if(c >= '0' && c <= '9')
        {
            exp.push(string(1,c));
        }
        else if(operators.find(c) != operators.end())
        {
            operatorHelp.push(string(1,c));
        }
        else
        {
            string right = exp.top();
            exp.pop();
            if(exp.empty())
            {
                exp.push('('+right+')');
                break;
            }
            string left = exp.top();
            exp.pop();
            if(operatorHelp.empty() && exp.size() > 1)
            {
                cout << "error input" << endl;
                return;
            }
            string operation = operatorHelp.top();
            operatorHelp.pop();
            exp.push('('+left+operation+right+')');
        }
    }
    str = exp.top();
}

int main()
{
    vector<string> store;
    ifstream *fp = new ifstream();
    fp->open("E:\\cpp\\algorithm\\1.3.9\\test.txt",ios::in);
    if(!fp->is_open())
    {
        cout << "fail";
        return 0;
    }
    while(!fp->eof())
    {
        string str;
        getline(*fp,str);
        fullExpression(str);
        store.push_back(str);
    }
    for(auto s : store)
    {
        cout << s << endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char,int> inPriority
{
    {'+',3},
    {'-',3},
    {'*',5},
    {'/',5},
    {'(',1},
    {')',6}
};

unordered_map<char,int> outPriority
{
    {'+',2},
    {'-',2},
    {'*',4},
    {'/',4},
    {'(',6},
    {')',1}
};

void infixToPostFix(string& str)
{
    string tmp;
    stack<char> help;
    for(char c : str)
    {
        if(c >= '0' && c <= '9')
        {
            tmp += c;
        }
        else
        {
            if(help.empty() || outPriority[c] > inPriority[help.top()])
            {
                help.push(c);
            }
            else if(outPriority[c] < inPriority[help.top()])
            {
                while(!help.empty() && outPriority[c] < inPriority[help.top()])
                {
                    tmp += help.top();
                    help.pop();
                }
                if(c == ')')
                {
                   help.pop(); 
                }
                else
                {
                    help.push(c);
                }
            }
            else
            {
                help.pop();
            }
        }
    }
    while(!help.empty())
    {
        tmp+=help.top();
        help.pop();
    }
    str = tmp;
}

int main()
{
    vector<string> result;
    ifstream* fp = new ifstream();
    ofstream* ofp = new ofstream();
    ofp->open("E:\\cpp\\algorithm\\1.3.11\\test.txt",ios_base::app);
    fp->open("E:\\cpp\\algorithm\\1.3.10\\test.txt");
    string str = "";
    while(getline(*fp,str))
    {
        infixToPostFix(str);
        result.push_back(str);
        *ofp << str << endl;
    }
    for(auto s : result)
    {
        cout << s << endl;
    }
    fp->close();
    ofp->close();
    return 0;
}
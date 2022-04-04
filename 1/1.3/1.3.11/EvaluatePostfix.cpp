#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

string EvaluatePostFix(string& str)
{
    stack<string> help;
    for(char c : str)
    {
        if(c >= '0' && c <= '9')
        {
            help.push(string(1,c));
        }
        else
        {
            double a = atof(help.top().c_str());
            help.pop();
            double b = atof(help.top().c_str());
            help.pop();
            if(c == '+')
            {
                help.push(to_string(a+b));
            }
            else if(c == '-')
            {
                help.push(to_string(a-b));
            }
            else if(c == '*')
            {
                help.push(to_string(a*b));
            }
            else
            {
                help.push(to_string(b/a));
            }
        }
    }
    return help.top();
}

int main()
{
    ifstream * fp = new ifstream();
    ofstream * ofp = new ofstream();
    fp->open("E:\\cpp\\algorithm\\1.3.11\\test.txt");
    ofp->open("E:\\cpp\\algorithm\\1.3.11\\result.txt",ios_base::app);
    string str;
    while(getline(*fp,str))
    {
        *ofp << EvaluatePostFix(str) <<endl;
    }
    fp->close();
    ofp->close();
    return 0;
}
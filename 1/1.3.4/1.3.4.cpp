#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

bool isLegal(string& str)
{
    stack<char> opera;
    int len = str.length();
    for(char c : str)
    {
        switch (c)
        {
        case '[':
        case '(':
        case '{':
        {
            opera.push(c);
        }
        break;
        case ']':
        {
            if(opera.empty() || opera.top() != '[')
            {
                return false;
            }
            opera.pop();
        }
        break;
        case ')':
        {
            if(opera.empty() || opera.top() != '(')
            {
                return false;
            }
            opera.pop();
        }
        break;
        case '}':
        {
            if(opera.empty() || opera.top() != '{')
            {
                return false;
            }
            opera.pop();
        }
        break;
        default:
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    std::ifstream* fp = new std::ifstream(".E:\\cpp\\algorithm\\1.3.4\\test.txt");
    char buf[256];
    while(!fp->eof())
    {
        fp->getline(buf,256);
        std::string str = buf;
        cout << isLegal(str) << endl;
    }
    return 0;
}
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> splitstr(char c,string& str)
{
    vector<int> ret;
    int len = str.length();
    string tmp = "";
    for(int i = 0;i < len; ++i)
    {
        if(str[i] == ' ')
        {
            ret.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }
    ret.push_back(atoi(tmp.c_str()));
    return ret;
}


int findPair(vector<int>& nums)
{
    int ret = 0;
    unordered_map<int,vector<vector<int>>>  help;
    for(int i = 0;i < nums.size()-1; ++i)
    {
        for(int j = i+1; j < nums.size(); ++j)
        {
            int count = nums[i] + nums[j];
            if(help.find(count) == help.end())
            {
                vector<int> tmp{nums[i],nums[j]};
                help[count].push_back(tmp);
            }
            else
            {
                vector<int> tmp{nums[i],nums[j]};
                help[count].push_back(tmp);
                ret++;
            }
        }
    }
    for(auto iter = help.begin(); iter != help.end(); ++iter)
    {
        cout << iter->first << ':' << endl;
        for(auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            for(int i : *it)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
    }
    return ret;
}

int main()
{
    ifstream* fp = new ifstream("E:\\cpp\\algorithm\\1\\1.4.8\\test.txt");
    string input;
    vector<int> data;
    while(getline(*fp,input))
    {
        data = splitstr(' ',input);
    }
    cout << findPair(data) << endl;
}
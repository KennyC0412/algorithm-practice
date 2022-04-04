#include <unordered_map>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    string str;
    Node* next;
    Node* pre;
    Node(const string& s)
    {
        str = s;
        next = nullptr;
        pre = nullptr;
    }
};

class List
{
public:
    void Insert(const string& s);
    void InsertHead(const string& s);
    bool Delete(const string& s);
    void Travel();
private:
    Node* head = nullptr;
    unordered_map<string, Node*> index;
};

void List::Insert(const string& s)
{
    if(head == nullptr)
    {
        head = new Node(s);
        index[s] = head;
        return;
    }
    auto iter = index.find(s);
    bool AtHead = false;
    if(iter != index.end())
    {
        AtHead = Delete(s);
    }
    if(!AtHead)
    {
        InsertHead(s);
    }
}

void List::InsertHead(const string& s)
{
    Node* cur = new Node(s);
    cur->next = head;
    head->pre = cur;
    head = cur;
    index[s] = head;
}

bool List::Delete(const string& s)
{
    Node* cur = index[s];
    if(cur == head)
    {
        return true;
    }
    cur->pre->next = cur->next;
    if(cur->next)
    cur->next->pre = cur->pre;
    delete(cur);
    return false;
}

void List::Travel()
{
    Node* cur = head;
    while(cur)
    {
        std::cout << cur->str << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main()
{
    ifstream fp("E:\\cpp\\algorithm\\1\\1.3.40\\test.txt");
    string str;
    vector<string> data;
    while(getline(fp,str))
    {
        data.push_back(str);
    }
    List l;
    for(int i = 0;i < data.size(); ++i)
    {
        l.Insert(data[i]);
        l.Travel();
    }
}
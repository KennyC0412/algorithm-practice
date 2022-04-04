#include <iostream>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

struct Node
{
    Node* next;
    int val;
    Node(){ next = NULL;  val = 0;}
    Node(int n){ next = NULL;  val = n;}
};

class List
{
public:
    List(){ head = new Node();}
    List(int n);
    bool isEmpty() { return head == NULL; }
    Node* GetNode(){ return head; }
    void SetNode(){ head = head->next;}
private:
    Node* head = NULL;
};

List::List(int n)
{
    head = new Node(0);
    Node* cur = head;
    for(int i = 1; i < n; ++i)
    {
        Node* tmp = new Node(i);
        cur->next = tmp;
        cur = tmp;
    }
    cur->next = head;
}

vector<int> split(string str)
{
    vector<int> ret;
    string tmp = "";
    for(int i = 0;i < str.length(); ++i)
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

void joephus(int people, int mark)
{
    List l(people);
    Node* head = l.GetNode();
    Node* cur = head;
    Node* pre = NULL;
    while(true)
    {
        for(int i = 0;i < mark-1; ++i)
        {
            pre = cur;
            cur = cur->next;
        }
        std::cout << cur->val << " ";
        if(l.GetNode() == cur)
        {
            l.SetNode();
        }
        if(l.GetNode() == cur)
        {
            delete(cur);
            std::cout << std::endl;
            return ;
        }
        pre->next = cur->next;
        delete(cur);
        if(pre)
        cur = pre->next;
    }
}


int main()
{
    ifstream fp("E:\\cpp\\algorithm\\1\\1.3.37\\test.txt");
    string str;
    while(getline(fp,str))
    {
        auto data = split(str);
        joephus(data[0],data[1]);
    }
    return 0;
}

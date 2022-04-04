#include <iostream>


typedef struct Node
{
    Node* next;
    Node* pre;
    int val;
    Node(int n)
    {
        val = n;
        next = NULL;
        pre = NULL;
    }
}Node;

class DoubleList
{
public:
    DoubleList(){root = NULL;}
    void HeadInsert(int n);
    void BackInsert(int n);
    void HeadDelete();
    void BackDelete();
    void Travel();
private:
    int size = 0;
    Node* root;
};

void DoubleList::HeadInsert(int val)
{
    Node* tmp = new Node(val);
    if(root == NULL)
    {
        root = tmp;
        root->next = root;
        root->pre =  root;
    }
    else
    {
        tmp->pre = root->pre;
        tmp->next = root;
        root->pre->next = tmp;
        root->pre = tmp;
        root = tmp;
    }
    size++;
}

void DoubleList::HeadDelete()
{
    if(root == NULL)
    {
        return;
    }
    Node* tmp = root->next;
    if(tmp == root)
    {
        delete(root);
        root = NULL;
    }
    else if(root->pre == tmp)
    {
        delete(root);
        root = tmp;
        root->next = root->pre = root;
    }
    else
    {
        root->next->pre = root->pre;
        root->pre->next = root->next;
        Node* tmp = root;
        root = root->next;
        delete(tmp);
    }
    size--;
}

void DoubleList::BackDelete()
{
    if(root == NULL)
    {
        return;
    }
    Node* tmp = root->pre;
    if(tmp == root)
    {
        delete(root);
        root = NULL;
    }
    else if(tmp->next == root)
    {
        delete(tmp);
        root->pre = root;
        root->next = root;
    }
    else
    {
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
        delete(tmp);
    }
    size--;
}

void DoubleList::BackInsert(int val)
{
    Node* tmp = new Node(val);
    if(root == NULL)
    {
        root = tmp;
        root->next = root;
        root->pre = root;
    }
    else
    {
        tmp->next = root->pre->next;
        tmp->pre = root->pre;
        root->pre->next = tmp;
        root->pre = tmp;
    }
    size++;
}

void DoubleList::Travel()
{
    Node* cur = root;
    for(int i = 0;i < size; ++i)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main()
{
    DoubleList* l = new DoubleList();
    l->HeadInsert(5);
    l->Travel();
    //5
    l->HeadInsert(3);
    l->Travel();
    //3 5
    l->BackDelete();    
    l->Travel();
    //3
    l->BackInsert(1);    
    l->Travel();
    //3 1
    l->HeadDelete();    
    l->Travel();
    //1
}
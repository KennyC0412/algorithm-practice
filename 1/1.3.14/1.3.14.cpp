#include <iostream>
#include <vector>

using namespace std;
typedef class ResizingArrayQueueOfStrings
{
public:
    ResizingArrayQueueOfStrings(){}
    ~ResizingArrayQueueOfStrings(){ free(array); }
    ResizingArrayQueueOfStrings(int n);
    void resize(int n);
    void enqueue(int val);
    void dequeue();
    bool empty();
    bool isFull();
    int si() { return size;}
    int cap();
    int front();
    int getK(int K);
private:
    int* array = NULL;
    int size = 0;
    int capacity = 0;
}Queue;

ResizingArrayQueueOfStrings::ResizingArrayQueueOfStrings(int n)
{
    array = (int *)malloc(sizeof(int)*n);
    capacity = n;
}

void ResizingArrayQueueOfStrings::enqueue(int val)
{
    if(capacity == size)
    {
        resize(capacity*2);
    }
    *(array + size) = val;
    size++;
}

void ResizingArrayQueueOfStrings::dequeue()
{
    for(int i = 0;i < size-1; ++i)
    {
        array[i] = array[i+1];
    }
    size--;
}

bool ResizingArrayQueueOfStrings::empty()
{
    return size == 0;
}

bool ResizingArrayQueueOfStrings::isFull()
{
    return size == capacity;
}

int ResizingArrayQueueOfStrings::front()
{
    if(array == NULL)
    {
        return -1;
    }
    return *array;
}

int ResizingArrayQueueOfStrings::getK(int K)
{
    if(K > size)
    {
        return -1;
    }
    return *(array + size - K);
}

int ResizingArrayQueueOfStrings::cap()
{
    return capacity;
}

void ResizingArrayQueueOfStrings::resize(int n)
{
    int* tmp = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i < size; ++i)
    {
        tmp[i] = array[i];
    }
    free(array);
    array = tmp;
    capacity *= 2;
}

int main(int argc,char* argv[])
{
    Queue queue(5);
    vector<int> num;
    for(int i = 0; i < 21; ++i)
    {
        queue.enqueue(rand());
        cout << queue.cap() << ' ' << queue.si() << endl;
    }
    if(argc == 2)
    {
        cout << queue.getK(atoi(argv[1])) << endl;
    }
    while(!queue.empty())
    {
        cout << queue.front() << ' ' << queue.si() << endl;
        queue.dequeue();
    }
    return 0;
}
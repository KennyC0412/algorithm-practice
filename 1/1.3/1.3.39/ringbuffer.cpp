#include <iostream>
#include <vector>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>


using namespace std;

typedef function<void()> func;

condition_variable cond;
mutex mtx;

class Buffer
{
public:
    static Buffer* GetInstance()
    {
        static Buffer buf;
        return &buf;
    }
    void Init(int n) { buffer = vector<int>(n,0); capacity = n;}
    void Add(int val);
    int Del();
    bool isEmpty() { return head == tail; }
    bool isFull() { return (tail+1)%capacity == head; }
private:
    vector<int> buffer;
    int head = 0;
    int tail = 0;
    int capacity;
};

void Buffer::Add(int val)
{
    std::cout << "add val " << val << std::endl;
    buffer[tail] = val;
    tail = tail+1 == capacity ? 0 : tail+1;
}

int Buffer::Del()
{
    int ret = buffer[head];
    head = head+1 == capacity ? 0 : head+1;
    return ret;
}

class Consumer
{
public:
    void consume()
    {
        while(true)
        {
                    unique_lock<mutex> lock(mtx);
        while(!Buffer::GetInstance()->isFull())
        {
            cond.wait(lock);
        }
        while(!Buffer::GetInstance()->isEmpty())
        {
            cout << "consume " << Buffer::GetInstance()->Del() << std::endl;
        }
        cond.notify_one();
        }

    }
private:

};


class Producer
{
public:
    void produce()
    {
        while(true)
        {
                    unique_lock<mutex> lock(mtx);
        while(!Buffer::GetInstance()->isEmpty())
        {
            cond.wait(lock);
        }
        while(!Buffer::GetInstance()->isFull())
        {
            Buffer::GetInstance()->Add(rand());
        }
        cond.notify_one();
        }
    }

private:
};


int main()
{
    Buffer::GetInstance()->Init(5);
    Producer p;
    Consumer c;
    thread t1(&Producer::produce,p);
    thread t2(&Consumer::consume,c);
    t1.join();
    t2.join();
    while(true);
}
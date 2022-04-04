#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

std::unordered_map<int,std::string> card
{
    {0,"3"},
    {1,"4"},
    {2,"5"},
    {3,"6"},
    {4,"7"},
    {5,"8"},
    {6,"9"},
    {7,"10"},
    {8,"J"},
    {9,"Q"},
    {10,"K"},
    {11,"A"},
    {12,"2"},
    {13,"JOKER"}
};

template<typename T>
class RandomQueue
{
public:
    RandomQueue(){}
    bool isEmpty() { return data.size() == 0; }
    void enqueue(T t);
    T dequeue();
    T sample();
private:
    std::vector<T> data;
};


template<typename T>
void RandomQueue<T>::enqueue(T t)
{
    data.push_back(t);
}

template<typename T>
T RandomQueue<T>::dequeue()
{
    srand(time(NULL));
    int index = rand() % data.size();
    std::swap(data[data.size()-1],data[index]);
    T tmp = data[data.size()-1];
    data.pop_back();
    return tmp;    
}

template<typename T>
T RandomQueue<T>::sample()
{
    srand(time(NULL));
    int index = rand() % data.size();
    return data[index];
}

int main()
{
    RandomQueue<std::string>* q = new RandomQueue<std::string>();
    for(int i = 0;i < 14; ++i)
    {
        q->enqueue(card[i]);
    }
    while(!q->isEmpty())
    {
        std::cout << q->dequeue() << " ";
    }
    return 0;
}
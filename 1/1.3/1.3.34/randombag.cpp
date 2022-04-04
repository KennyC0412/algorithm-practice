#include <iostream>
#include <vector>
#include <fstream>
#include <string>

template<typename T>
class RandomBag
{
public:
    bool isEmpty() { return size == 0; }
    int Size() { return size; }
    void add(T t);
    RandomBag(){};
    RandomBag(std::vector<T>&);
    void Travel()
    {
        for(T& t : bag)
        {
            std::cout << t << " ";
        }
    }
private:
    int size = 0;
    std::vector<T> bag;
};

template<typename T>
RandomBag<T>::RandomBag(std::vector<T>& v)
{
    int i = 0;
    int s = v.size();
    for(int i = 0;i < s; ++i)
    {
        srand(time(NULL));
        int index = rand()%(s-i)+i;
        std::swap(v[i],v[index]);
        add(v[i]);
    }
};

template<typename T>
void RandomBag<T>::add(T t)
{
    bag.push_back(t);
    size++;
}

int main()
{
    std::ifstream* fp = new std::ifstream();
    fp->open("E:\\cpp\\algorithm\\1.3.34\\test.txt");
    std::vector<int> data;
    std::string str;
    while(getline(*fp,str))
    {
        data.push_back(atoi(str.c_str()));
    }
    RandomBag<int>* bag = new RandomBag<int>(data);
    bag->Travel();
}
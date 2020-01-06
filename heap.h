#include <iostream>
#include <sstream>
#include <stdexcept>
#ifndef HEAP_H 
#define HEAP_H

using namespace std;

template <typename T>
class Heap
{
public:
    Heap();
    Heap(int cap);
    ~Heap();
    void insert_key(T key);
    T deletedata();
    T getdata();
    void printheap();
private:
    void percolateDown(int pos);
    bool isfull();
    bool isempty(); 
    int leftchild(int pos);
    int rightchild(int pos);
    int parent(int pos);
    int count;
    int capacity;
    int *heap;
};

template <typename T>
Heap<T>::Heap()
{
    this->count = 0;
    this->capacity = 10;
    this->heap = new T[this->capacity];
}

template <typename T>
Heap<T>::Heap(int cap)
{
    this->count = 0;
    this->capacity = cap;
    this->heap = new  T[this->capacity];
}

template <typename T>
bool Heap<T>::isfull()
{
    return this->count == this->capacity - 1;
}

template <typename T>
bool Heap<T>::isempty()
{
    return this->count == 0;
}

template <typename T>
int Heap<T>::parent(int pos)
{
    if(pos <= 0 || pos > this->count)
        return -1;
    return (pos-1)/2;
}


template <typename T>
int Heap<T>::leftchild(int pos)
{
    if(pos < 0 || pos > this->count)
        return -1;
    return 2*pos+1;
}

template <typename T>
int Heap<T>::rightchild(int pos)
{
    if(pos < 0 ||  pos > this->count)
        return -1;
    return 2*pos+2;
}


template <typename T>
void Heap<T>::percolateDown(int pos)
{
    int lc,rc,max;
    lc = this->leftchild(pos);
    rc = this->rightchild(pos);
    if(lc != -1 && this->heap[lc] > this->heap[pos])
        max = lc;
    else 
        max = pos;
    if(rc != -1 && this->heap[rc] > this->heap[max])
        max = rc; 
    if(max != pos)
    {
        int temp = this->heap[max];
        this->heap[max] = this->heap[pos];
        this->heap[pos] = temp;
        percolateDown(max);
    }
}

template <typename T>
void Heap<T>::insert_key(T key)
{
    int pos = this->count;
    this->count++;
    try
    {
        if(this->isfull())
        {
            throw logic_error("Heap is Full!!!");
        }
        else 
        {
            while(pos > 0 && this->heap[(pos-1)/2] < key)
            {
                this->heap[pos] = this->heap[(pos-1)/2];
                pos = (pos-1)/2;
            }
            this->heap[pos] = key;
        }
    }
    catch(logic_error& e) 
    {
        cerr << e.what() << endl;
    }
}

template <typename T>
T Heap<T>::deletedata()
{
    try
    {
        if(this->isempty())
        {
            throw logic_error("Heap is Empty!!!");
        }
        else 
        {
            int data = this->heap[this->count - 1];
            this->heap[0] = this->heap[this->count - 1];
            this->count--;
            percolateDown(0);
            return data;
        }
    }
    catch(logic_error& e)
    {
        cerr << e.what() << '\n';
    }

}

template <typename T>
T Heap<T>::getdata()
{
    try 
    {
        if(this->isempty())
            throw logic_error("Heap is empty");
        else 
            return this->heap[0];
    }
    catch(logic_error& e)
    {
        cerr << e.what() << endl;
    }
}

template <typename T>
void Heap<T>::printheap()
{
    cout << "{ Heap : ";
    for(int i = 0; i < this->count; i++)
        cout << this->heap[i] << ", ";
    cout << " }" << endl;
}

#endif
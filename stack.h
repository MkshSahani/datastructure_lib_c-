#include <iostream>
#ifndef STACK_H 
#define STACK_H 

using namespace std;

template <typename T>
class Stack; 

template <typename T>
class Node 
{
public:
    Node();
    Node(T key);
private:
    T data;
    Node<T> *next;

friend class Stack<T>;
};

template <typename T>
Node<T>::Node()
{
    next = NULL;
}

template <typename T>
Node<T>::Node(T key)
{
    data = key;
    next = NULL;
}

template <typename T>
class Stack 
{
public:
    Stack();
    void push(T key);
    Node<T>* pop();
    bool isempty();
    void print_stack();
private:
    Node<T> *top;
};

template <typename T>
List<T>::List()
{
    top = NULL;
}

template <typename T>
void List<T>::push(T key)
{
    if(this->top == NULL)
    {
        this->top = new Node<T>(key);
    }
    else 
    {
        Node<T> *new_node = new Node<T>(key);
        new_node->next = this->top;
        this->top = new_node;
    }
}

template <typename T>
Node<T>* List<T>::pop()
{
    Node<T>* ret = this->top;
    Node<T>* temp = this->top;
    this->top = this->top->next;
    delete temp;
    return ret;
}

template <typename T>
void List<T>::print_stack()
{
    Node<T> *current = this->top; 
    cout << "{ Stack : ";
    while(current != NULL)
    {
        cout << current->data << ", " << endl;
        current = current->next;
    }
    cout << " }" << endl;
}


#endif

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#ifndef LIST_H 
#define LIST_H 

using namespace std;

template <typename T>
class List; 

template <typename T>
class Node{
public:
    Node();
    Node(T key);    

private:
    T data;
    Node<T> *next;

friend class List<T>;
};

template <typename T>
Node<T>::Node()
{
    this->next = NULL;
}

template <typename T>
Node<T>::Node(T key)
{
    data = key;
    this->next = NULL;
}

template <typename T>
class List
{
public:
    List();
    void push_back(T key);    
    void print_list();
    Node<T>* delete_node(T key);
    Node<T>* search_node(T key);
private:
    Node<T> *head;
};

template <typename T>
List<T>::List()
{
    this->head = NULL;
}

template <typename T>
void List<T>::push_back(T key)
{
    if(this->head == NULL)
    {
        this->head = new Node<T>(key);
    }
    else 
    {
        Node<T>* current = this->head; 
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new Node<T>(key);
    }
}

template <typename T>
void List<T>::print_list()
{
    Node<T> *current = this->head; 
    try 
    {
        if(this->head == NULL)
            throw logic_error("List is Empty!!!");
        
        else 
        {
            cout << "{List : ";
            while(current != NULL)
            {
                cout << current->data << ", ";
                current = current->next;
            }        
            cout << " }" << endl;
        }
    }
    catch(logic_error& e)
    {
        cerr << e.what() << endl;
    }
}

template <typename T>
Node<T>* List<T>::delete_node(T key)
{
    try 
    {
        if(this->head == NULL)
        {
            throw logic_error("List is Empty!!!");
        }
        else 
        {
            Node<T> *current = this->head; 
            Node<T> *previous = this->head;
            while(current != NULL && current->data != key)
            {
                previous = current;
                current = current->next; 
            }
            Node<T> *temp = current;
            // cout << "Lets Check : " << current << endl; // for the scope of checking.
            if(current != NULL)
            {
                if(current == this->head)
                {
                    this->head  = this->head->next; 
                }                
                else 
                {
                    previous->next = current->next;
                }

                delete current;
                // cout << "Lest Check : " << current << endl; // for the scope of checking.
            }
            return temp;
        }
    }
    catch(logic_error& e)
    {
        cerr << e.what() << endl;
    }
}

template <typename T>
Node<T>* List<T>::search_node(T key)
{
    try 
    {
        if(this->head == NULL)
            throw logic_error("List is Empty!!!");
        Node<T> *current = this->head; 
        while(current != NULL && current->data != key)
        {
            current = current->next;
        }
        return current;
    }
    catch(logic_error& e) 
    {
        cerr << e.what() << endl;
    }
}

#endif

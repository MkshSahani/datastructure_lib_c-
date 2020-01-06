#include <iostream>
#ifndef BST_H 
#define BST_H 

using namespace std;

template <typename T>
class BST;

template <typename T>
class Node 
{
public:
    Node();
    Node(T key);
private:
    T data;
    Node<T> *left;
    Node<T> *right;

friend class BST<T>;
};

template <typename T>
Node<T>::Node()
{
    // defualt constructor.
    this->left = NULL;
    this->right = NULL;
}

template <typename T>
Node<T>::Node(T key)
{
    this->data = key;
    this->left = NULL;
    this->right = NULL;
}

template <typename T>
class BST 
{
public:
    BST();
    ~BST();
    void insert_node(T key);
    Node<T>* findmax();
    Node<T>* delete_node(T key);
    void printTree();
private:
    Node<T>* root;
    Node<T>* insert_node(Node<T> *node, T key);
    Node<T>* delete_node(Node<T> *node, T key);
    Node<T>* findmax(Node<T> *keynode);
    void printTree(Node<T> *node);
};

template <typename T>
BST<T>::BST()
{
    root = NULL;
}

template <typename T>
Node<T>* BST<T>::insert_node(Node<T> *node,T key)
{
    if(node == NULL)
        node = new Node<T>(key);
    else 
    {
        if(key < node->data)
            node->left =  insert_node(node->left, key);
        else if(key >= node->data)
            node->right =  insert_node(node->right, key);
    }
    return node;
}


template <typename T>
void BST<T>::insert_node(T key)
{
    if(this->root == NULL)
        this->root = new Node<T>(key);
    else 
        this->insert_node(this->root, key);
}

template <typename T>
Node<T>* BST<T>::findmax(Node<T> *keynode)
{
    Node<T> *current = keynode;
    while(current->right != NULL)
        current = current->right;
    return current;
}

template <typename T>
Node<T>* BST<T>::findmax()
{
    return this->findmax(this->root);
}

template <typename T>
Node<T>* BST<T>::delete_node(Node<T> *node, T key)
{
    if(node == NULL)
    {
        return NULL;
    }
    else 
    {
        if(key < node->data)
            node->left = this->delete_node(node->left, key);
        else if(key > node->data)
            node->right = this->delete_node(node->right, key);
        else if(key == node->data)
        {
            if(node->right != NULL  && node->left != NULL)
            {
                Node<T>* temp = this->findmax(node->left);
                node->data = temp->data;
                node->left = this->delete_node(node->left, node->data);
            }
            else if(node->right != NULL && node->left == NULL)
            {
                Node<T>* temp = node;
                node = node->right;
                delete temp;
            }
            else if(node->left != NULL && node->right == NULL)
            {
                Node<T>* temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                Node<T> *temp = node;
                node = NULL;
                delete temp;
            }
        }
    }
    return node;
}

template <typename T>
Node<T>* BST<T>::delete_node(T key)
{
    if(this->root == NULL)
        return NULL; 
    else return this->delete_node(this->root, key);
}

template <typename T>
void BST<T>::printTree()
{
    if(this->root != NULL)
    {
        cout << "Binary Search Tree : ";
        this->printTree(this->root);
        cout << endl;
    }
    else 
    {
        cout << "Tree is not Grown Yet!!!";
    }
}

template <typename T>
void BST<T>::printTree(Node<T> *node)
{
    if(node != NULL)
    {
        this->printTree(node->left);
        cout << node->data << ", ";
        this->printTree(node->right);
    }
}

#endif 
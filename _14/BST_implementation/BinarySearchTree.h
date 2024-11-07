//
// Created by ner13 on 07/11/2024.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iomanip>


template<class T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    explicit Node(T val) : data(val), left(nullptr), right(nullptr)
    {
    }
};

template<class T>
class BinarySearchTree
{
private:
    Node<T> *root;
    int numOfNodes;

    // Helper functions for recursive operations
    Node<T> *insert(Node<T> *node, T value);

    Node<T> *search(Node<T> *node, T value) const;

    Node<T> *remove(Node<T> *node, T value);

    Node<T> *findMin(Node<T> *node) const;

    Node<T> *findMax(Node<T> *node) const;

    void print(Node<T> *node, int spaces) const;

public:
    BinarySearchTree() : root(nullptr), numOfNodes(0)
    {
    }

    void insert(T val);

    Node<T> *search(T val) const;

    void remove(T val);

    T findMin() const;

    T findMax() const;

    int size() const;

    void print() const;
};

template<class T>
Node<T> *BinarySearchTree<T>::insert(Node<T> *node, T value)
{
    if (node == nullptr)
        return new Node<T>(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

template<class T>
Node<T> *BinarySearchTree<T>::search(Node<T> *node, T value) const
{
    if (node == nullptr)
        return nullptr;
    else if (value < node->data)
        return search(node->left, value);
    else if (value > node->data)
        return search(node->right, value);
    else
        return node;
}

template<class T>
Node<T> *BinarySearchTree<T>::remove(Node<T> *node, T value)
{
    if (node == nullptr)
        return nullptr;
    else if (value < node->data)
        node->left = remove(node->left, value);
    else if (value > node->data)
        node->right = remove(node->right, value);
    else
    {
        if (node->left == nullptr)
        {
            Node<T> *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr)
        {
            Node<T> *temp = node->left;
            delete node;
            return temp;
        }

        Node<T> *min = findMin(node->right);
        node->data = min->data;
        node->right = remove(node->right, min->data);
    }
    return node;
}

template<class T>
Node<T> *BinarySearchTree<T>::findMin(Node<T> *node) const
{
    if (node == nullptr)
        return nullptr;

    while (node->left != nullptr)
        node = node->left;
    return node;
}

template<class T>
Node<T> *BinarySearchTree<T>::findMax(Node<T> *node) const
{
    if (node == nullptr)
        return nullptr;

    while (node->right != nullptr)
        node = node->right;

    return node;
}

template<class T>
void BinarySearchTree<T>::print(Node<T> *node, int spaces) const
{
    if (node == nullptr)
        return;

    const int SPACES = 4;
    spaces += SPACES;

    //std::cout << "Test node " << node->data << " spaces lvl "<< spaces << std::endl;

    print(node->right, spaces);

    std::cout << std::setw(spaces) << node->data << std::endl;

    print(node->left, spaces);
}

template<class T>
void BinarySearchTree<T>::insert(T val)
{
    this->root = insert(this->root, val);
    numOfNodes++;
}

template<class T>
Node<T> *BinarySearchTree<T>::search(T val) const
{
    return search(this->root, val);
}

template<class T>
void BinarySearchTree<T>::remove(T val)
{
    this->root = remove(this->root, val);
    numOfNodes--;
}

template<class T>
T BinarySearchTree<T>::findMin() const
{
    return findMin(root)->data;
}

template<class T>
T BinarySearchTree<T>::findMax() const
{
    return findMax(root)->data;
}

template<class T>
int BinarySearchTree<T>::size() const
{
    return numOfNodes;
}

template<class T>
void BinarySearchTree<T>::print() const
{
    print(root, 0);
}


#endif //BINARYSEARCHTREE_H

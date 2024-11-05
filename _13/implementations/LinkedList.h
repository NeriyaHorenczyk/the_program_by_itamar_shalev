//
// Created by ner13 on 05/11/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T> class LinkedList
{

    class Node
    {
    public:
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };


    Node* head;
    int listSize;

public:

    LinkedList() :head(nullptr), listSize(0) {}

    void insert(T val);
    bool isEmpty();
    int size();
    T pop();
};



#endif //LINKEDLIST_H

//
// Created by ner13 on 05/11/2024.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
using namespace std;

template <class T> class Queue
{
private:
    deque<T> container;

public:
    Queue() = default;

    bool isEmpty();
    int size();
    void push(T val);
    T pop();
    T& top();
};



#endif //QUEUE_H

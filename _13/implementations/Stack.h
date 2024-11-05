//
// Created by ner13 on 05/11/2024.
//

#ifndef STACK_H
#define STACK_H

#include <deque>
using namespace std;

template <class T> class Stack
{
private:
    deque<T> container;

public:

    //methods
    Stack() = default;

    void push(T val);
    T pop();
    T& top();
    bool isEmpty();
    int size();
};



#endif //STACK_H

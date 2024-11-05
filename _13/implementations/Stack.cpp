//
// Created by ner13 on 05/11/2024.
//
#include "Stack.h"

template<class T>
void Stack<T>::push(T val)
{
    container.push_back(val);
}

template<class T>
T Stack<T>::pop()
{
    if (!container.empty())
    {
        T temp = container.back();
        container.pop_back();
        return temp;
    }
}

template<class T>
T& Stack<T>::top()
{
    return container.back();
}

template<class T>
bool Stack<T>::isEmpty()
{
    return container.empty();
}

template<class T>
int Stack<T>::size()
{
    return container.size();
}


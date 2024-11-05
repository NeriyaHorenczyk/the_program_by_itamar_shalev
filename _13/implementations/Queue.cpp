//
// Created by ner13 on 05/11/2024.
//

#include "Queue.h"

template<class T>
bool Queue<T>::isEmpty()
{
    return container.empty();
}

template<class T>
int Queue<T>::size()
{
    return container.size();
}

template<class T>
void Queue<T>::push(T val)
{
    container.push_back(val);
}

template<class T>
T Queue<T>::pop()
{
    if (!container.empty())
    {
        T temp = container.front();
        container.pop_front();
        return temp;
    }
}

template<class T>
T& Queue<T>::top()
{
    return container.front();
}


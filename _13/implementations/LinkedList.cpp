//
// Created by ner13 on 05/11/2024.
//

#include "LinkedList.h"

template<class T>
void LinkedList<T>::insert(T val)
{
    Node* value = new Node(val);
    value->next = this->head;
    this->head = value;
    listSize++;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    return this->head == nullptr;
}

template<class T>
int LinkedList<T>::size()
{
    return listSize;
}

template<class T>
T LinkedList<T>::pop()
{
    if (!isEmpty())
    {
        Node* temp = this->head;
        T value = temp->data;
        this->head = this->head->next;
        delete temp;
        listSize--;
        return value;
    }
}


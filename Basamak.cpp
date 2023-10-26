//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Basamak.h"

Basamak::Basamak() {
    BasamakHead = nullptr;
}

Basamak::~Basamak() {
    Node* temp = BasamakHead;
    while (temp != nullptr)
    {
        Node* next = temp->Next;
        delete temp;
        temp = next;
    }
}

void Basamak::Add(int data)
{
    Node* newNode = new Node(data);
    if (BasamakHead == nullptr)
    {
        BasamakHead = newNode;
    }
    else
    {
        Node* temp = BasamakHead;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

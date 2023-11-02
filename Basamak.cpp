//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Basamak.h"
#include "Sayi.h"
#include "Node.h"
#include <iostream>

using namespace std;

Basamak::Basamak()
{
    this->Head = NULL;
}

Basamak::~Basamak()
{
    cout << "Basamak deleted" << endl;

    Node* temp = this->Head;
    while(temp != NULL)
    {
        Node* next = temp->Next;
        delete temp;
        temp = next;
    }
}

void Basamak::Add(int data)
{
    Node *newNode = new Node(data);
    if (this->Head == NULL)
    {
        this->Head = newNode;
    }
    else
    {
        Node *temp = this->Head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}
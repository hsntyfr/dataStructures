//
// Created by Hasan Tayfur on 26.10.2023.
//

#include <iostream>
#include "Sayi.h"
#include "Node.h"
#include "Basamak.h"


using namespace std;

Sayi::Sayi()
{
    this->Head = NULL;
}

Sayi::~Sayi()
{
    cout << "Sayi deleted" << endl;

    Node* temp = this->Head;
    while(temp != NULL)
    {
        Node* next = temp->Next;
        delete temp;
        temp = next;
    }
}

void Sayi::Add(Basamak *basamak)
{
    Node *newNode = new Node(basamak);
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

/*void Sayi::Print()
{
    Node *temp = this->Head;
    while (temp != NULL)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }
    cout << endl;
}*/

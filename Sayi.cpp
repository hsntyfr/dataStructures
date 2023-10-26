//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Sayi.h"
#include "Node.h"
#include <iostream>


Sayi::Sayi() {
    SayiHead = nullptr;
}

Sayi::~Sayi()
{
    Basamak* tempSayi = SayiHead;
    while (tempSayi != nullptr)
    {
        Basamak* next = tempSayi->Next;
        Node* tempBasamak = tempSayi->BasamakHead;
        while (tempBasamak != nullptr)
        {
            Node* next = tempBasamak->Next;
            delete tempBasamak;
            tempBasamak = next;
        }
        delete tempSayi;
        tempSayi = next;
    }
}

void Sayi::Add(Basamak *basamak)
{
    if (SayiHead == nullptr)
    {
        SayiHead = basamak;
    }
    else
    {
        Basamak* temp = SayiHead;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = basamak;
    }
}

void Sayi::Print()
{
    Basamak* tempSayi = SayiHead;
    while (tempSayi != nullptr)
    {
        Node* tempBasamak = tempSayi->BasamakHead;
        while (tempBasamak != nullptr)
        {
            std::cout << tempBasamak->Data;
            tempBasamak = tempBasamak->Next;
        }
        tempSayi = tempSayi->Next;
    }
    std::cout << std::endl;

}
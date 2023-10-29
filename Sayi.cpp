//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Sayi.h"
#include <iostream>


Sayi::Sayi() {
    BasamakHead = nullptr;
    Next = nullptr;
}

Sayi::~Sayi()
{
    std::cout << "sayi silindi" << std::endl;
}

void Sayi::Add(int data)
{
    Basamak* basamak = new Basamak(data);
    if (BasamakHead == nullptr)
    {
        BasamakHead = basamak;
    }
    else
    {
        Basamak* temp = BasamakHead;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = basamak;
    }
}

void Sayi::Print()
{

}

void Sayi::Delete(Sayi *sayi)
{
    Sayi *temp = sayi;
    while (temp != nullptr)
    {
        Sayi *temp5 = temp;
        Basamak *temp2 = temp->BasamakHead;
        while (temp2 != nullptr)
        {
            Basamak *temp3 = temp2;
            temp2 = temp2->Next;
            delete temp3;
        }
        temp = temp->Next;
        delete temp5;
    }
}



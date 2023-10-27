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
    while (BasamakHead != nullptr)
    {
        while (BasamakHead != nullptr)
        {
            Basamak* SayiHeadConst = BasamakHead;
            BasamakHead = BasamakHead->Next;
            delete SayiHeadConst;
        }

        Sayi* SayiHeadConst2 = Next;
        Next = Next->Next;
        delete SayiHeadConst2;
    }
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
   Basamak* SayiHeadConst = BasamakHead;





}



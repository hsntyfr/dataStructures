//
// Created by Hasan Tayfur on 2.11.2023.
//

#include "SayilarListesi.h"
#include "iostream"
using namespace std;

SayilarListesi::SayilarListesi()
{
    this->IlkSayi = nullptr;
}

SayilarListesi::~SayilarListesi()
{
    cout << "SayilarListesi silindi" << endl;
    while (this->IlkSayi != nullptr)
    {
        Dugum *temp = this->IlkSayi;
        this->IlkSayi = this->IlkSayi->Sonraki;
        delete temp;
    }
}

void SayilarListesi::Ekle(Dugum *dugum)
{
    Dugum *temp = this->IlkSayi;
    if (this->IlkSayi == nullptr)
    {
        this->IlkSayi = dugum;
    }
    else
    {
        while (temp->Sonraki != nullptr)
        {
            temp = temp->Sonraki;
        }
        temp->Sonraki = dugum;
    }
}


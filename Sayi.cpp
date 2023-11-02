//
// Created by Hasan Tayfur on 2.11.2023.
//

#include "Sayi.h"
#include "iostream"
using namespace std;

Sayi::Sayi()
{
    this->IlkBasamak = nullptr;
}

Sayi::~Sayi()
{
    cout << "Sayi silindi" << endl;
    while (this->IlkBasamak != nullptr)
    {
        Basamak *temp = this->IlkBasamak;
        this->IlkBasamak = this->IlkBasamak->Sonraki;
        delete temp;
    }
}

void Sayi::Ekle(Basamak *basamak)
{
    Basamak *temp = this->IlkBasamak;
    if (this->IlkBasamak == nullptr)
    {
        this->IlkBasamak = basamak;
    }
    else
    {
        while (temp->Sonraki != nullptr)
        {
            temp = temp->Sonraki;
        }
        temp->Sonraki = basamak;
    }
}
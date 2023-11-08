//
// Created by Hasan Tayfur on 2.11.2023.
//

#include "Dugum.h"
#include "iostream"
using namespace std;

Dugum::Dugum(Sayi *sayi)
{
    //cout << "Dugum olusturuldu" << endl;
    this->sayi = sayi;
    this->Sonraki = nullptr;
}

Dugum::~Dugum()
{
    cout << "Dugum silindi" << endl;
    delete this->sayi;
}

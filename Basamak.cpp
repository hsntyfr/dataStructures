//
// Created by Hasan Tayfur on 2.11.2023.
//

#include "Basamak.h"
#include "iostream"
using namespace std;
Basamak::Basamak(int basamakDegeri)
{
    this->BasamakDegeri = basamakDegeri;
    this->Sonraki = nullptr;
}

Basamak::~Basamak()
{
    cout << "Basamak silindi" << endl;
    cout << this->BasamakDegeri << endl;
}

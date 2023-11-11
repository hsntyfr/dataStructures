//
// Created by Hasan Tayfur on 2.11.2023.
//

#include "Basamak.h"
#include "iostream"
#include "sstream"
using namespace std;

Basamak::Basamak(int basamakDegeri)
{
    this->BasamakDegeri = basamakDegeri;
    this->Sonraki = nullptr;
}

Basamak::~Basamak()
{
    //cout << "Basamak silindi" << endl;
    //cout << this->BasamakDegeri << endl;
}

string Basamak::To_string()
{
    stringstream ss;
    ss << this;
    return ss.str();
}
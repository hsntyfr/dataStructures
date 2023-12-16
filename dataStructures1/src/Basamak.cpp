/**
* @file             Basamak.cpp
* @description      Bu dosyada basamak sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

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
    //Test kodu silindiğini denetlemek için
    //cout << "Basamak silindi" << endl;
    //cout << this->BasamakDegeri << endl;
}

string Basamak::To_string()
{
    stringstream ss;
    ss << this;
    return ss.str();
}

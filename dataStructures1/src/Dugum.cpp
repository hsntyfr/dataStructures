/**
* @file             Dugum.cpp
* @description      Bu dosyada düğüm sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#include "Dugum.h"
#include "iostream"
using namespace std;

Dugum::Dugum(Sayi *sayi)
{
    //Test kodu düğüm takibi
    //cout << "Dugum olusturuldu" << endl;
    this->sayi = sayi;
    this->Sonraki = nullptr;
}

Dugum::~Dugum()
{
    //Test kodu silindiğini denetlemek için
    //cout << "Dugum silindi" << endl;
    delete this->sayi;
}

void Dugum::TekBasaAl()
{
    Basamak *temp = this->sayi->IlkBasamak;
    Basamak *head = this->sayi->IlkBasamak;
    Basamak *lastTemp = this->sayi->IlkBasamak;
    Basamak *last = nullptr;

    while (lastTemp->Sonraki != nullptr)
    {
        lastTemp = lastTemp->Sonraki;
    }
    last = lastTemp;

    while (this->sayi->IlkBasamak->Sonraki != nullptr && this->sayi->IlkBasamak != last)
    {
        if (temp->BasamakDegeri % 2 == 0)
        {
            temp = temp->Sonraki;
            head->Sonraki = nullptr;
            lastTemp->Sonraki = head;
            this->sayi->IlkBasamak = temp;
        }
        else
        {
            this->sayi->IlkBasamak = this->sayi->IlkBasamak->Sonraki;
            break;
        }
    }
}

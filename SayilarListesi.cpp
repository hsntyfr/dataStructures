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

void SayilarListesi::Yazdir()
{
    Dugum *temp = this->IlkSayi;
    while (temp != nullptr)
    {
        KenarlikOlustur(temp->sayi);
        temp->sayi->YazdirAdres();
        OrtaOlustur(temp->sayi);
        temp->sayi->YazdirVeri();
        KenarlikOlustur(temp->sayi);
        cout << endl;
        temp = temp->Sonraki;
    }
}

void SayilarListesi::KenarlikOlustur(Sayi *sayi)
{
    cout << "##########  ";
    for (int i = 0; i < sayi->BasamakSayisi(); ++i)
    {
        cout << "  *******";
    }
    cout << endl;
}

void SayilarListesi::OrtaOlustur(Sayi *sayi)
{
    cout << "#--------#  ";
    for (int i = 0; i < sayi->BasamakSayisi(); ++i)
    {
        cout << "  *******";
    }
    cout << endl;
}

void SayilarListesi::TekBasaAl()
{
    Basamak *temp = this->IlkSayi->sayi->IlkBasamak;
    Basamak *ilk = this->IlkSayi->sayi->IlkBasamak;



}

/*
void SayilarListesi::YazdirAdres()
{
    Sayi *temp = this->IlkSayi->sayi;
    cout << this->IlkSayi << endl;
    for (int i = 0; i < temp->BasamakSayisi(); ++i)
    {
        cout << temp->IlkBasamak << endl;
        temp->IlkBasamak = temp->IlkBasamak->Sonraki;
    }

    cout << endl;
}*/

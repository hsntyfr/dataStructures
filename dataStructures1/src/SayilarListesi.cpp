/**
* @file             SayilarListesi.cpp
* @description      Bu dosyada sayılar sınıfı sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.h"
#include "iostream"
#include "fstream"

using namespace std;

SayilarListesi::SayilarListesi()
{
    this->IlkSayi = nullptr;
}

SayilarListesi::~SayilarListesi()
{
    //Test kodu silindiğini denetlemek için
    //cout << "SayilarListesi silindi" << endl;
    while (this->IlkSayi != nullptr)
    {
        Dugum *temp = this->IlkSayi;
        this->IlkSayi = this->IlkSayi->Sonraki;
        delete temp;
    }
}

string SayilarListesi::SayiOku(string path)
{
    string sayilar;
    ifstream read("./src/Sayilar.txt");
    if (read.is_open())
    {
        getline(read, sayilar);
    }
    else
    {
        cout << "Dosya acilamadi" << endl;
    }
    read.close();
    return sayilar;
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
    Dugum *temp = this->IlkSayi;
    while (temp != nullptr)
    {
        temp->sayi->TekBasaAl();
        temp->sayi->TekBasaAlOrta();
        //Test kodu işlemi denetlemek için
        temp->sayi->TekBasaAlOrta();
        temp->sayi->TekBasaAlOrta();
        temp->sayi->TekBasaAlOrta();
        temp = temp->Sonraki;
    }
    this->Yazdir();
    cout << endl;
}

void SayilarListesi::BasamaklariTersle()
{
    Dugum *temp = this->IlkSayi;
    while (temp != nullptr)
    {
        temp->sayi->BasamaklariTersle();
        temp = temp->Sonraki;
    }
    this->Yazdir();
}

void SayilarListesi::EnBuyukCikar()
{
    Dugum *temp = this->IlkSayi;
    int highest = 0;
    int number = 0;
    Dugum *deleted = nullptr;
    int counter = this->SayiAdet();

    while (temp != nullptr)
    {
        number = temp->sayi->SayiOlustur();
        if (number > highest)
        {
            highest = number;
            deleted = temp;
        }
        temp = temp->Sonraki;
    }
    temp = this->IlkSayi;

    if (deleted == this->IlkSayi)
    {
        this->IlkSayi = this->IlkSayi->Sonraki;
        delete deleted;
    }
    else if (deleted->Sonraki == nullptr)
    {
        while (temp->Sonraki != deleted)
        {
            temp = temp->Sonraki;
        }
        temp->Sonraki = nullptr;
        delete deleted;
    }
    else
    {
        while (temp->Sonraki != deleted)
        {
            temp = temp->Sonraki;
        }
        temp->Sonraki = temp->Sonraki->Sonraki;
        delete deleted;
    }

    if (counter == 1)
    {
        cout << "Listede eleman kalmadı" << endl;
    }
    else
    {
        this->Yazdir();
        cout << endl;
    }
}

int SayilarListesi::SayiAdet() {
    int count = 0;
    Dugum *temp = this->IlkSayi;

    while (temp != nullptr)
    {
        temp = temp->Sonraki;
        count++;
    }
    return count;
}

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
    //cout << "SayilarListesi silindi" << endl;
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
    int i = 0;
    Dugum *temp = this->IlkSayi;
    while (temp != nullptr)
    {
        //cout << i << endl;
        temp->sayi->TekBasaAl();
        //cout << i << endl;
        i++;
        temp = temp->Sonraki;
    }
    cout << "basarili" << endl;
    //temp->sayi->TekBasaAl();
}

void SayilarListesi::BasamaklariTersle()
{
    Dugum *temp = this->IlkSayi;
    while (temp != nullptr)
    {
        temp->sayi->BasamaklariTersle();
        temp = temp->Sonraki;
    }
}

void SayilarListesi::EnBuyukCikar()
{
    Dugum *temp = this->IlkSayi;
    //çalışan kısım
    /*int highest = 0;
    int number = 0;
    int index = 0;
    Dugum *temp = this->IlkSayi;

    while (temp != nullptr)
    {
        number = temp->sayi->SayiOlustur();
        if (number > highest)
        {
            highest = number;
            index++;
        }
        temp = temp->Sonraki;
    }

    if (index == 0)
    {
        Dugum* deleted = this->IlkSayi;
        this->IlkSayi = this->IlkSayi->Sonraki;
        delete deleted;
        return;
    }

    Dugum* temp2 = this->IlkSayi;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp2->Sonraki == nullptr)
        {
            return;
        }
        temp2 = temp2->Sonraki;
    }
    Dugum* deleted = temp2->Sonraki;
    temp2->Sonraki = temp2->Sonraki->Sonraki;
    delete deleted;*/


   /* int count = (this->SayiAdet() - 1);
    int highest = 0;
    int number = 0;
    int index = 0;
    Dugum *temp = this->IlkSayi;
    Dugum *prev = nullptr;
    Dugum *next = nullptr;

    while (temp != nullptr)
    {
        number = temp->sayi->SayiOlustur();
        if (number > highest)
        {
            highest = number;
            index++;
        }
        temp = temp->Sonraki;
    }

    Dugum *head = this->IlkSayi;

    cout << index << endl;
    cout << count << endl;

    *//*if ((index - 1) == 0)
    {
        temp = this->IlkSayi;
        this->IlkSayi = this->IlkSayi->Sonraki;
        delete temp;
    }*/



    int highest = 0;
    int number = 0;
    int index = 0;
    int counter = 0;
    Dugum *deleted = nullptr;
    counter = this->SayiAdet();

    while (temp != nullptr)
    {
        //cout << temp->sayi->BasamakSayisi() << endl;
        number = temp->sayi->SayiOlustur();
        //cout << number << endl << endl;

        if (number > highest)
        {
            highest = number;
            deleted = temp;
        }
        temp = temp->Sonraki;
    }
    temp = this->IlkSayi;


    //cout << highest << endl;
    //cout << deleted->sayi->SayiOlustur() << endl;

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

    //cout << counter << endl;

    if (counter == 1)
    {
        cout << "Listede eleman kalmadi" << endl;
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

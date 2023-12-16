/**
* @file             Sayi.cpp
* @description      Bu dosyada sayı sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#include "Sayi.h"
#include "iostream"
#include "sstream"
#include "iomanip"
using namespace std;

Sayi::Sayi()
{
    this->IlkBasamak = nullptr;
}

Sayi::~Sayi()
{
    //Test kodu silindiğini denetlemek için
    //cout << "Sayi silindi" << endl;
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

void Sayi::Yazdir()
{
    Basamak *temp = this->IlkBasamak;
    while (temp != nullptr)
    {
        cout << temp->BasamakDegeri << endl;
        temp = temp->Sonraki;
    }
    cout << endl;
}

int Sayi::BasamakSayisi()
{
    int basamakSayisi = 0;
    Basamak *temp = this->IlkBasamak;
    while (temp != nullptr)
    {
        basamakSayisi++;
        temp = temp->Sonraki;
    }
    return basamakSayisi;
}

void Sayi::YazdirAdres()
{
    Sayi *temp = this;
    #if defined(_WIN32)
        cout << "#" << setw(8) << temp->To_string().substr(1) << "#    ";
        Basamak *temp2 = this->IlkBasamak;
        while (temp2 != nullptr)
        {
            cout << "*" << setw(4) << temp2->To_string().substr(6) << " *  ";
            temp2 = temp2->Sonraki;
        }
        cout << endl;
    #elif defined(__APPLE__) && defined(__MACH__)
    cout << "#" << temp->To_string().substr(6) << "#    ";
    Basamak *temp2 = this->IlkBasamak;
    while (temp2 != nullptr)
    {
        //cout << temp << endl;
        cout << "* " << temp2->To_string().substr(11) << " *  ";
        temp2 = temp2->Sonraki;
    }
    cout << endl;
    #endif
}

int Sayi::SayiOlustur()
{
    Basamak *temp = this->IlkBasamak;
    string veri = "";
    int veriInt = 0;
    while (temp != nullptr)
    {
        veri += to_string(temp->BasamakDegeri);
        temp = temp->Sonraki;
    }
    veriInt = stoi(veri);
    return veriInt;
}

void Sayi::YazdirVeri()
{
    cout << "#" << setw(8) << this->SayiOlustur() << "#    ";
    Basamak *temp2 = this->IlkBasamak;
    while (temp2 != nullptr)
    {
        cout << "*   " << temp2->BasamakDegeri << " *  ";
        temp2 = temp2->Sonraki;
    }
    cout << endl;
}

string Sayi::To_string()
{
    stringstream ss;
    ss << this;
    return ss.str();
}

void Sayi::BasamaklariTersle()
{
    Basamak *temp = this->IlkBasamak;
    Basamak *temp2 = nullptr;
    Basamak *prev = nullptr;

    while (temp != nullptr)
    {
        temp2 = temp->Sonraki;
        temp->Sonraki = prev;
        prev = temp;
        temp = temp2;
    }
    this->IlkBasamak = prev;
}


void Sayi::TekBasaAl()
{
    Basamak *endtemp = nullptr;
    Basamak *temp = this->IlkBasamak;
    Basamak *temp2 = this->IlkBasamak;
    Basamak *head = this->IlkBasamak;
    Basamak *end = this->IlkBasamak;
    int count = this->BasamakSayisi();

    while (end->Sonraki != nullptr)
    {
        end = end->Sonraki;
    }
    endtemp = end;

    while (temp != endtemp) {
        if (temp->BasamakDegeri % 2 == 0 && count > 1 && temp == head)
        {
            temp2 = temp;
            head = head->Sonraki;
            temp2->Sonraki = nullptr;
            end->Sonraki = temp2;
            end = end->Sonraki;
            this->IlkBasamak = head;
            temp = head;
        }
        else
        {
            temp = temp->Sonraki;
        }
    }
}

void Sayi::TekBasaAlOrta()
{
    Basamak *temp = this->IlkBasamak;
    Basamak *temp2 = this->IlkBasamak;
    Basamak *head = this->IlkBasamak;
    Basamak *end = this->IlkBasamak;
    Basamak *headTemp = this->IlkBasamak;
    int count = this->BasamakSayisi();

    while (end->Sonraki != nullptr)
    {
        end = end->Sonraki;
    }
    if (count > 2)
    {
        while (temp->Sonraki->Sonraki != nullptr)
        {
            if (temp->Sonraki->BasamakDegeri % 2 == 0 && temp->Sonraki->Sonraki->Sonraki != nullptr)
            {
                //cout << temp->BasamakDegeri << endl;
                temp2 = temp->Sonraki;
                temp->Sonraki = temp->Sonraki->Sonraki;
                temp2->Sonraki = nullptr;
                end->Sonraki = temp2;
                end = end->Sonraki;
            }
            temp = temp->Sonraki;
        }
    }
}

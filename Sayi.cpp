//
// Created by Hasan Tayfur on 2.11.2023.
//

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

void Sayi::Yazdir()
{
    Basamak *temp = this->IlkBasamak;
    while (temp != nullptr)
    {
        //cout << temp << endl;
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
    cout << "#" << temp->To_string().substr(6) << "#    ";
    Basamak *temp2 = this->IlkBasamak;
    while (temp2 != nullptr)
    {
        //cout << temp << endl;
        cout << "* " << temp2->To_string().substr(11) << " *  ";
        temp2 = temp2->Sonraki;
    }
    cout << endl;
}

void Sayi::SayiOlustur()
{
    Basamak *temp = this->IlkBasamak;
    string veri = "";
    while (temp != nullptr)
    {
        veri += to_string(temp->BasamakDegeri);
        temp = temp->Sonraki;
    }
    cout << "#" << setw(8) << veri << "#    ";
}

void Sayi::YazdirVeri()
{
    Sayi *temp = this;
    this->SayiOlustur();
    /*while (temp->IlkBasamak->Sonraki != nullptr)
    {
        veri += to_string(temp->IlkBasamak->BasamakDegeri);
        temp->IlkBasamak = temp->IlkBasamak->Sonraki;
    }*/
    //cout << "#" << veri << "#    ";
    Basamak *temp2 = this->IlkBasamak;
    while (temp2 != nullptr)
    {
        //cout << temp << endl;
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

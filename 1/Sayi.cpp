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
    //cout << "#" << setw(8) << veri << "#    ";
    return veriInt;
}

void Sayi::YazdirVeri()
{
    cout << "#" << setw(8) << this->SayiOlustur() << "#    ";
    //this->SayiOlustur();
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

int calismaSayisi = 0;

Basamak *endtemp = nullptr;

void Sayi::TekBasaAl()
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
    endtemp = end;


    while (temp != endtemp)
    {
        if (temp->BasamakDegeri % 2 == 0 && count > 1 && temp == head)
        {
            temp2 = temp;

            head = head->Sonraki;

            temp2->Sonraki = nullptr;

            end->Sonraki = temp2;

            end = end->Sonraki;

            this->IlkBasamak = head;
            temp = head;
            calismaSayisi++;
        }
        else
        {
            temp = temp->Sonraki;
        }
    }

    temp = this->IlkBasamak;
    temp2 = this->IlkBasamak;
    head = this->IlkBasamak;
    endtemp = nullptr;
    end = this->IlkBasamak;





    /*if (temp->BasamakDegeri % 2 == 0 && count > 1 && temp == headTemp)
    {
        temp2 = temp;

        head = head->Sonraki;

        temp2->Sonraki = nullptr;

        end->Sonraki = temp2;

        end = end->Sonraki;

        this->IlkBasamak = head;
    }*/
    /*while (temp == endtemp)
    {
        if (temp->BasamakDegeri % 2 == 0)
        {
            if (temp == head)
            {
                temp2 = temp;
                temp = temp->Sonraki;
                temp2->Sonraki == nullptr;
                end->Sonraki = temp2;
                end = end->Sonraki;
            }
        }
        temp = temp->Sonraki;
    }*/
    //çalışıyor ama adresleri değişti new olmadan yap
    /*Basamak *temp = this->IlkBasamak;
    Basamak *temp2 = this->IlkBasamak;

    Basamak *added;
    Sayi *evens = new Sayi();
    Sayi *odds = new Sayi();
    Basamak *oddsTemp = nullptr;

    int a;

    while (temp != nullptr)
    {
        a = temp->BasamakDegeri;
        if (temp->BasamakDegeri % 2 == 0)
        {
            temp2 = temp;
            //temp2->Sonraki = nullptr;
            added = new Basamak(temp2->BasamakDegeri);
            evens->Ekle(added);
            cout << added->BasamakDegeri << endl;
        }
        else
        {
            temp2 = temp;
            //temp2->Sonraki = nullptr;
            added = new Basamak(temp2->BasamakDegeri);
            odds->Ekle(added);
            cout << added->BasamakDegeri << endl;
        }
        temp = temp->Sonraki;
    }

    cout<< endl << evens->BasamakSayisi() << endl;
    cout << odds->BasamakSayisi() << endl;

    if (odds->BasamakSayisi() > 0)
    {
        oddsTemp = odds->IlkBasamak;
        while (oddsTemp->Sonraki != nullptr)
        {
            oddsTemp = oddsTemp->Sonraki;
        }
        if (evens->BasamakSayisi() > 0)
        {
            oddsTemp->Sonraki = evens->IlkBasamak;
            this->IlkBasamak = odds->IlkBasamak;
        }
        else
        {
            this->IlkBasamak = odds->IlkBasamak;
        }
    }

    evens = nullptr;
    odds = nullptr;
    delete evens;
    delete odds;*/
}

void Sayi::TekBasaAl2()
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
                cout << temp->BasamakDegeri << endl;
                temp2 = temp->Sonraki;
                temp->Sonraki = temp->Sonraki->Sonraki;
                temp2->Sonraki = nullptr;
                end->Sonraki = temp2;
                end = end->Sonraki;
            }
            temp = temp->Sonraki;
        }
    }
    cout << endl;

    /*Basamak *temp = this->IlkBasamak;
    Basamak *temp2 = this->IlkBasamak;
    Basamak *head = this->IlkBasamak;
    Basamak *end = this->IlkBasamak;
    Basamak *endtemp = nullptr;
    Basamak *headTemp = this->IlkBasamak;

    int count = this->BasamakSayisi();


    while (end->Sonraki != nullptr)
    {
        end = end->Sonraki;
    }
    endtemp = end;

    for (int i = 0; i < this->BasamakSayisi() - calismaSayisi; i++)
    {

        if (temp->BasamakDegeri % 2 == 0)
        {
            temp2 = temp;
            head = temp->Sonraki;
            temp2->Sonraki = nullptr;
            this->IlkBasamak = head;
            end->Sonraki = temp2;
            temp = head;
        }
        else
        {
            temp = temp->Sonraki;

        }
    }*/
}





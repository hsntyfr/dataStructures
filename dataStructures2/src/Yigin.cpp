#include "Yigin.h"
#include<iostream>

using namespace std;

Yigin::Yigin()
{
    Tepe = 0;
}

Yigin::~Yigin()
{

}

void Yigin::Ekle(int veri)
{
    DugumYigin* yeni = new DugumYigin(veri);
    if (Tepe != 0)
    {
        yeni->Sonraki = Tepe;
    }
    Tepe = yeni;
}

void Yigin::Temizle()
{
    while (Tepe != NULL)
    {
        DugumYigin* silinecek = Tepe;
        Tepe = Tepe->Sonraki;
        delete silinecek;
    }
}

void Yigin::Cikar()
{
    if (Tepe != 0)
    {
        DugumYigin* silinecek = Tepe;
        Tepe = Tepe->Sonraki;
        delete silinecek;
    }
}

int Yigin::Getir()
{
    if (Tepe != 0)
    {
        return Tepe->Veri;
    }
    else
    {
        return -1;
    }
}
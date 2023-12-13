#include "Yigin.h"
#include<iostream>
using namespace std;

Yigin::Yigin()
{
    tepe = 0;
}
Yigin::~Yigin()
{
    //cout << "yigindan sayi silindi" << endl;
}
void Yigin::ekle(int veri)
{
    DugumYigin* yeni = new DugumYigin(veri);
    if (tepe != 0)
        yeni->sonraki = tepe;
    tepe = yeni;
}
void Yigin::temizle()
{
    while (tepe != NULL)
    {
        DugumYigin* silinecek = tepe;
        tepe = tepe->sonraki;
        delete silinecek;
    }
}
void Yigin::cikar()

{
    if (tepe != 0)
    {
        DugumYigin* silinecek = tepe;
        tepe = tepe->sonraki;
        delete silinecek;

    }

}

int Yigin::getir()
{
    if (tepe != 0)
    {
        return tepe->veri;
    }
    else
    {
        return -1;
    }
    
}
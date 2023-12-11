#include "Yigin.h"
#include<iostream>
using namespace std;

Yigin::Yigin()
{
    tepe = 0;
}
void Yigin::ekle(int veri)
{
    DugumYigin* yeni = new DugumYigin(veri);
    if (tepe != 0)
        yeni->sonraki = tepe;
    tepe = yeni;
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
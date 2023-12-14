#ifndef Yigin_h
#define Yigin_h
#include "DugumYigin.h"
#include<exception>
#include<iostream>
#include <iomanip>

using namespace std;

class Yigin
{
public:
    Yigin();
    ~Yigin();
    void Ekle(int veri);
    void Cikar();
    void Temizle();
    int Getir();

    DugumYigin* Tepe;
};

#endif
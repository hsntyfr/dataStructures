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
    void ekle(int veri);

    void cikar();
    void temizle();

    int getir();
private:
    DugumYigin* tepe;
};

#endif
/**
* @file             Sayi.h
* @description      Bu dosyada sayı sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#ifndef VERIYAPILARI2_SAYI_H
#define VERIYAPILARI2_SAYI_H
#include "Basamak.h"
#include "iostream"
using namespace std;

class Sayi {

public:
    Sayi();
    ~Sayi();
    void Ekle(Basamak *basamak);
    void Yazdir();
    int BasamakSayisi();
    void YazdirAdres();
    void YazdirVeri();
    int SayiOlustur();
    string To_string();
    void BasamaklariTersle();
    void TekBasaAl();
    void TekBasaAlOrta();

    Basamak *IlkBasamak;
};

#endif //VERIYAPILARI2_SAYI_H

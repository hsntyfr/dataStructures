//
// Created by Hasan Tayfur on 2.11.2023.
//

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
    void TekBasaAl2();






    Basamak *IlkBasamak;

};


#endif //VERIYAPILARI2_SAYI_H

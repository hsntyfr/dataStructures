/**
* @file             SayilarListesi.h
* @description      Bu dosyada sayılar listesi sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#ifndef VERIYAPILARI2_SAYILARLISTESI_H
#define VERIYAPILARI2_SAYILARLISTESI_H
#include "Dugum.h"

class SayilarListesi {
public:
    SayilarListesi();
    ~SayilarListesi();
    string SayiOku(string path);
    void Ekle(Dugum *dugum);
    void Yazdir();
    void KenarlikOlustur(Sayi *sayi);
    void OrtaOlustur(Sayi *sayi);
    void TekBasaAl();
    void BasamaklariTersle();
    void EnBuyukCikar();
    int SayiAdet();


    Dugum *IlkSayi;
};

#endif //VERIYAPILARI2_SAYILARLISTESI_H

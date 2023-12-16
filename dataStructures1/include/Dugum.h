/**
* @file             Dugum.h
* @description      Bu dosyada düğüm sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#ifndef VERIYAPILARI2_DUGUM_H
#define VERIYAPILARI2_DUGUM_H
#include "Sayi.h"

class Dugum {
public:
    Dugum(Sayi *sayi);
    ~Dugum();
    void TekBasaAl();
    Sayi *sayi;
    Dugum *Sonraki;

};

#endif //VERIYAPILARI2_DUGUM_H

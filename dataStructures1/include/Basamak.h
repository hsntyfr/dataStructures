/**
* @file             Basamak.h
* @description      Bu dosyada basamak sınıfı yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#ifndef VERIYAPILARI2_BASAMAK_H
#define VERIYAPILARI2_BASAMAK_H
#include "iostream"
using namespace std;

class Basamak{
public:
    Basamak(int basamakDegeri);
    ~Basamak();
    string To_string();

    int BasamakDegeri;
    Basamak *Sonraki;
};

#endif //VERIYAPILARI2_BASAMAK_H

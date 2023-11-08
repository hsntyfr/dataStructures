//
// Created by Hasan Tayfur on 2.11.2023.
//

#ifndef VERIYAPILARI2_SAYILARLISTESI_H
#define VERIYAPILARI2_SAYILARLISTESI_H
#include "Dugum.h"



class SayilarListesi {
public:
    SayilarListesi();
    ~SayilarListesi();

    void Ekle(Dugum *dugum);
    void Yazdir();
    void KenarlikOlustur(Sayi *sayi);
    void OrtaOlustur(Sayi *sayi);
    void TekBasaAl();
    void BasamaklariTersle();
    void EnBuyukCikar();


    //void YazdirAdres();

    Dugum *IlkSayi;
};


#endif //VERIYAPILARI2_SAYILARLISTESI_H

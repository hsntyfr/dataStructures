//
// Created by Hasan Tayfur on 2.11.2023.
//

#ifndef VERIYAPILARI2_SAYILARLISTESI_H
#define VERIYAPILARI2_SAYILARLISTESI_H
#include "Sayi.h"
#include "Dugum.h"


class SayilarListesi {
public:
    SayilarListesi();
    ~SayilarListesi();

    void Ekle(Dugum *dugum);

    Dugum *IlkSayi;
};


#endif //VERIYAPILARI2_SAYILARLISTESI_H

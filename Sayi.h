//
// Created by Hasan Tayfur on 2.11.2023.
//

#ifndef VERIYAPILARI2_SAYI_H
#define VERIYAPILARI2_SAYI_H
#include "Basamak.h"


class Sayi {

public:
    Sayi();
    ~Sayi();

    void Ekle(Basamak *basamak);

    Basamak *IlkBasamak;

};


#endif //VERIYAPILARI2_SAYI_H

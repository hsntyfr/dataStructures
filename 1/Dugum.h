//
// Created by Hasan Tayfur on 2.11.2023.
//

#ifndef VERIYAPILARI2_DUGUM_H
#define VERIYAPILARI2_DUGUM_H
#include "Sayi.h"


class Dugum {
public:
    Dugum(Sayi *sayi);
    ~Dugum();
    Sayi *sayi;
    Dugum *Sonraki;

};


#endif //VERIYAPILARI2_DUGUM_H

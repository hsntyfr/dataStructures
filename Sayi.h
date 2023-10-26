//
// Created by Hasan Tayfur on 26.10.2023.
//

#ifndef VERIYAPILARI_SAYI_H
#define VERIYAPILARI_SAYI_H
#include "Sayi.h"
#include "Basamak.h"

class Sayi {
public:
    Sayi();
    ~Sayi();
    void Add(Basamak* basamak);
    void Print();

    Basamak* SayiHead;
    Sayi* Next;
};


#endif //VERIYAPILARI_SAYI_H

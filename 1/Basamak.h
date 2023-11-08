//
// Created by Hasan Tayfur on 2.11.2023.
//

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

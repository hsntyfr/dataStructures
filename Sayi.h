//
// Created by Hasan Tayfur on 26.10.2023.
//

#ifndef UNTITLED2_SAYI_H
#define UNTITLED2_SAYI_H
#include "Node.h"
#include "Basamak.h"

class Sayi {
public:
    Sayi();
    ~Sayi();

    void Add(Basamak* basamak);


private:
    Node* Head;

};


#endif //UNTITLED2_SAYI_H

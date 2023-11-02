//
// Created by Hasan Tayfur on 26.10.2023.
//

#ifndef VERI_YAPILARI_1_LINKEDLIST_H
#define VERI_YAPILARI_1_LINKEDLIST_H

#include "Node.h"


class Basamak {
public:
    Basamak();
    ~Basamak();

    void Add(int data);

    Node* Head;
};


#endif //VERI_YAPILARI_1_LINKEDLIST_H

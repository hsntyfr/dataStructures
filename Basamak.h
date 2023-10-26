//
// Created by Hasan Tayfur on 26.10.2023.
//

#ifndef VERIYAPILARI_BASAMAK_H
#define VERIYAPILARI_BASAMAK_H

#include "Node.h"


class Basamak {
    public:
    Basamak();
    ~Basamak();
    void Add(int data);

    Node* BasamakHead;
    Basamak* Next;
};


#endif //VERIYAPILARI_BASAMAK_H

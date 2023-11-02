//
// Created by Hasan Tayfur on 26.10.2023.
//

#ifndef VERI_YAPILARI_1_Node_H
#define VERI_YAPILARI_1_Node_H


#include "Basamak.h"


class Node{
public:
    Node(int data);
    Node(Basamak* basamak);
    ~Node();

    int Data;
    Node* Next;
};


#endif //VERI_YAPILARI_1_Node_H

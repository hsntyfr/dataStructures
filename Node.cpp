//
// Created by Hasan Tayfur on 26.10.2023.
//

#include <iostream>
#include "Node.h"
#include "Basamak.h"
#include "Sayi.h"


using namespace std;

Node::Node(int data) {
    this->Data = data;
    this->Next = NULL;
}

Node::Node(Basamak *basamak) {
    this->Data = basamak->Head;
    this->Next = NULL;
}

Node::~Node() {
    cout << "Node deleted" << endl;
}



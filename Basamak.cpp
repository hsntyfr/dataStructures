//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Basamak.h"

Basamak::Basamak() {
    Head = nullptr;
}

Basamak::~Basamak() {
    Node* temp = Head;
    while (temp != nullptr) {
        Node* next = temp->Next;
        delete temp;
        temp = next;
    }
}

void Basamak::Add(int data) {
    Node* newNode = new Node(data);
    if (Head == nullptr) {
        Head = newNode;
    }
    else {
        Node* temp = Head;
        while (temp->Next != nullptr) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

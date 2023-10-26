//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Sayi.h"
#include "Node.h"

Sayi::Sayi() {
    Head = nullptr;
}

Sayi::~Sayi() {
    Node* temp = Head;
    while (temp != nullptr) {
        Node* next = temp->Next;
        delete temp;
        temp = next;
    }
}


void Sayi::Add(int data) {
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
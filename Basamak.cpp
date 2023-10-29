//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Basamak.h"
#include <iostream>

Basamak::Basamak(int data)
{
    Data = data;
    Next = nullptr;
}

Basamak::~Basamak() {
    std::cout << "basamak silme çağrıldı" << std::endl;

}





//
// Created by Hasan Tayfur on 26.10.2023.
//

#include "Node.h"
#include <iostream>


Node::Node(int data) {
    Data = data;
    Next = NULL;
}

Node::~Node() {
    std::cout << "Node deleted" << std::endl;
}


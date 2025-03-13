#include <iostream>
#include "QueueElement.h"
#pragma once
using namespace std;

class Queue {
    QueueData* front;
    QueueData* rear;
public:
    Queue();
    bool empty() const;
    char* frontValue();
    void pop();
    void push(const char* n);
    void displayQueue() const;
    ~Queue();
};
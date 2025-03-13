#include <iostream>
#pragma once
using namespace std;
#define MAX_CHAR_SIZE 13

class QueueData {
public:
    char data[MAX_CHAR_SIZE];
    QueueData* next;
    QueueData(const char* n);
    ~QueueData();
};

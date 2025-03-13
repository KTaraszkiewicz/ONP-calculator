#include "StackElement.h"

StackData::StackData(const char *n)
{
    strncpy_s(data, n, _TRUNCATE);
    this->under = nullptr;
}
StackData::~StackData(){}

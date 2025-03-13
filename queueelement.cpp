#include "QueueElement.h"

QueueData::QueueData(const char* n)
{
    strncpy_s(data, n, _TRUNCATE);
    this->next = nullptr;
}
QueueData::~QueueData() {}
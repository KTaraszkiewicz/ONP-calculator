#include "queue.h"
using namespace std;

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

bool Queue::empty() const
{
    return front == NULL;
}

char* Queue::frontValue()
{
    if (!empty())
        return front->data;
    else {
        printf("Cannot give front value while empty");
        exit(1);
    }
}

void Queue::pop()
{
    if (front == NULL) {
        printf("\nQueue empty!");
        exit(1);
    }
    else {
        QueueData* temp;
        temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::push(const char* n)
{
    QueueData* temp = new QueueData(n);
    if (!temp) {
        printf("\nTemporary QueueData Error!");
        exit(1);
    }
    temp->next = nullptr;
    if (empty())
    {
        front = rear = temp;
    }
    else {
        rear->next = temp; 
        rear = temp; 
    }
}

void Queue::displayQueue() const
{
    QueueData* temp;
    if (empty()) {
        printf("\nQueue empty!");
        exit(1);
    }
    else {
        temp = front;
        while (temp != NULL) {
            printf("%s", temp->data);
            temp = temp->next;
            if (temp != NULL)
                printf("  ");
        }
    }
    printf("\n");
}

Queue::~Queue()
{
    while (!empty()) {
        pop();
    }
    delete front;
}
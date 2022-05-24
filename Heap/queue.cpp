#include "queue.h"

Queue::Queue()
{
    this->arr = NULL;
    this->rear = -1;
    this->front = 0;
    this->size = 0;
}

Queue::Queue(int size)
{
    this->size = size;
    this->arr = new item[this->size];
    this->front = 0;
    this->rear = -1;
}

bool Queue::is_empty()
{
    return this->rear == -1;
}

bool Queue::is_full()
{
    return this->rear == this->size - 1;
}

void Queue::push(item value)
{
    if(!is_full())
    {
        this->arr[++rear] = value;
    }
}

void Queue::pop()
{
    if(!is_empty())
    {
        this->front = this->front + 1;
    }
}

item Queue::top()
{
    if(!is_empty())
    {
        return this->arr[this->front];
    }

    return INT_MIN;
}
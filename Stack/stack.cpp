#include "stack.h"

Stack::Stack()
{
    this->arr = NULL;
    this->size = 0;
    this->tos = -1;
}

Stack::Stack(int size)
{
    this->size = size;
    this->arr = new item[this->size];
    this->tos = -1;
}

bool Stack::is_empty()
{
    return this->tos == -1;
}

bool Stack::is_full()
{
    return this->tos == this->size - 1;
}

void Stack::push(item value)
{
    if (!is_full())
        this->arr[++tos] = value;
}

item Stack::top()
{
    if(!is_empty())
        return this->arr[this->tos];
    
    return INT_MIN;
}

void Stack::pop()
{
    if(!is_empty())
        this->tos--;
}
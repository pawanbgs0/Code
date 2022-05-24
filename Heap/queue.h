#include <bits/stdc++.h>
using namespace std;

#define item int

class Queue
{
    item* arr;
    int size;
    int front;
    int rear;
    public:
        Queue();
        Queue(int size);
        bool is_empty();
        bool is_full();
        void push(item value);
        void pop();
        item top();
};
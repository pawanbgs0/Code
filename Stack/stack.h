#include <bits/stdc++.h>
using namespace std;

#define item int


class Stack
{   
    item* arr;
    int size;
    int tos;
    public:
        Stack();
        Stack(int size);
        bool is_full();
        bool is_empty();
        void push(item value);
        item top();
        void pop();
};

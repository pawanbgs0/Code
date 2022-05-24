#include <bits/stdc++.h>
using namespace std;

class Banker
{
    public:
    int no_of_process;
    int no_of_type;
    vector<vector<int>> alloc;
    vector<vector<int>> max;
    vector<vector<int>> need;
    vector<int> max_instance;
    vector<int> available;
    vector<bool> flag;
    bool can_use(vector<int> test);

    public:
        Banker(int no_of_process, int no_of_type);
        void take_input();
        void display();
        vector<int> calculate();
};
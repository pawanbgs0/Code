#include <bits/stdc++.h>
using namespace std;

class Job
{   
    public:
        int start_time;
        int finish_time;

        Job(int start_time, int finish_time);
};

bool comp(Job &j1, Job &j2);
vector<Job> activity_selection(vector<Job> data);
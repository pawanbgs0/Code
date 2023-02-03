#include <bits/stdc++.h>
using namespace std;

class Job
{
    public:
        char id;
        int deadline;
        int profit;

        Job(char id, int deadline, int profit);
};

bool comp(Job &j1, Job &j2);

// fuction to reture the secquence that lead to max profit
vector<Job> job_secquence(vector<Job> data);
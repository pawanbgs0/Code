#include "js.h"

Job::Job(char id, int deadline, int profit)
{
    this->id = id;
    this->deadline = deadline;
    this->profit = profit;
}


bool comp(Job &j1, Job &j2)
{
    return j1.profit > j2.profit;
}

vector<Job> job_secquence(vector<Job> data)
{
    vector<Job> res;
    int max_deadline;

    sort(data.begin(), data.end(), comp);

    for (int i = 0; i < data.size(); i++)
    {
        max_deadline = max(max_deadline, data[i].deadline);
        // cout << data[i].id << "\t\t" << data[i].deadline << "\t\t" << data[i].profit << endl;
    }

    res.push_back(data[0]);
    int curr_deadline = data[0].deadline;

    for (int i = 1; i < data.size(); i++)
    {
        if (res.size() == max_deadline)
            break;

        if (data[i].deadline >= curr_deadline)
        {
            res.push_back(data[i]);
            curr_deadline = data[i].deadline;
        }
    }

    return res;
}
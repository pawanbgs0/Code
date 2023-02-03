#include "as.h"

Job::Job(int start_time, int finish_time)
{
    this->start_time = start_time;
    this->finish_time = finish_time;
}


bool comp(Job &j1, Job &j2)
{
    return j1.finish_time < j2.finish_time;
}

vector<Job> activity_selection(vector<Job> data)
{
    vector<Job> res;
    int res_index = 0;

    if (data.size() == 0)
        return res;

    sort(data.begin(), data.end(), comp);

    Job temp(data[0].start_time, data[0].finish_time);
    res.push_back(temp);

    for (int i = 1; i < data.size(); i++)
    {
        if (data[i].start_time >= res[res_index].finish_time)
        {
            Job tmp(data[i].start_time, data[i].finish_time);
            res.push_back(tmp);

            res_index++;
        }
    }

    return res;
}
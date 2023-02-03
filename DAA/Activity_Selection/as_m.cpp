#include "as.h"

int main()
{
    // Input: start[]  =  {10, 12, 20}, finish[] =  {20, 25, 30}

    // start[]  =  {1, 3, 0, 5, 8, 5}, finish[] =  {2, 4, 6, 7, 9, 9};
    vector<Job> job;
    vector<Job> res;

    job.push_back(Job(1, 2));
    job.push_back(Job(3, 4));
    job.push_back(Job(0, 6));
    job.push_back(Job(5, 7));
    job.push_back(Job(8, 9));
    job.push_back(Job(5, 9));

    res = activity_selection(job);

    cout << "The optimal activity selection is: " << endl;

    cout << "Start Time \t Finish Time" << endl;

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].start_time << "\t\t\t" << res[i].finish_time << endl;
    }
    return 0;
}
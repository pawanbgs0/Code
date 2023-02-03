#include "js.h"

// JobID   Deadline  Profit

// a            2          100
// b            1          19
// c            2          27
// d            1          25
// e            3          15


int main()
{
    vector<Job> job;
    vector<Job> res;
    int max_proft = 0;

    job.push_back(Job('a', 2, 100));
    job.push_back(Job('b', 1, 19));
    job.push_back(Job('c', 2, 27));
    job.push_back(Job('d', 1, 25));
    job.push_back(Job('e', 3, 15));

    res = job_secquence(job);

    cout << "The job secquence that generates maximum profit is: " << endl;
    cout << "Id\tDeadline\tProfit" << endl;

    for (int i = 0; i < res.size(); i++)
    {
        max_proft += res[i].profit;

        cout << res[i].id << "\t" << res[i].deadline << "\t\t" << res[i].profit << endl;
    }

    cout << endl << "And the maximum profit is: " << max_proft << "." << endl;
    return 0;
}
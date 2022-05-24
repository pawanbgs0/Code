#include "banker.h"

Banker::Banker(int no_of_process, int no_of_type)
{
    this->no_of_process = no_of_process;
    this->no_of_type = no_of_type;
    this->alloc.resize(no_of_process, vector<int> (no_of_type));
    this->max.resize(no_of_process, vector<int> (no_of_type));
    this->need.resize(no_of_process, vector<int> (no_of_type));
    this->max_instance.resize(no_of_type);
    this->available.resize(no_of_type);
    this->flag.resize(no_of_process + 1, false);
}

void Banker::take_input()
{
    cout << "Enter the value of Allocations: " << endl;

    for (int i = 0; i < no_of_process; i++)
    {
        cout << "For Process " << i << ": " << endl;
        for (int j = 0; j < no_of_type; j++)
        {
            cout << "The value of type " << j << ": ";
            cin >> this->alloc[i][j];
        }
    }

    cout << endl << endl;

    cout << "Enter the Maximum Allocation: " << endl;

    for (int i = 0; i < no_of_process; i++)
    {
        cout << "For Process " << i << ": " << endl;

        for (int j = 0; j < no_of_type; j++)
        {
            cout << "The value of type " << j << ": ";
            cin >> this->max[i][j];
        }
    }

    cout << "Enter the values of Max instances of: " << endl;

    for (int i = 0; i < no_of_type; i++)
    {
        cout << "Type " << i << ": ";
        cin >> this->max_instance[i];
    }

    cout << "Input Completed, Thank You!" << endl;
}

void Banker::display()
{
    cout << "The value of Allocations are: " << endl;

    for (int i = 0; i < no_of_process; i++)
    {
        cout << "For Process " << i << ": " << endl;
        for (int j = 0; j < no_of_type; j++)
        {
            cout << this->alloc[i][j] << endl;
        }
    }

    cout << endl << endl;

    cout << "The Maximum Allocation: " << endl;

    for (int i = 0; i < no_of_process; i++)
    {
        cout << "For Process " << i << ": " << endl;

        for (int j = 0; j < no_of_type; j++)
        {
            cout << this->max[i][j] << endl;
        }
    }

    cout << "The values of Max instances of: " << endl;

    for (int i = 0; i < no_of_type; i++)
    {
        cout << "Type " << i << ": ";
        cout << this->max_instance[i] << endl;
    }

    cout << "Output Completed, Thank You!" << endl;
}

bool Banker::can_use(vector<int> need)
{
    for (int i = 0; i < need.size(); i++)
    {
        if (need[i] > this->available[i])
            return false;
    }
    return true;
}

vector<int> Banker::calculate()
{
    vector<int> safe_sequence;
    vector<int> temp(no_of_type, 0);

    for (int i = 0; i < no_of_process; i++)
    {
        
        for (int j = 0; j < no_of_type; j++) //to calculate the needs
        {
            this->need[i][j] = this->max[i][j] - this->alloc[i][j];
        }
    }

    for (int i = 0; i < no_of_type; i++)
    {
        for (int j = 0; j < no_of_process; j++)
        {
            this->available[i] += this->alloc[j][i];
        }
        this->available[i] = this->max_instance[i] - this->available[i];
    }

    int i = 0;
    int count = 0;
    while (i < no_of_process)
    {
        if (count == no_of_process)
            break;

        if (flag[i] == false)
        { 
            if (can_use(this->need[i]))
            {
                for (int j = 0; j < this->no_of_type; j++)
                {
                    this->available[j] += this->alloc[i][j];
                }
                this->flag[i] = true;
                safe_sequence.push_back(i);
                count++;
                // i = 0;
            }
        }
        i++;
        if (i >= no_of_process)
            i = 0;
    }
    return safe_sequence;
}
#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int id;
    int weight;
    int value;
};

bool comp(Data &d1, Data &d2)
{
    return (d1.value / (d1.weight * 1.0)) > (d2.value / (d2.weight * 1.0));
}

double fractionalKnapsack(vector<Data> items, int capacity)
{
    double res = 0;
    int index = 0;

    sort(items.begin(), items.end(), comp);

    for (index = 0; index < items.size(); index++)
    {
        if (capacity < items[index].weight)
            break;
        
        res += items[index].value;
        capacity -= items[index].weight;
    }

    double ratio = items[index].value / (items[index].weight * 1.0);
    res += (capacity * ratio);

    return res;
}

int main()
{
    vector<Data> input;
    int size, capacity;

    cout << "Enter the size of Input: ";
    cin >> size;

    cout << "Enter the capacity of Bag: ";
    cin >> capacity;

    for (int i = 0; i < size; i++)
    {
        Data temp;
        
        cout << "Enter the id of item " << i + 1 << ": ";
        cin >> temp.id;

        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> temp.weight;

        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> temp.value;

        input.push_back(temp);
    }

    cout << "The maximum Profit a robber can rob is " << fractionalKnapsack(input, capacity) << "." << endl;


    return 0;
}
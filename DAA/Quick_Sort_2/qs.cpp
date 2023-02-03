#include "qs.h"

int partition(int startIndex, int endIndex, vector<int> &arr)
{
    int i = startIndex -1;
    int j = startIndex;
    int pivot = arr[endIndex];

    while (j <= endIndex)
    {
        if (arr[j] < pivot)
        {
            swap(arr[++i], arr[j++]);
        }
        
        else 
            j++;
    }
    swap(arr[++i], arr[endIndex]); // swapping i with pivot;

    return i;
}

void quick_sort(int startIndex, int endIndex, vector<int> &arr)
{
    if (startIndex >= endIndex)
        return;

    int pivot = partition(startIndex, endIndex, arr);

    quick_sort(startIndex, pivot - 1, arr);
    quick_sort(pivot + 1, endIndex, arr);
}


vector<int> random_vector(int size)
{
    vector<int> res;

    srand(time(0));

    for (int i = 0; i < size; i++)
        res.push_back(rand());

    return res;
}

void time_measure_to_sort(int no_iteration, int size_of_vector)
{
    for (int i = 0; i < no_iteration; i++)
    {
        int size = rand() % size_of_vector;

        vector<int> temp = random_vector(size_of_vector);

        // Get starting timepoint
        auto start = high_resolution_clock::now();

        quick_sort(0, temp.size() - 1, temp);

        // Get ending timepoint
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken to sort an array of size " << size_of_vector << " is " << duration.count() << " microseconds" << endl;
    }
}
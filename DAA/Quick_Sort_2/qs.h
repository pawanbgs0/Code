#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition(int startIndex, int endIndex,vector<int> &arr);
void quick_sort(int startIndex, int endIndex, vector<int> &arr);
vector<int> random_vector(int size);
void time_measure_to_sort(int no_iteration, int size_of_vector);
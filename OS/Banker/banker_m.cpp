#include "banker.h"

int main()
{
    Banker b1(5, 3);

    // b1.take_input();
    // b1.display();

    vector<vector<int>> alloc = { 
                                    { 0, 1, 0 }, // P0 // Allocation Matrix
                                    { 2, 0, 0 }, // P1
                                    { 3, 0, 2 }, // P2
                                    { 2, 1, 1 }, // P3
                                    { 0, 0, 2 } // P4
                                }; 

    vector<vector<int>> max = { 
                                { 7, 5, 3 }, // P0 // MAX Matrix
                                { 3, 2, 2 }, // P1
                                { 9, 0, 2 }, // P2
                                { 2, 2, 2 }, // P3
                                { 4, 3, 3 } // P4
                            }; 

    vector<int> max_instance = {10, 5, 7};

    b1.alloc = alloc;
    b1.max = max;
    b1.max_instance = max_instance;

    vector <int> temp = b1.calculate();

    for (int i = 0; i < temp.size(); i++)
    {
        cout << " " << temp[i] << " ";
    }
    return 0;
}
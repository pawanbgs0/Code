#include "c.h"

int main()
{
    vector<string> input = {"2", "*", "3.14", "*", "r"};
    vector<string> input2 = {"2", "+", "3", "+", "a", "+", "b"};
    vector<string> input3;
    vector<string> res;
    int size;

    cout << "Enter the size of Input: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string temp;
        cout << "Enter at index " << i << ": ";
        cin >> temp;
        input3.push_back(temp);
    }
    

    res = constant_folding(input3);

    cout << endl << "The result is: ";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}
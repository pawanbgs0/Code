#include <iostream>
#include <vector>

using namespace std;

// function to generate 2D parity matrix
vector<vector<int>> generateParityMatrix(vector<vector<int>> data) {
    int rows = data.size();
    int cols = data[0].size();
    vector<vector<int>> parityMatrix(rows+1, vector<int>(cols+1, 0));
    
    // calculate row parity bits
    for(int i=0; i<rows; i++) 
    {
        int rowParity = 0;
        for(int j=0; j<cols; j++) 
        {
            rowParity ^= data[i][j];
        }
        parityMatrix[i][cols] = rowParity;
    }
    
    // calculate column parity bits
    for(int j=0; j<cols; j++) 
    {
        int colParity = 0;
        for(int i=0; i<rows; i++) 
        {
            colParity ^= data[i][j];
        }
        parityMatrix[rows][j] = colParity;
    }
    
    // calculate overall parity bit
    int overallParity = 0;
    for(int i=0; i<rows; i++) 
    {
        for(int j=0; j<cols; j++) 
        {
            overallParity ^= data[i][j];
        }
    }
    parityMatrix[rows][cols] = overallParity;
    
    return parityMatrix;
}

// function to check 2D parity matrix
bool checkParityMatrix(vector<vector<int>> data, vector<vector<int>> parityMatrix) {
    int rows = data.size();
    int cols = data[0].size();
    
    // check row parity bits
    for(int i=0; i<rows; i++) 
    {
        int rowParity = 0;
        for(int j=0; j<cols; j++) 
        {
            rowParity ^= data[i][j];
        }
        if(rowParity != parityMatrix[i][cols]) 
        {
            return false; // error detected in row i
        }
    }
    
    // check column parity bits
    for(int j=0; j<cols; j++) 
    {
        int colParity = 0;
        for(int i=0; i<rows; i++) 
        {
            colParity ^= data[i][j];
        }
        if(colParity != parityMatrix[rows][j]) 
        {
            return false; // error detected in column j
        }
    }
    
    // check overall parity bit
    int overallParity = 0;
    for(int i=0; i<rows; i++) 
    {
        for(int j=0; j<cols; j++) 
        {
            overallParity ^= data[i][j];
        }
    }
    if(overallParity != parityMatrix[rows][cols]) 
    {
        return false; // error detected in overall data
    }
    
    return true; // no error detected
}

// example usage
// example usage
int main() {
    vector<vector<int>> data = {{0, 1, 0, 1},
                                 {1, 0, 1, 0},
                                 {0, 1, 0, 1},
                                 {1, 1, 1, 1}};
    
    // generate parity matrix
    vector<vector<int>> parityMatrix = generateParityMatrix(data);
    
    // check parity matrix
    if (checkParityMatrix(data, parityMatrix)) 
    {
        cout << "No error detected" << endl;
    } 
    else 
    {
        cout << "Error detected" << endl;
    }
    
    return 0;
}
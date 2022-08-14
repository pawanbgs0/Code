#include "matrix.h"

using namespace std;

int main()
{
    int m,n;

    cout << "Enter the Row and Column of the Matrix:" << endl;
    cin >> m >> n;

    int m1[m][n];
    int m2[m][n];
    int m3[m][n];
    int m4[m][n];

    cout << "Enter matrix1: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> m1[i][j];
        }
    }

    cout << "Enter matrix2: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>m2[i][j];
        }
    }

    cout << "The matrix formed after addition: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            m3[i][j]=m1[i][j]+m2[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << m3[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"The matrix formed after subtraction is:"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            m4[i][j]=m1[i][j]-m2[i][j];
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m4[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

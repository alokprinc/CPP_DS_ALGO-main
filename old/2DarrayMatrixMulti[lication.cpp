#include <iostream>
using namespace std;

int main()
{

    int n1, n2, n3;

    cin >> n1 >> n2 >> n3;

    int arr1[n1][n2];
    int arr2[n2][n3];
    int solArray[n1][n3];
    //input array 1
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> arr1[i][j];
        }
    }
    // input array 2
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
         solArray[i][j] = 0;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                solArray[i][j] = solArray[i][j] + (arr1[i][k] * arr2[k][j]);
            }
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cout << solArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;


int MINIMUM(int arr[], int i, int n = 5)
{
    int MIN = arr[i], LOC = i;
    for (int j = i + 1; j < 5; j++)
    {
        if (MIN > arr[j])
        {
            MIN = arr[j];
            LOC = j;
        }
    }
    return LOC;
}
int main()
{
    int arr[7] = {3, 2, 6, 1, 5};
    for (int i = 0; i < 5; i++)
    {
        int LOC = MINIMUM(arr, i);
        int temp = arr[i];
        arr[i] = arr[LOC];
        arr[LOC] = temp;
    }
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}
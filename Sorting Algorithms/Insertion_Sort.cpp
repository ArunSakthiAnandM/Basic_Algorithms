#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &vec)
{
    int n = vec.size();
    for(int i=1 ; i<n ; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while(j>=0 && vec[j]>key)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

void printArray(vector<int> &vec)
{
    int n = vec.size();
    for (int i=0; i < n; i++)
        cout << vec[i] << " ";
}

int main()
{
    int arr[] = {9,15,8,13,2,5,10,1,4,14,3,11,7,6,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    insertionSort(vec);
    printArray(vec);
    return 0;
}
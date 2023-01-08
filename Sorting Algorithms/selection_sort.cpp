#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
void selectionSort(vector<int> &vec)
{
    int n = vec.size();

    for(int i = 0; i < n-1; i++)
    {
        int min_index = i;

        for (int j = i+1; j < n; j++)
            if (vec[j] < vec[min_index])
                min_index = j;

        if(min_index != i)
            swap(vec[min_index], vec[i]);
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
    selectionSort(vec);
    printArray(vec);
    return 0;
}
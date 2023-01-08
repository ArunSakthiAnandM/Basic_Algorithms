#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &vec, int left, int mid, int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
    vector<int> leftvec,rightvec;
    for (auto i = 0; i < subArrayOne; i++)
        leftvec.push_back(vec[left+i]);
    for (auto j = 0; j < subArrayTwo; j++)
        rightvec.push_back(vec[mid + 1 + j]);
 
    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
        if (leftvec[indexOfSubArrayOne] <= rightvec[indexOfSubArrayTwo]) 
        {
            vec[indexOfMergedArray] = leftvec[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else 
        {
            vec[indexOfMergedArray] = rightvec[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        vec[indexOfMergedArray] = leftvec[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        vec[indexOfMergedArray] = rightvec[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(vector<int> &vec, int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(vec, begin, mid);
    mergeSort(vec, mid + 1, end);
    merge(vec, begin, mid, end);
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
    mergeSort(vec , 0 , n-1);
    printArray(vec);
    return 0;
}
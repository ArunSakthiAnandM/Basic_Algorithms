#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &vec)
{
    int n = vec.size();
	for (int i=0 ; i<n-1 ; i++)
		for (int j=0 ; j<n-i-1 ; j++)
			if (vec[j] > vec[j+1])
				swap(vec[j], vec[j+1]);
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
    bubbleSort(vec);
    printArray(vec);
    return 0;
}
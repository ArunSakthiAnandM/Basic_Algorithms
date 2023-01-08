#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &vec, int low, int high)
{
	int pivot = vec[high];
	int i = low;

	for (int j=low ; j<=high-1 ; j++)
    {
		if (vec[j] < pivot)
        {
			swap(vec[i], vec[j]);
            i++;
		}
	}
	swap(vec[i], vec[high]);
	return (i);
}

void quickSort(vector<int> &vec, int low, int high)
{
	if (low < high)
    {
		int pi = partition(vec, low, high);
		quickSort(vec, low, pi - 1);
		quickSort(vec, pi + 1, high);
	}
}

void printArray(vector<int> &vec)
{
    int n = vec.size();
    for (int i=0 ; i<n ; i++)
        cout << vec[i] << " ";
}

int main()
{
    int arr[] = {9,15,8,13,2,5,10,1,4,14,3,11,7,6,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    quickSort(vec , 0 , n-1);
    printArray(vec);
    return 0;
}
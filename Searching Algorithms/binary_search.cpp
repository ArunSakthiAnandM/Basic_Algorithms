#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) return mid;

        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(void)
{
    vector<int> arr = { 2, 3, 4, 10, 40 };
    int element = 10;
    int n = arr.size();
    int result = binarySearch(arr, 0, n - 1, element);
    if(result == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << result;
    return 0;
}
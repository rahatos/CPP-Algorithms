#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            binarySearch(arr, l, mid-1, x);
        else
            binarySearch(arr, mid+1, r, x);
    }
    else
        return -1;
}

int main(void)
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i <n ; i++)
        cin >> arr[i];

    int x;
    cin >> x;
    sort(arr, arr+n);

    for(int i = 0; i <n ; i++)
        cout << arr[i] << " ";

    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)? printf("\nElement is not present in array") : printf("\nElement is present at index %d",result);
    return 0;
}

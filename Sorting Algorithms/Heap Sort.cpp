#include <bits/stdc++.h>

using namespace std;

int heapsize;

int l(int root)
{
    return 2*root+1;
}

int r(int root)
{
    return 2*root+2;
}

void heapify(int arr[], int i)
{
    int largest = i;

    int left = l(i);
    int right = r(i);

    if(arr[left] > arr[largest] && left <= heapsize)
        largest = left;
    if(arr[right] > arr[largest] && right <= heapsize)
        largest = right;

    if(largest != i)
    {
        swap (arr[i], arr[largest]);
        //confirming that the tree is on maxheap even after swapping
        heapify(arr, largest);
    }
}

void build_max_heap(int arr[])
{
    for (int i = heapsize/2; i >= 0; i--)
    {
        heapify(arr, i);
    }
}

void heapsort(int arr[])
{
    build_max_heap(arr);
    int _size = heapsize;
    for(int i = 0; i < _size; i++)
    {
        swap(arr[0], arr[heapsize]);
        heapsize--;
        heapify(arr, 0);
    }
}

int main()
{
    int n;
    cout << "size of array? = ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapsize = n-1;
    heapsort(arr);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int Partition(int Array[],int Start, int End)
{
    int pivot, pIndex;
    pivot = Array[End];
    pIndex = Start;

    for ( int i = Start; i < End; i++ )
    {
        if (Array[i] <= pivot)
        {
            swap(Array[i], Array[pIndex]);
            pIndex++;
        }
    }
    swap (Array[pIndex], Array[End]);
    return pIndex;
}

Quicksort(int Array[], int Start, int End)
{
    int pIndex;
    if(Start < End)
    {
        pIndex = Partition(Array,Start,End);
        Quicksort (Array, Start, pIndex-1);
        Quicksort (Array, pIndex+1, End);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for(int i=0 ; i<n; i++)
        cin >> arr[i];

    Quicksort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
void Merge(int Array[], int Start, int mid, int End);

void MergeSort(int Array[], int Start, int End)
{
    int mid;

    if(Start < End)
    {
        mid = (Start + (End))/2;
        MergeSort(Array, Start, mid);
        MergeSort(Array, mid+1, End);
        Merge(Array, Start, mid, End);
    }
}

void Merge(int Array[], int Start, int mid, int End)
{
    int n1 = mid - Start + 1;
    int n2 = End - mid;
    int Left[n1 +1], Right[n2+1];
    for(int i = 0; i < n1; i++)
    {
        Left[i] = Array[Start + i];
    }

    Left[n1] = INT_MAX;

    for(int i = 0; i < n2; i++)
    {
        Right[i] = Array[mid + 1 + i];
    }

    Right[n2] = INT_MAX;

    int i = 0, j = 0;

    for(int k = Start; k <= End; k++)
    {
        if(Left[i] <= Right[j])
        {
            Array[k] = Left[i];
            i++;
        }
        else
        {
            Array[k] = Right[j];
            j++;
        }
    }


}

int main()
{
    int n;
    cout << "size : ";
    cin >> n;
    int test[n];
    for( int i = 0; i < n; i++)
    {
        cin >> test[i];
    }

    MergeSort(test, 0, n-1);

    for(int i=0; i<n; i++)
        cout << test[i] << " ";

    return 0;
}

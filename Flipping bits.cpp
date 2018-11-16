#include<iostream>
#include<vector>
using namespace std;

int GetCeilIndex(int arr[], vector<int> &T, int l, int r,int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LongestIncreasingSubsequence(int arr[], int n)
{
    vector<int> tailIndices(n, 0);
    vector<int> prevIndices(n, -1);

    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[tailIndices[0]])
        {
            tailIndices[0] = i;
        }
        else if (arr[i] > arr[tailIndices[len-1]])
        {
            prevIndices[i] = tailIndices[len-1];
            tailIndices[len++] = i;
        }
        else
        {
            int pos = GetCeilIndex(arr, tailIndices, -1,
                                   len-1, arr[i]);

            prevIndices[i] = tailIndices[pos-1];
            tailIndices[pos] = i;
        }
    }

    return len;
}

int main()
{
    int n;
    cin>>n;
    int tab[n];

    for(int i=0;i<n;i++)
        cin>>tab[i];

    cout<< LongestIncreasingSubsequence(tab, n);

    return 0;
}

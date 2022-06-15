
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> left, vector<int> right, vector<int> &arr)
{
    cout << "---enter merging \n";
    int i = 0, j = 0, k = 0;
    while (k < arr.size())
    {
        cout << "  # " << k << "\n";
        cout << "   arr: ";
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << "\n";
        cout << "   left: ";
        for (auto x : left)
        {
            cout << x << " ";
        }
        cout << "\n";
        cout << "   right: ";
        for (auto x : right)
        {
            cout << x << " ";
        }
        cout << "\n";
        {
            if (i < left.size() && j < right.size())
            {
                if (left[i] <= right[j])
                {
                    arr[k] = left[i];
                    i++;
                }
                else
                {
                    arr[k] = right[j];
                    j++;
                }
            }
            else if (i < left.size())
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
        }
        k++;
    }
    cout << "---exit merging \n\n";
}

void mergesort(vector<int> &arr, int length)
{
    cout << "----enter mergesort \n";
    if (length < 2)
        return;

    int mid = length / 2;
    vector<int> left(mid, 0);
    vector<int> right(length - mid, 0);

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < length; i++)
        right[i - mid] = arr[i];

    cout << "left ";
    for (auto i : left)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "right ";
    for (auto i : right)
    {
        cout << i << " ";
    }
    cout << "\n";

    mergesort(left, mid);
    mergesort(right, length - mid);

    merge(left, right, arr);
    cout << "after merging ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "----exit mergesort \n\n\n";
};

int main()
{

    vector<int> myarr{3, 11, 2};

    mergesort(myarr, myarr.size());

    for (auto i : myarr)
    {
        cout << i << " ";
    }
    return 0;
}


#include <vector>
#include <iostream>

using namespace std;

void quickSort(vector<int> a, int low, int high)
{
    if(low >= high)
    {
        return;
    }

    int pivot = a[low];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(a[j] > pivot && i < j)
        {
            j--;
        }

        if(i<j)
        {
            a[i++]=a[j];
        }

        while(a[i] < pivot && i< j)
        {
            i++;
        }

        if(i<j)
        {
            a[j] = a[i];
        }
    }

    a[i]=pivot;

    quickSort(a, low-1 ,i);
    quickSort(a,i+1,high);
}
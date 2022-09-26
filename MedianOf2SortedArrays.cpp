

#include <vector>
#include <iostream>

using namespace std;

vector<int> mergeArray(vector<int> &nums1, vector <int> &nums2)
{
    vector<int> all;
    int i=0;
    int j=0;

    while(i<nums1.size() &&  j<nums2.size())
    {
        if(nums1[i] < nums2[j])
        {
            all.push_back(nums1[i++]);
        }
        else
        {
            all.push_back(nums2[j++]);
        }
    }

    while(i<nums1.size())
    {
        all.push_back(nums1[i++]);
    }

    while(j<nums2.size())
    {
        all.push_back(nums2[j++]);
    }

    return all;
}

double findMedianSortedArray(vector<int> &nums1, vector<int>& nums2)
{
    vector<int> all = mergeArray(nums1,nums2);
    if(all.size()%2==0)
    {
        return (all[all.size()/2] + all[all.size()/2-1])/2.0;
    }
    else
    {
        return all[all.size()/2];
    }
}

void findMedianMain()
{
    vector<int> a={1};
    vector<int> b = { 2,3 };

    double d = findMedianSortedArray(a,b);

    vector<int> a1 = { 1,2 };
    vector<int> b1 = { 3,4 };

    double d2 = findMedianSortedArray(a1, b1);

    cout << d << endl;
    cout << d2 << endl;


}
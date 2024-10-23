#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Question 01 : Merge two sorted array
// vector<int>nums1 = { -1,0,0,3,3,3,0,0,0 }; m =6
// vector<int>nums2 = { 1,2,2 }; n = 3

void mergeArrayTLE(vector<int> nums1, int m, vector<int> nums2, int n) {

    int t = m + n;
    int i = 0, j = 0;
    bool flag = false;
    int count = 1;

    while(j != n)
    {
        

        if (nums1[i] == 0 && i > m)
        {
            nums1[i] = nums2[j];
            i++;
            j++;
            continue;
        }

        if (nums1[i] < nums2[j])
        {
            i++;
            continue;
        }
        else
        {
            nums1.insert(nums1.begin() + i, nums2[j]);
            nums1.pop_back();
            j++;
            continue;
        }



    }

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

}


void mergeArray(vector<int> nums1, int m, vector<int> nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = n + m - 1;

    while (j >= 0)
    {

        if (nums2[j] >= nums1[i])
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        else
        {
            nums1[k] = nums1[i];
            k--;
            i--;
        }


    }

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
}

// Question 02 : Plus One
// [1,2,3] => [1,2,4]
// [9] => [1,0]

void plusOne(vector<int> digits) {

    int n = digits.size();
    int last = n - 1;


    if (digits[last] != 9)
    {
        digits[last] += 1;
    }
    else
    {

        while (last != -1)
        {
            if (digits[last] == 9)
            {
                digits[last] = 0;
                last--;
            }
            else
            {
                break;
            }
        }

        if (last != -1 && digits[last] != 0)
        {
            digits[last] += 1;
        }
        else
        {
            digits.insert(digits.begin(), 1);
        }

    }



    for (int j = 0; j < digits.size(); j++)
    {
        cout << digits[j] << " ";
    }
}


// Question 03 : Find Duplicate in a array 
// vector<int> arr = { 1,2,3,4,5,3 };
// duplicate(arr);
void duplicate(vector<int>arr)
{

    int n = arr.size();
    map<int, int>count;

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }


    for (auto temp : count)
    {
        if (temp.second > 1)
        {
            cout << "Duplicate " << temp.first << endl;
        }
    }

}


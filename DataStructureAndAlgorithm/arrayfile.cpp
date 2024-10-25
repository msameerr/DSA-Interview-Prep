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


// Question 04 : Swap two numbers without the third variable
void two_swap()
{

    int a = 5, b = 10;

    cout << "Before : " << a << " " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After : " << a << " " << b << endl;

}

// Question 05 : Print Pattren
// 4 3 2 1
// 4 3 2 1
// 4 3 2 1
// 4 3 2 1

void pattern1()
{

    int i = 0;
    int n = 4;

    while (i < n)
    {
        int j = n;

        while (j >= 1)
        {
            cout << j << " ";
            j--;
        }
        cout << endl;
        i++;
    }

}

// Question 06 : Print Pattren
// 1 2 3
// 4 5 6
// 7 8 9

void pattern2()
{
    int i = 0, j = 1;

    int n = 3;


    while (i < n)
    {
        int k = 0;
        while (k < n)
        {
            cout << j << " ";
            k++;
            j++;
        }
        cout << endl;
        i++;
    }

}

// Question 07 : Print Pattren
// *
// * *
// * * *
// * * * *

void pattern3()
{

    int i = 1;
    int n = 4;

    while (i <= n)
    {
        int k = 0;
        while (k < i)
        {
            cout << "*" << " ";
            k++;
        }
        cout << endl;

        i++;
    }

}

// Question 08 : Print Pattren
// 1
// 2 3 
// 4 5 6 
// 7 8 9 10

void pattern4()
{

    int i = 1, count = 1;
    int n = 4;

    while (i <= n)
    {
        int k = 0;
        while (k < i)
        {
            cout << count << " ";
            k++; count++;
        }
        cout << endl;

        i++;
    }

}

// Question 09 : Print Pattren
// 1
// 2 1
// 3 2 1
// 4 3 2 1

void pattern5()
{

    int i = 1;
    int n = 4;

    while (i <= n)
    {

        int j = i;
        while (j >= 1)
        {
            cout << j << " ";
            j--;
        }
        cout << endl;
        i++;

    }


}

// Question 10 : Print Pattren
// * * * *
// * * *
// * *
// * 

void pattern6()
{

    int i = 1; 
    int n = 4;
    int count = 4;

    while (i <= n)
    {
        int j = count;

        while (j >= 1)
        {
            cout << "*" << " ";
            j--;
        }

        cout << endl;
        count--; i++;
    }

}

// Question 11 : Print Pattern
//       *
//     * *
//   * * *
// * * * *

void pattern7()
{
    int i = 1;
    int n = 4;
    int count = 3;

    while (i <= n)
    {
        int j = 1;
        while (j <= count)
        {
            cout << " ";
            j++;
        }

        int k = i;
        while (k >= 1)
        {
            cout << "*";
            k--;
        }
        
        cout << endl;

        i++; count--;
    }
}

// Question 12 : Print Pattern
//       *
//     * * *
//   * * * * *
// * * * * * * *

void pattern8()
{

    int i = 1;
    int n = 4;
    int count = 3;

    while (i <= n)
    {
        int j = count;
        while (j >= 1)
        {
            cout << " "; 
            j--;
        }

        int k = i;
        while (k >= 1)
        {
            cout << "*";
            k--;
        }

        int l = i - 1;
        while (l >= 1)
        {
            cout << "*";
            l--;
        }
        cout << endl;

        i++; count--;
    }

}

// Question 13 : Product and sum of int
// input -> 1232
// prod -> 12, Sum -> 8

void prod_sum()
{

    int num = 1232;
    int prod = 1, sum = 0;

    while (num != 0)
    {

        int n = num % 10;

        prod *= n;
        sum += n;

        num = num / 10;

    }
    cout << "Product " << prod << endl;
    cout << "sum : " << sum << endl;
}


// Question 14 : Reverse int
// 123 -> 321
void reverse_int()
{

    int num = 123;
    int ans = 0;
    while (num != 0)
    {

        int n = num % 10;

        ans = (ans * 10) + n;

        num = num / 10;

    }
    cout << "Reverse : " << ans;
}


// Question 15 : swap alternative
// 1 2 3 4 5 -> 2 1 4 3 5

void Swap_alternative()
{

    int arr[6] = { 1,2,3,4,5,6 };
    int n = 6;

    int i = 0;
    while (i < n)
    {
        if (i + 1 < n)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
      
        i += 2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


// Question 16 : Find Unique in array of Duplicate
void Find_unique()
{
    int arr[7] = { 1,2,3,1,3,4,2 };
    int n = 7;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << "Unique : " << ans;
}

// Question 17 : Find Unique Occurence in an array
void unique_occurence()
{
    int arr[8] = { 1,2,2,2,1,1,3 };
    int n = 7;

    map<int, int> count;

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int check[10];
    int j = 0;
    for (auto num : count)
    {
        check[j] = num.second;
        j++;
    }

    int m = count.size();
    for (int i = 0; i < m; i++)
    {
        if (check[i] != check[i + 1])
        {
            cout << "unique Occurence";
            break;
        }
    }

}


// Question 18 : Sort zeros ans ones
void zeros_ones()
{

    int arr[8] = { 1,1,0,0,0,0,1,0 };
    int n = 8;

    int start = 0;
    int end = n - 1;

    while (start < end)
    {

        if (arr[start] == 1 && arr[end] == 0)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

        if (arr[start] == 0 && arr[end] == 0)
        {
            start++;
        }

        if (arr[start] == 1 && arr[end] == 1)
        {
            end--;
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}

// Question 19 : Implement binary search
void BinarySearch()
{

    int arr[5] = { 1,2,3,4,5 };
    int n = 5, key = 5;

    int start = 0;
    int end = n - 1;

    int mid = (start + end) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            cout << "key is present : " << arr[mid] << endl;
            break;
        }

        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        
        if (arr[mid] < key)
        {
            start = mid + 1;
        }

        mid = (start + end) / 2;


    }

}
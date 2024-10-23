#include<iostream>
#include<string>
#include <algorithm>
#include<map>
#include<vector>
#include<queue>

using namespace std;

// Question 01 : Valid palindrome
// "A man, a plan, a canal: Panama" => True

bool isPalindrome(string s) {

    int n = s.length();
    if (n < 1)
    {
        return true;
    }

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int i = 0;
    int j = n - 1;
    bool flag = true;
    while (i < j)
    {
        if (!isdigit(s[i]))
        {
            if (!isalpha(s[i]))
            {
                i++;
                continue;
            }
        }

        if (!isdigit(s[j]))
        {
            if (!isalpha(s[j]))
            {
                j--;
                continue;
            }
        }

        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Question 02 : first unique character
// 	cout << firstUniqChar("loveleetcode"); => 2

int firstUniqChar(string s) {

    map<char, int>count;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        count[s[i]]++;
    }

    char arr[100];
    int k = 0;
    for (auto temp : count)
    {
        if (temp.second == 1)
        {
            arr[k] = temp.first;
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (s[i] == arr[j])
            {
                return i;
                
            }
        }
    }
    return -1;
}


// Question 03 : Reverse the String
void reverse(string str)
{

    int n = str.length();
    int start = 0; 
    int end = n - 1;

    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }

    cout << str;
}
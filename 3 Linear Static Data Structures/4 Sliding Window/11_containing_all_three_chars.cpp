// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>
using namespace std;

// brute force
int numberOfSubstrings(string str)
{
    int n = str.size();
    int ctr = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        unordered_set<char> hash;
        for (int j = i; j <= n - 1; j++)
        {
            hash.insert(str[j]);
            if (hash.size() == 3)
            {
                // ctr++;
                // little bit more optimization to brute force
                ctr += n - j;
                break;
            }
        }
    }
    return ctr;
}

// optimal

int numberOfSubstrings(string str)
{
     int n = str.size();
    int ctr = 0;
    unordered_map<char, int> hash;
    for (int i = 0, j = 0; j <= n - 1; j++)
    {
        hash[str[j]]++;
        while (hash.size() == 3)   // we're counting number of substrings and not finding the longest substring hence we must use while loop
        {
            hash[str[i]]--;
            if (hash[str[i]] == 0)
            {
                hash.erase(str[i]);
            }
            i++;
        }
        ctr += i;
    }
    return ctr;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
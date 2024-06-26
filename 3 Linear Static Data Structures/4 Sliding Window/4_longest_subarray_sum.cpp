// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// For arrays with both positive and negative elements
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int max_len = 0, n = a.size();
    for (int i = 0; i <= n - 1; i++)
    {
        long long sum = 0;
        for (int j = i; j <= n - 1; j++)
        {
            sum += a[j];
            if (sum == k)
                max_len = max(j - i + 1, max_len);
            // else if (sum > k) break; // this should done if array doesn't contain negative numbers
        }
    }
    return max_len;
}
// TC: O(n^2)
// SC: O(n1)

// Hashing
// Prefix Sum Algorithm
// Optimal (For arrays with both positive and negative elements)
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    unordered_map<long long, int> preSum;
    int max_len = 0, n = a.size();
    ;
    long long sum = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            max_len = max(max_len, i + 1);
        }
        else if (preSum.find(sum - k) != preSum.end())
        {
            max_len = max(max_len, i - preSum[sum - k]);
        }
        if (preSum.find(sum) == preSum.end())
            preSum[sum] = i; // stores only if the sum is already not there or else subarray won't be the longest ie due to zeroes
    }
    return max_len;
}
// TC: O(n)/ O(n^2) (if collision happens since we're using unordered map)
// SC: O(n)

// Sliding Window
// For arrays with positive elements only including zeroes (optimal)
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int max_len = 0, n = a.size();
    long long sum = 0;
    for (int i=0, j = 0; j <= n - 1; j++)
    {
        sum += a[j];
        if (sum > k) // while is replaced by if as we're only looking for the longest
        {
            sum -= a[i];
            i++;
        }
        if (sum == k)
            if(max_len<j-i+1) max_len = j-i+1;
    }
    return max_len;
}
// TC: O(n) (Using while loop is O(2n))
// SC: O(1)

int main()
{
    vector<int> arr = {1, 2, 1, 3};
    long long k = 2;

    int maxLength = longestSubarrayWithSumK(arr, k);

    cout << maxLength << endl;

    return 0;
}
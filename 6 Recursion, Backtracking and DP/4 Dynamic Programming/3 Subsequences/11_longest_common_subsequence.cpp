// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

int fn(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // equal
    if (str1[i] == str2[j])
        return 1 + fn(i - 1, j - 1, str1, str2, dp);
    // not equal
    return dp[i][j] = max(fn(i - 1, j, str1, str2, dp), fn(i, j - 1, str1, str2, dp));
}

int longestCommonSubsequence(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fn(n - 1, m - 1, str1, str2, dp);
}

int longestCommonSubsequence(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1)); // in case of problems where its invalid going to negative, normalize
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1]) // denormalize
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[n][m];
    int i = n;
    int j = m;

    int index = len - 1;
    string str = "";
    for (int k = 1; k <= len; k++)
    {
        str += "$"; // dummy string
    }

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            str[index] = str1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (str1[i - 1] > str2[j - 1])
        {
            i--;
        }
        else
            j--;
    }
    cout << str;
    return dp[n][m];
}

int longestCommonSubsequence(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(2, vector<int>(m + 1)); // in case of problems where its invalid going to negative, normalize
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1]) // denormalize
            {
                dp[1][j] = 1 + dp[0][j - 1];
                continue;
            }
            dp[1][j] = max(dp[0][j], dp[1][j - 1]);
        }
        dp[0] = dp[1];
    }
    return dp[0][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
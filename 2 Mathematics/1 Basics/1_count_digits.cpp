// https://www.geeksforgeeks.org/problems/count-digits5716/1

#include <bits/stdc++.h>
using namespace std;

// Brute Force
int countDigits(int n)
{
    int count = 0, digit;
    while (n != 0)
    {
        digit = n % 10;
        count++;
        n /= 10;
    }
    return count;
}
// TC: O(log10(n))
// SC: O(1)

// Optimal assuming n is natural number
int countDigits(int n)
{
    return floor(log10(n)) + 1;
}

// TC: O(1)
// SC: O(1)

int main()
{

    return 0;
}

// floor(log10(x)) + 1  for best time and space complexity
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    { // for arrays size(arr) using stl or simply sizeof(arr)/sizeof(arr[0])
        cout << v[i] << " ";
    }
    cout << endl;
}

void pass_by_value(vector<int> v)
{ // don't do this. its deep copy so O(n) complexity
    v.push_back(47);
}

void pass_by_reference(vector<int> &v)
{ // do this. its shallow copy so O(1) complexit
    v.push_back(47);
}

int fun(int x)
{
    return x > 5;
}

int main()
{

    // input and printing
    vector<int> v;
    // v = {1, 2, 3, 4, 5};
    //  vector<int> v(begin(arr), end(arr)) // creating through array
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x); // O(1)
    }
    printVec(v);

    reverse(v.begin(), v.end()); // For arrays, reverse(arr, arr+n); or rev(begin(arr), end(arr))
    printVec(v);

    next_permutation(v.begin(), v.end());
    printVec(v);

    v.pop_back(); // O(1)
    printVec(v);

    v.erase(v.begin() + 2); // O(n)
    printVec(v);

    vector<int> v_zeroes(10);
    printVec(v_zeroes);
    vector<int> v_ones(10, 1);
    printVec(v_ones);

    // or use fill
    fill(v_zeroes.begin(), v_zeroes.end(), 0); // int arr[n]; fill(arr, n, 0);

    // Copying of vectors are shallow copy by default
    vector<int> v_copy = v;
    v.push_back(7);
    printVec(v_copy);

    // Pass by value
    pass_by_value(v);
    printVec(v);

    // Pass by reference
    pass_by_reference(v);
    printVec(v);

    vector<int> v2 = {4, 6, 8, 25, 7, 4};
    int min = *min_element(v2.begin(), v2.end());  // it returns reference to the min element
    int max = *max_element(v2.begin(), v2.end());  // ie for an array reference, for a vector iterator but both can be dereferenced with *
    int sum = accumulate(v2.begin(), v2.end(), 0); // 0 is initial sum doesn't return pointer
    int ct = count(v2.begin(), v2.end(), 4);
    cout << min << " " << max << " " << sum << " " << ct << endl;

    reverse(v2.begin(), v2.end());
    printVec(v2);
    cout << all_of(v2.begin(), v2.end(), fun) << " ";   // returns 0(false)
    cout << any_of(v2.begin(), v2.end(), fun) << " ";   // returns 1(true)
    cout << none_of(v2.begin(), v2.end(), fun) << endl; // returns 0(false)
}
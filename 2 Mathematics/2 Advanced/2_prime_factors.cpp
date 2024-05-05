#include<bits/stdc++.h>
using namespace std;

// Brute
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

vector<int> primeFactors(int n)
{
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(isPrime(i)&&n%i==0){
            ans.push_back(i);
        }
    }
    return ans;
}

// Better
vector<int> primeFactors(int n)
{
    vector<int> output;
    int i = 2;
    for(int i=2; i*i<=n;i++)
    {
        if (n % i == 0)
        {
            output.push_back(i);
            while(n%i==0)
                n /= i;
        }
    }
    if(n!=1) output.push_back(n); // to insert factor that comes after i*i<=n
    return output;
}

// TC: O(sqrtn*logn)
// SC: O(x)

// Optimized version in sieve folder


void printVector(vector<int>& vec) {
    for(const auto& val : vec) {
        cout << val << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>  output =primeFactors(n) ;
    printVector(output);
    
    return 0;
}
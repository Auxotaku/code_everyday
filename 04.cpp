#include <iostream>
#include <vector>
using namespace std;
//埃筛
void getPrime(vector<int>& prime, int n)
{
    vector<bool> isPrime(n+1,true);
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++)
        {
            isPrime[i*prime[j]]=false;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}

vector<int> findPalindromePrimes(int a, int b)
{
    vector<int> prime;
    getPrime(prime,b);
    vector<int> result;
    for(int i=0;i<prime.size();i++)
    {
        int num=prime[i];
        int temp=0;
        while(num)
        {
            temp=temp*10+num%10;
            num/=10;
        }
        if(temp==prime[i]&&prime[i]>=a)
        {
            result.push_back(prime[i]);
        }
    }
    return result;
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> result = findPalindromePrimes(a, b);
    if(result.empty()){
        cout<<-1;
        return 0;
    }
    for (int num : result) {
        cout << num << endl;
    }
    return 0;
}
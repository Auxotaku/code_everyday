#include<bits/stdc++.h>
using namespace std;
long long n,k;
int q;
// //埃筛
vector<long long> prime;
// vector<bool> is_prime;
vector<long long> ans;
// void init(unsigned long long n){
//     is_prime.resize(n+1,true);
//     is_prime[0]=is_prime[1]=false;
//     for(int i=2;i<=n;i++){
//         if(is_prime[i]) prime.push_back(i);
//         for(int j=0;j<prime.size()&&i*prime[j]<=n;j++){
//             is_prime[i*prime[j]]=false;
//             if(i%prime[j]==0) break;
//         }
//     }
// }
bool isprime(long long x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    cin>>q;
    while(q--){
        //is_prime.clear();
        prime.clear();
        ans.clear();
        cin>>n>>k;
        //init(n);
        int cnt=0;
        long long tempn;
        long long mul=1;
        for(long long i=2;i<=sqrt(n);i++){
            cnt=0;
            tempn=n;
            if(n%i==0){
                if(isprime(i)){
                    while(tempn%i==0){
                        tempn/=i;
                        cnt++;
                    }
                    if(cnt>=k){
                        mul*=pow(i,cnt);
                    }
                }
            }
        }
        cout<<mul<<endl;
    }
    return 0;
}
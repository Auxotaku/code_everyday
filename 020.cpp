#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    string s;
    cin>>s;
    long long sum=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '1'){
            sum += pow(2,i);
        }
    }
    cout<<sum;
    return 0;
}
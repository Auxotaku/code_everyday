#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    string c;
    for(int i=0;i<n;i++){
        cin>>c;
        s.append(c);
    }
    string ss = s;
    reverse(s.begin(),s.end());
    if(ss == s) cout<<"true";
    else cout<<"false";
}
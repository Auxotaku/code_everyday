#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int a[10010],t,cnt=0;
    while (cin>>t)
    {
        a[cnt++]=t;
        sort(a,a+cnt);
    }
    for (int i = 0; i < cnt; i++)
    {
        cout<<a[i]<<' ';
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx,dy;
int x,y;
int main(){
    cin>>n>>m;
    while(n--){
        cin>>x>>y;
        dx+=x;
        dy+=y;
    }
    while(m--){
        cin>>x>>y;
        x+=dx;
        y+=dy;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
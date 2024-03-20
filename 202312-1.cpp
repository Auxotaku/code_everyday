// 仓库规划
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> repos[1001];
// bool compare(const vector<int>& a,const vector<int> &b){
//     for(int i=0 ;i<a.size();i++){
//         if(a[i]!=b[i]){
//             return a[i]<b[i];
//         }
//     }
// }
bool solve(vector<int>& repoa,vector<int>& repob){
    for(int i=0;i<m;i++){
        if(repoa[i]>=repob[i]){
            return false;
        }
    }
    return true;
}
int ans[1001];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ans[i]=1002;
    }
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            repos[i].push_back(x);
        }
    }
    // sort(repos+1,repos+n,compare);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(solve(repos[i],repos[j])){
                ans[i]=min(ans[i],j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==1002) printf("0\n");
        else printf("%d\n", ans[i]);
    }
    return 0;
    
}

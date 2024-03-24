#include<bits/stdc++.h>
using namespace std;
struct T{
    int type;
    double value;
    double partialsum;
};
T t1[100001];
T t2[100001];
int n,m;
int main(){
    cin>>n>>m;
    double sumk=1;
    double sumtheta=0;
    for(int i=1;i<=n;i++){
        int type;
        cin>>type;
        if(type == 1){
            cin>>t1[i].value;
            t1[i].type=1;
            sumk*=t1[i].value;
            t1[i].partialsum=sumk;

            t2[i].type=2;
            t2[i].value=0;
            t2[i].partialsum=sumtheta;
        }
        else{
            cin>>t2[i].value;
            t2[i].type=2;
            sumtheta+=t2[i].value;
            t2[i].partialsum=sumtheta;

            t1[i].type=1;
            t1[i].value=1;
            t1[i].partialsum=sumk;
        }
    }
    while(m--){
        int ti,tj;
        double tx,ty;
        cin>>ti>>tj>>tx>>ty;
        t1[0].partialsum=1;
        double ans_k=t1[tj].partialsum/t1[ti-1].partialsum;
        t2[0].partialsum=0;
        double ans_theta=t2[tj].partialsum-t2[ti-1].partialsum;
        double ansx=tx*cos(ans_theta)-ty*sin(ans_theta);
        double ansy=tx*sin(ans_theta)+ty*cos(ans_theta);
        ansx*=ans_k;
        ansy*=ans_k;
        printf("%.3f %.3f\n",ansx,ansy);
    }
    return 0;
}
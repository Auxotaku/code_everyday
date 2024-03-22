#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long omega[2001];
long long tree_root;
struct node{
    long long no;
    long long father;
    vector<long long> son;
    long long omega;
    long long omega_delta;
    long long omega_sum;
    bool alive;
};
node tree[2001];
long long omega_solve(node &root ){
    if(root.alive){
        long long sum=0;
        for(long long i=0;i<root.son.size();i++){
            sum+=omega_solve(tree[root.son[i]]);
        }
        root.omega_sum=sum+root.omega;
        return root.omega_sum;
    }
    else{
        for(long long i=0;i<root.son.size();i++){
            omega_solve(tree[root.son[i]]);
        }
        return 0;
    }
}
void activate(node &root){
    for(long long i=0;i<root.son.size();i++){
        activate(tree[root.son[i]]);
    }
    root.alive=true;
}
void deactivate(node &root){
    for(long long i=0;i<root.son.size();i++){
        deactivate(tree[root.son[i]]);
    }
    root.alive=false;
}
void survive(vector<long long> &survivors,node &root){
    if(root.alive){
        survivors.push_back(root.no);
    }
    for(long long i=0;i<root.son.size();i++){
        survive(survivors,tree[root.son[i]]);
    }
}
int main(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>omega[i];
        tree[i].no=i;
        tree[i].omega=omega[i];
        tree[i].alive=true;
        tree[i].omega_sum=0;
    }
    for(long long i=2;i<=n;i++){
        long long temp;
        cin>>temp;
        tree[i].father=temp;
        tree[temp].son.push_back(i);
    }
    while(m--){
        long long q;
        cin>>q;
        for(long long i=1;i<=n;i++){
            tree[i].alive=true;
        }
        vector<long long> category;
        long long temp=q;
        category.push_back(temp);
        while(temp!=1&&tree[temp].alive){
                temp=tree[temp].father;
                category.push_back(temp);
        }
        for(long long i=1;i<=n;i++){
            tree[i].alive=true;
        }
        while(1){
            long long minnode=0; 
            long long mindiff=0x7fffffffffffffff;
            long long sum=0;
            long long diff=0;
            omega_solve(tree[1]);
            for(long long i=1;i<=n;i++){
                if(tree[i].alive){
                    sum+=tree[i].omega;
                }
            }
            for(long long i=1;i<=n;i++){
                if(tree[i].alive){
                    diff=abs(sum-2*tree[i].omega_sum);
                    if(mindiff>diff){
                        mindiff=diff;
                        minnode=i;
                    }
                }
            }
            cout<<minnode<<' ';
            bool flag=false;
            for(long long i=0;i<category.size();i++){
                if(tree[category[i]].no==minnode){
                    flag=true;
                    vector<long long> survivors;
                    survive(survivors,tree[category[i]]);
                    for(long long j=1;j<=n;j++){
                        tree[j].alive=false;
                    }
                    for(long long j=0;j<survivors.size();j++){
                        tree[survivors[j]].alive=true;
                    }
                    break;
                }
            }
            if(!flag){
                deactivate(tree[minnode]);
            }
            long long alivecnt=0;
            for(long long i=1;i<=n;i++){
                if(tree[i].alive) alivecnt++;
            }
            if(alivecnt==1) break;
        }
        cout<<endl;
    }
    return 0;
}
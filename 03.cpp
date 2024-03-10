#include <iostream>
using namespace std;

void calculateRectangle(int n, int m)
{
    long long square=0;
    long long rectangle=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i!=j){
                rectangle+=(n-i+1)*(m-j+1);
            }
            else{
                square+=(n-i+1)*(m-j+1);
            }
        }
    }
    cout<<square<<" "<<rectangle;
}

int main()
{
    int n, m;
    cin >> n >> m;
    calculateRectangle(n, m);
    return 0;
}
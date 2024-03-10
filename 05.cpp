#include <iostream>
#include <map>
using namespace std;
map<int,int> number_stuck;
int stuck[10]={6,2,5,5,4,5,6,3,7,6};
bool flag[121];
int splicedWoodenSticks(int n)
{
    for(int i=0;i<10;i++){
        number_stuck[i]=stuck[i];
    }
    int count=0;
    //枚举所有的可能，每个数字可能不止一位
    for(int i=0;i<2400;i++){
        int tempi=i;
        int costi = 0;
        while(tempi/10){
            costi+=number_stuck[tempi%10];
            tempi/=10;
        }
        costi+=number_stuck[tempi];
        number_stuck[i]=costi;
    }
    for(int i=0;i<1200;i++){ 
        for(int j=0;j<1200;j++){
            if(number_stuck[i]+number_stuck[j]+number_stuck[i+j]+4==n){
                if(i==j&&flag[i]==0){
                    count++;
                    flag[i]=1;
                    //cout<<i<<" "<<j<<endl;
                }
                else if(i!=j){
                    count++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << splicedWoodenSticks(n) << endl;
    return 0;
}
int howManyBits(int x){
    int sum;
    int isZero  =  !x;
    int flag = x>>31;
    int bit_16,bit_8,bit_4,bit_2,bit_1,bit_0;
    int mask = ((!!x)<<31)>>31;
    x = (flag & (~x)) | (~flag & x);
    bit_16 = (!((!!(x>>16)) ^ (0x1))) << 4;
    x = x >> bit_16;
    bit_8 = (!((!!(x>>8)) ^ (0x1))) << 3;
    x = x >> bit_8;
    bit_4 = (!((!!(x>>4)) ^ (0x1))) << 2;
    x = x >> bit_4;
    bit_2 = (!((!!(x>>2)) ^ (0x1))) << 1;
    x = x >> bit_2;
    bit_1 = (!((!!(x>>1)) ^ (0x1)));
    x = x >> bit_1;
    bit_0 = x;
    sum = bit_16 + bit_8 + bit_4 + bit_2 + bit_1 + bit_0 +1;
    return isZero | (sum & mask);
}
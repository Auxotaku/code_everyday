#include<bits/stdc++.h>

using namespace std;
#define L 100100
int n, m, l, r, k, cnt, temp, ans;
int a[L], b[L];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    temp = a[0];
    for (int i = 1; i < n; i++) {
        temp = __gcd(temp, a[i]);
    }
    cout << (temp == 1 ? "true" : "false");
    return 0;
}
// 用gcd 来判断真的好难想
// 主要还是题意 和任何一个数相乘
// 最后形式变成 n*k+m*q.... 此时 k q 还得是互质的 那么其实还是 n*k k=1 大家的gcd为1 -> 有互质数
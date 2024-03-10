#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXM = 5005;
const int INF = 1e9;

int n, m;
int a[MAXN], h[MAXN];
int dp[MAXM];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> h[i];
    }
    fill(dp + 1, dp + m + 1, INF);
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= a[i]; k++) {
            for (int j = m; j >= h[i]; j--) {
                dp[j] = min(dp[j], dp[j - h[i]] + h[i] - min(h[i], m - j + h[i]));
            }
        }
    }
    if (dp[m] < INF) {
        cout << "op" << endl;
    } else {
        cout << dp[m] << endl;
    }
    return 0;
}
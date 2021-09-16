#include<iostream>
using namespace std;

const int N = 105;
int a[N][N];
int dp[N][N];

int q, r, c;

int main() {
    cin >> q;
    while (q--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
            }
        }
        cout << dp[r][c] << endl;
    }

    return 0;
}

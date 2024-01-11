#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int len = 2; len < n; len++){
        for(int row = 0, col = len; col < n; row++, col++){
            dp[row][col] = INT_MAX;
            for(int k = row + 1; k < col; k++){
                dp[row][col] = min(dp[row][col], 
                dp[row][k] + dp[k][col] + a[row] * a[k] * a[col]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}
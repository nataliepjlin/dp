#include <iostream>
#include <climits>
using namespace std;
int minCoins(const int n, int a[], const int asize, int dp[]){
    if(!n) return 0;
    int mn = INT_MAX, nowmn;
    for(int i = 0; i < asize; i++){
        if(n - a[i] >= 0){
            nowmn = (dp[n - a[i]] != -1) ? dp[n - a[i]] : minCoins(n - a[i], a, asize, dp);
            if(mn > nowmn + 1) mn = nowmn + 1;
        }
    }
    return dp[n] = mn;
}
int main(){
    int n = 18, asize = 3;
    int dp[n + 1], a[asize] = {7, 5, 1};
    fill_n(dp, n + 1, -1); dp[0] = 0;
    int mn = minCoins(n, a, asize, dp);
    cout << mn << endl;
    for(int i = 0; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;
}
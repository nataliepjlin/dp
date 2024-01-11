#include <iostream>
#include <cstring>
#include <algorithm>
#define N 1001
using namespace std;
int lps(string &s1, string &s2, int n1, int n2, int dp[N][N]){
    if(!n1 || !n2)
        return 0;
    if(dp[n1][n2] != -1)
        return dp[n1][n2];
    if(s1[n1 - 1] == s2[n2 - 1])
        return dp[n1][n2] = 1 + lps(s1, s2, n1 - 1, n2 - 1, dp);
    else 
        return dp[n1][n2] = max(lps(s1, s2, n1 - 1, n2, dp), lps(s1, s2, n1, n2 - 1, dp));
}
int main(){
    string s1, s2;
    cin >> s1;
    int n = s1.length();
    s2 = s1;
    reverse(s2.begin(), s2.end());
    #ifdef debug
    cout << s1 << ", " << s2 << endl;
    #endif
    int dp[N][N];
    memset(dp, -1, sizeof(dp));
    cout << lps(s1, s2, n, n, dp) << endl;
}
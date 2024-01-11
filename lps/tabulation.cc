#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s1;
    cin >> s1;
    int n = s1.length();
    string s2 = s1; reverse(s2.begin(), s2.end());
    #ifdef debug
    cout << s1 << ", " << s2 << endl;
    #endif
    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++) dp[i][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
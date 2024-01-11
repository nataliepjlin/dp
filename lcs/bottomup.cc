#include <iostream>
using namespace std;
#define LEN 1001
int main(){
    int dp[LEN][LEN] = {{0}};
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length(), l2 = s2.length();
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    #ifdef debug
    cout << "   ";
    for(int i = 0; i < l2; i++) cout << " " << s2[i];
    cout << endl;
    for(int i = 0; i <= l1; i++){
        if(i) cout << s1[i - 1]; else cout << " ";
        for(int j = 0; j <= l2; j++){
            cout << " " << dp[i][j];
        }
        cout << endl;
    }
    string ans = "";
    int r = l1, c = l2;
    while(r && c){
        if(dp[r][c] == 1 + dp[r - 1][c - 1]
        && dp[r - 1][c] != dp[r][c] && dp[r][c - 1] != dp[r][c]){
            ans = s1[r - 1] + ans;
            r--, c--;
        }
        else if(dp[r][c] == dp[r - 1][c]) r--;
        else c--;
    }
    cout << "ans = " << ans << endl;
    #endif
    cout << dp[l1][l2] << endl;
}
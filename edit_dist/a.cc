#include <iostream>
using namespace std;
#define N 1001
void printdp(int dp[N][N], int l1, int l2){
    for(int i = 0; i <= l2; i++){
        for(int j = 0; j <= l1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    int dp[N][N];
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length(), l2 = s2.length();
    for(int i = 0; i <= l1; i++) dp[0][i] = i;
    for(int i = 1; i <= l2; i++) dp[i][0] = i;
    // printdp(dp, l1, l2);
    for(int i = 1; i <= l2; i++){
        for(int j = 1; j <= l1; j++){
            if(s2[i - 1] == s1[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
            }
        }
    }
    // printdp(dp, l1, l2);
    cout << dp[l2][l1] << endl;
}
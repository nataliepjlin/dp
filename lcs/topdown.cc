#include <iostream>
using namespace std;
#define N 10
#define M 10
int lcs(string str1, string str2, int l1, int l2, int dp[M][N]){
    if(!l1 || !l2)
        return 0;
    if(dp[l1][l2] != -1)
        return dp[l1][l2];
    if(str1[l1 - 1] == str2[l2 - 1])
        return dp[l1][l2] = 1 + lcs(str1, str2, l1 - 1, l2 - 1, dp);
    else return dp[l1][l2] = max(lcs(str1, str2, l1 - 1, l2, dp), lcs(str1, str2, l1, l2 - 1, dp));
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int l1 = str1.length(), l2 = str2.length();
    int dp[M][N]; 
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++)
            dp[i][j] = -1;
    }
    cout << lcs(str1, str2, l1, l2, dp) << endl;
    return 0;
}
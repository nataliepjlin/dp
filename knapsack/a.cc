#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int w = 10, wt[] = {1, 3, 4, 6};
    int n = 4, val[] = {20, 30, 10, 50};
    
    int dp[n + 1][w + 1];
    for(int r = 0; r < n + 1; r++)
        dp[r][0] = 0;
    for(int c = 0; c < w + 1; c++)
        dp[0][c] = 0;

    for(int item = 1; item <= n; item++){
        for(int cap = 1; cap <= w; cap++){
            int maxWithoutCur = dp[item - 1][cap];//here `item - 1` stands for how many items are stored
            int maxWithCur = 0;//init

            int nowWt = wt[item - 1];//wt of current item, minus 1 since there is an extra row for 0
            if(cap >= nowWt){
                maxWithCur = val[item - 1];
                int remainCap = cap - nowWt;
                maxWithCur += dp[item - 1][remainCap];
            }
            dp[item][cap] = max(maxWithoutCur, maxWithCur);
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            cout << setw(2) << dp[i][j] << " ";
        }
        cout << endl;
    }
}
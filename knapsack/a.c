#include <stdio.h>
#define N 21
#define W 10001
int max(const int a, const int b){
    return a * (a > b) + b * (a <= b);
}
int main(){
    int n, val[N], wt[N], maxw;
    scanf("%d%d", &n, &maxw);
    for(int i = 0; i < n; i++)
        scanf("%d%d", &wt[i], &val[i]);

    int dp[N][W] = {{0}};
    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= maxw; w++){
            int no = dp[i - 1][w], yes = 0;
            if(wt[i - 1] <= w){
                int remain = w - wt[i - 1];
                yes = val[i - 1] + dp[i - 1][remain];
            }
            dp[i][w] = max(no, yes);
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int w = 0; w <= maxw; w++){
    //         printf("%2d%c", dp[i][w], " \n"[w == maxw]);
    //     }
    // }
    printf("%d\n", dp[n][maxw]);
}
#include <iostream>
using namespace std;
int main(){
    int row, col;
    cin >> row >> col;
    int a[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> a[i][j];
        }
    }
    int maxsum = 0, f = 1, cursum = 0;
    for(int oc = 0; oc < col; oc++){
        int k[row] = {0};
        for(int c = oc; c < col; c++){
            cursum = 0;
            for(int r = 0; r < row; r++){
                k[r] += a[r][c];
                cursum += k[r];
                if(f || maxsum < cursum){
                    f = 0, maxsum = cursum;
                }
                #ifdef debug
                cout << "maxsum = " << maxsum << ", cursum = " << cursum << endl;
                #endif
                cursum = max(0, cursum);
            }
            #ifdef debug
            for(int r = 0; r < row; r++)
                cout << k[r] << endl;
            cout << endl;
            #endif
        }
        #ifdef debug
        cout << "###########" << endl;
        #endif
    }
    cout << maxsum << endl;
}
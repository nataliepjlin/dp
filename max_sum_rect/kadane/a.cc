#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int maxsum = 0, cursum = 0, f = 1;
    for(int i = 0; i < n; i++){
        cursum += a[i];
        if(f || maxsum < cursum){
            f = 0;
            maxsum = cursum;
        }
        #ifdef debug
        cout << "maxsum = " << maxsum << ", cursum = " << cursum << endl;
        #endif
        cursum = max(0, cursum);
    }
    cout << maxsum << endl;
}
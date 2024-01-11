#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int maxsum = 0, cursum = 0;
    for(int i = 0; i < n; i++){
        cursum += a[i];
        maxsum = max(maxsum, cursum);
        #ifdef debug
        cout << "maxsum = " << maxsum << ", cursum = " << cursum << endl;
        #endif
        cursum = max(0, cursum);
    }
    cout << maxsum << endl;
}
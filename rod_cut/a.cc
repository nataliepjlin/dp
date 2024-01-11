#include <iostream>
using namespace std;
#define N 101
int main(){
    int price[N], value[N], n; 
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> price[i];
    value[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            value[i] = max(value[i], price[j - 1] + value[i - j]);
        }
        cout << value[i] << " ";
    }
    cout << endl;
}